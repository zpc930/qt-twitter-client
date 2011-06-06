#include <string>
#include <ApiProvider/SinaParam.h>
#include <ApiProvider/SinaApi.h>
#include <ApiProvider/ApiProvider_global.h>

using namespace std;

SinaParamServer::SinaParamServer(void)
{
    this->SPSource = new SinaParamSource(SINA_DEFAULT_APP_KEY);
    this->SPCount = new SinaParamCount(20);
    this->SPPage = new SinaParamPage(1);
}

string SinaParamServer::getDefaultStringById(int id)
{
    switch(id)
    {
    case SINA_PARAM_SOURCE:
        return this->SPSource->defaultString();
    case SINA_PARAM_COUNT:
        return this->SPCount->defaultString();
    default:
        /*还未支持*/
        return "";
    }
}

/*
 * 生成所有默认参数
 */
string SinaParamServer::getDefaultString(int param_bitmap)
{
    int id;
    string Str;
    for(id = 0; id < SINA_PARAM_MAX; id++)
    {
        if(NUM_TO_BIT(id) & param_bitmap)
        {
            /*该参数需要默认值*/
            Str += this->getDefaultStringById(id) + "&";
        }
    }
    return Str;
}
