#include <string>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApiProvider.h>

using namespace std;

SinaApiProvider::SinaApiProvider(OauthHelper *helper)
{
    this->oauth = helper;
}
