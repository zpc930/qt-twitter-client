#include <string>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApiProvider.h>

using namespace std;

SinaApiProvider::SinaApiProvider(OauthHelper *helper)
{
    this->oauth = helper;
}


int MiniBlogProvider::OauthStep1(string * url)
{
    return this->oauth->LoginStep1(url);
}

int MiniBlogProvider::OauthStep2(string pin)
{
    return this->oauth->LoginStep2(pin);
}
