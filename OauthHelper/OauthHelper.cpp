#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern "C"
{
#include <oauth.h>
}
#include <oauth/OauthHelper.h>
#include <iostream>

string http_method_string[] = {"GET", "POST"};

OauthHelper::OauthHelper(string ServerUrl, string RequestTokenUrl, string AuthUrl, string AccessTokenUrl, string ConsumerKey, string ConsumerSecret)
{
    this->ServerUrl = ServerUrl;
    this->RequestUrl = ServerUrl + RequestTokenUrl;
    this->AuthUrl = ServerUrl + AuthUrl;
    this->AccessUrl = ServerUrl + AccessTokenUrl;
    this->C_Key = ConsumerKey;
    this->C_Secret = ConsumerSecret;

    this->LoginStatus = OAUTH_NEED_REQUEST;
    this->OauthMethod = OA_HMAC;
}

void OauthHelper::RevertLoginStatus(string AccessToken, string AccessSecret, string Verifier, string UserId)
{
    this->r_key = AccessToken;
    this->r_Secret = AccessSecret;
    this->Verifier = Verifier;
    this->UserId = UserId;
    this->LoginStatus = OAUTH_ACCESSED;
}

/*Oauth认证第一步，生成request token和request secret*/
int OauthHelper::LoginStep1(string *url)
{
    int ret = OK;
    char * request_url, * reply;
    request_url = oauth_sign_url2(this->RequestUrl.c_str(), NULL, (OAuthMethod)this->OauthMethod, NULL, this->C_Key.c_str() , this->C_Secret.c_str(), NULL, NULL);
#if OAUTH_DEBUG
    cout << "Request URL : " << request_url << endl;
#endif
    reply = oauth_http_get(request_url,NULL);
    if (!reply)
            ret = FAIL;
    else
    {
        int rc;
        char **rv = NULL;
#if OAUTH_DEBUG
        cout << "HTTP-reply:" << reply << endl;
#endif
        rc = oauth_split_url_parameters(reply, &rv);
        qsort(rv, rc, sizeof(char *), oauth_cmpstringp);
        if( rc==2 && !strncmp(rv[0],"oauth_token=",11) && !strncmp(rv[1],"oauth_token_secret=",18))
        {
            this->r_key = &(rv[0][12]);
            this->r_Secret = &(rv[1][19]);
#if OAUTH_DEBUG
            cout << "request_key: '" << this->r_key << "'\nsecret: '" << this->r_Secret << "'\n" << endl;
#endif
        }
        else
        {
            ret = FAIL;
        }
        if(rv) free(rv);
    }
    if(request_url) free(request_url);
    if(reply) free(reply);


    if(OK == ret)
    {
        char c_url[512];
        snprintf(c_url, sizeof(c_url), "%s?oauth_token=%s):\n", this->AuthUrl.c_str(), this->r_key.c_str());
        *url = c_url;
        this->LoginStatus = OAUTH_NEED_ACCESS;
    }
    return ret;
}

/*Oauth第二步，根据输入的PIN码获取access token*/
int OauthHelper::LoginStep2(string pin)
{
    int ret = OK;
    char * request_url, * reply;

    /*状态机判断*/
    if(OAUTH_NEED_ACCESS != this->LoginStatus)
        return FAIL;

    this->Verifier = pin;
    this->AccessUrl += "?oauth_verifier=" + this->Verifier;
    request_url = oauth_sign_url2(this->AccessUrl.c_str(), NULL, (OAuthMethod)this->OauthMethod, NULL, this->C_Key.c_str() , this->C_Secret.c_str(), this->r_key.c_str(), this->r_Secret.c_str());
#if OAUTH_DEBUG
    cout << "Request URL : " << request_url << endl;
#endif
    reply = oauth_http_get(request_url,NULL);
    if (!reply)
            ret = FAIL;
    else
    {
        int rc;
        char **rv = NULL;
#if OAUTH_DEBUG
        cout << "HTTP-reply:" << reply << endl;
#endif
        rc = oauth_split_url_parameters(reply, &rv);
        qsort(rv, rc, sizeof(char *), oauth_cmpstringp);
        if( rc==3 && !strncmp(rv[0],"oauth_token=",11) && !strncmp(rv[1],"oauth_token_secret=",18) && !strncmp(rv[2], "user_id=",7))
        {
            this->r_key = &(rv[0][12]);
            this->r_Secret = &(rv[1][19]);
            this->UserId = &(rv[2][8]);
#if OAUTH_DEBUG
            cout << "access_key: '" << this->r_key << "'\nsecret: '" << this->r_Secret << "'\nuser id:" << this->UserId << endl;
#endif
        }
        else
        {
            ret = FAIL;
        }
        if(rv) free(rv);
    }
    if(request_url) free(request_url);
    if(reply) free(reply);


    if(OK == ret)
    {
        this->LoginStatus = OAUTH_ACCESSED;
    }
    else
    {
        this->LoginStatus = OAUTH_NEED_REQUEST;
    }
    return ret;
}

int OauthHelper::ExportLoginData(string *AccessToken, string *AccessSecret, string *Verifier, string *UserId)
{
    if(OAUTH_ACCESSED != this->LoginStatus)
        return FAIL;
    *AccessToken = this->r_key;
    *AccessSecret = this->r_Secret;
    *Verifier = this->Verifier;
    *UserId = this->UserId;
    return OK;
}

int OauthHelper::Request(string RequestUrl, int httpMethod, string *result)
{
    int ret = OK;
    char * request_url, * reply;
    string urlString;

    if(OAUTH_ACCESSED != this->LoginStatus  || httpMethod >= HTTP_METHOD_MAX)
        return FAIL;

    urlString = this->ServerUrl + RequestUrl + "?oauth_verifier=" + this->Verifier;
    request_url = oauth_sign_url2(urlString.c_str(), NULL, (OAuthMethod)this->OauthMethod, http_method_string[httpMethod].c_str(), this->C_Key.c_str() , this->C_Secret.c_str(), this->r_key.c_str(), this->r_Secret.c_str());
#if OAUTH_DEBUG
    cout << "Request URL : " << request_url << endl;
#endif
    reply = oauth_http_get(request_url,NULL);
    if (!reply)
            ret = FAIL;
    else
    {
#if OAUTH_DEBUG
        cout << "HTTP-reply:" << reply << endl;
#endif
        *result = reply;
    }
    if(request_url) free(request_url);
    if(reply) free(reply);
    return ret;
}

int OauthHelper::Request(string RequestUrl, int httpMethod, Response* response)
{
    int ret = OK;
    char * request_url, * reply;
    string urlString;

    if(OAUTH_ACCESSED != this->LoginStatus || httpMethod >= HTTP_METHOD_MAX)
        return FAIL;

    urlString = this->ServerUrl + RequestUrl + "?oauth_verifier=" + this->Verifier;
    request_url = oauth_sign_url2(urlString.c_str(), NULL, (OAuthMethod)this->OauthMethod, http_method_string[httpMethod].c_str(), this->C_Key.c_str() , this->C_Secret.c_str(), this->r_key.c_str(), this->r_Secret.c_str());
#if OAUTH_DEBUG
    cout << "Request URL : " << request_url << endl;
#endif
    reply = oauth_http_get(request_url,NULL);
    if (!reply)
            ret = FAIL;
    else
    {
#if OAUTH_DEBUG
        cout << "HTTP-reply:" << reply << endl;
#endif
        response->setResponseAsString(reply);
    }
    if(request_url) free(request_url);
    if(reply) free(reply);
    return ret;
}
