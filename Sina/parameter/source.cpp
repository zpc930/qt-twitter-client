
#include <string>
#include <api/sina/SinaParam.h>

using namespace std;

#define SINA_PARAM_SOURCE_LEN 16

SinaParamSource::SinaParamSource(string appKey)
{
    this->name = "source";
    this->default_value = appKey;
}


string SinaParamSource::convertToString(string value)
{
    string Str(this->name);
    Str += "=" + value;
    return Str;
}

bool SinaParamSource::checkValidity(string value)
{
    /*无法进行app key的合法性检测*/
    (void)value;
    return true;
}

string SinaParamSource::defaultString(void)
{
    return this->convertToString(this->default_value);
}
