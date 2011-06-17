#ifndef OAUTHHELPER_H
#define OAUTHHELPER_H

#include <string>
#include <http/Response.h>

enum OAUTH_STATUS
{
    OAUTH_NEED_REQUEST,
    OAUTH_NEED_ACCESS,
    OAUTH_ACCESSED,
};

enum HTTP_METHOD
{
    HTTP_METHOD_GET,
    HTTP_METHOD_POST,
    HTTP_METHOD_MAX,
};

#define OAUTH_DEBUG 1

#define OK 0
#define FAIL 1


using namespace std;

class OauthHelper
{
private:
    string ServerUrl;
    string RequestUrl;
    string AuthUrl;
    string AccessUrl;

    string C_Key;
    string C_Secret;

    /*get from server*/
    string r_key;
    string r_Secret;
    string Verifier;
    string UserId;

    int LoginStatus;
    /*default*/
    int OauthMethod;
    int HttpMethod;
public:
    OauthHelper(string ServerUrl, string RequestTokenUrl, string AuthUrl, string AccessTokenUrl, string ConsumerKey, string ConsumerSecret);
    int LoginStep1(string * url);
    int LoginStep2(string pin);
    void RevertLoginStatus(string AccessToken, string AccessSecret, string Verifier, string UserId);
    int ExportLoginData(string * AccessToken, string * AccessSecret, string * Verifier, string * UserId);
    int Request(string RequestUrl, int httpMethod, string * result);
    int Request(string RequestUrl, int httpMethod, Response* response);
};

#endif //OAUTHHELPER_H
