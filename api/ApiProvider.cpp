#include <string>
#include <api/ApiProvider.h>

using namespace std;

int MiniBlogProvider::OauthStep1(string * url)
{
    return this->oauth->LoginStep1(url);
}

int MiniBlogProvider::OauthStep2(string pin)
{
    return this->oauth->LoginStep2(pin);
}

void MiniBlogProvider::RevertLoginStatus(string AccessToken, string AccessSecret, string Verifier, string UserId)
{
    this->oauth->RevertLoginStatus(AccessToken, AccessSecret, Verifier, UserId);
}

int MiniBlogProvider::ExportLoginData(string * AccessToken, string * AccessSecret, string * Verifier, string * UserId)
{
    return this->oauth->ExportLoginData(AccessToken, AccessSecret, Verifier, UserId);
}
