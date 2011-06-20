#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oauth.h>
#include <oauth/OauthHelper.h>
#include <iostream>
#include <fstream>

#include <api/sina/SinaParam.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <api/ApiProvider.h>
#include <api/ApiGlobal.h>
#include <factory/ManagerFactory.h>

using namespace std;

int main(int argc, char ** argv)
{
    int ret = 0;
    string url;
    string pin;
    class MiniBlogProvider * provider;
    string AccessToken, AccessSecret, Verifier, UserId;

    provider = ManagerFactory::getInstance()->getProvider(PROVIDER_SINA);

    if (argc != 5) {
        ret = provider->OauthStep1(&url);
        cout << "LoginStep 1 result:" << ret << "\nUrl:" << url << endl;
        cout << "Please Enter Pin code :";
        getline(cin, pin);
        ret = provider->OauthStep2(pin);
        cout << "LoginStep 2 result:" << ret << endl;
    }
    else {
        AccessToken = argv[1];
        AccessSecret = argv[2];
        Verifier = argv[3];
        UserId = argv[4];
        provider->RevertLoginStatus(AccessToken, AccessSecret, Verifier, UserId);
    }
    list<Status*> lsStatus = provider->getFriendsTimeline();

    for (list<Status*>::iterator s = lsStatus.begin(); s != lsStatus.end(); s++) {
        cout<<(*s)->getUser()->getId().toStdString()<<"\t"<<(*s)->getId()<<"\t"<<(*s)->getText()<<endl;
    }
    provider->ExportLoginData(&AccessToken, &AccessSecret, &Verifier, &UserId);
    cout<<AccessToken<<" "<<AccessSecret<<" "<<Verifier<<" "<<UserId<<endl;
    return ret;
}
