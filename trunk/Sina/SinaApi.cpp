#include <string>
#include <api/ApiGlobal.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApiProvider.h>

SinaApi::SinaApi(string family, string name, int http_method, int required_param, int all_param)
{
    this->family = family;
    this->name = name;
    this->http_method = http_method;
    this->needed_param = this->required_param = required_param;
    this->all_param = all_param;
    this->query_string = "?";
}

SinaApi::SinaApi(string family, string name, int http_method)
{
    this->family =family;
    this->name = name;
    this->http_method = http_method;
    this->query_string = "?";
}

string SinaApi::toString(class SinaParamServer * SPServer)
{
    string Str;

    this->query_string += SPServer->getDefaultString(this->needed_param);
    /*只支持xml*/
    Str =  "/" +this->family + "/" + this->name + ".xml" + this->query_string;
    Str.erase(Str.end() - 1); /*删掉最后一个&*/
    return Str;
}

string SinaApi::toString(QList<PostParameter*> paras)
{
    string retValue;
    PostParameter para;
    char* paraStr = para.generatePostParameter(paras);
    this->query_string += paraStr;
    retValue = "/" +this->family + "/" + this->name + ".xml" + this->query_string;
    delete[] paraStr;
    return retValue;
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
