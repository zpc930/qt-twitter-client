#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oauth.h>
#include <oauth/OauthHelper.h>
#include <iostream>

#include <api/sina/SinaParam.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApiProvider.h>
#include <api/ApiGlobal.h>

using namespace std;

int main(int argc, char ** argv)
{
    int ret = 0;
    string url;
    string pin;
    class OauthHelper * oauth;
    class SinaApiProvider * sina;

    oauth = new OauthHelper(
                "http://api.t.sina.com.cn",
                "/oauth/request_token",
                "/oauth/authorize",
                "/oauth/access_token",
                "3270683373", "74eeee59407de92f1e6394157f090a36");

    sina = new SinaApiProvider(oauth);
    ret = oauth->LoginStep1(&url);
    cout << "LoginStep 1 result:" << ret << "\nUrl:" << url << endl;
    cout << "Please Enter Pin code :";
    getline(cin, pin);
    ret = oauth->LoginStep2(pin);
    cout << "LoginStep 2 result:" << ret << endl;

    list<Status*> lsStatus = sina->getFriendsTimeline();
    /*for (int i = 0; i < lsStatus.size(); ++i) {
        cout<<lsStatus[i]->getId()<<endl;
    }*/
    for (list<Status*>::iterator s = lsStatus.begin(); s != lsStatus.end(); s++) {
        cout<<(*s)->getId()<<"\t"<<(*s)->getText()<<endl;
    }
    return ret;
}
