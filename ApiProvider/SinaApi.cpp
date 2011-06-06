#include <string>
#include <ApiProvider/SinaApi.h>
#include <ApiProvider/SinaParam.h>
#include <ApiProvider/SinaApiProvider.h>
#include <ApiProvider/ApiProvider_global.h>

SinaApi::SinaApi(string family, string name, int required_param, int all_param)
{
    this->family = family;
    this->name = name;
    this->needed_param = this->required_param = required_param;
    this->all_param = all_param;
    this->query_string = "?";
}

string SinaApi::toString(class SinaParamServer * SPServer, string targetUrl)
{
    string Str;

    this->query_string += SPServer->getDefaultString(this->needed_param);
    /*只支持xml*/
    Str =  targetUrl + "/" + this->family + "/" + this->name + ".xml" + this->query_string;
    Str.erase(Str.end() - 1); /*删掉最后一个&*/
#ifdef API_PROVIDER_DEBUG
    cout << Str << endl;
#endif
    return Str;
}

void SinaApi::setUrlString(int param_id, string param_string)
{
    if(BITMAP_TEST(this->all_param, param_id))
    {
        /*参数合法*/
        this->query_string += param_string + "&";
        BITMAP_CLEAN(this->needed_param, param_id);
    }
    return ;
}
