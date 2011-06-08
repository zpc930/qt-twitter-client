#include <string>
#include <sstream>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApi.h>

using namespace std;

SinaParamCount::SinaParamCount(int default_count)
{
    this->name = "count";
    this->default_value = default_count;
}
/*
 * count 最大值是200
 */
bool SinaParamCount::checkValidity(int value)
{
    return ((value > 0 && value <= 200) ? true: false);
}

string SinaParamCount::convertToString(int value)
{
    stringstream out;
    string Str(this->name);

    Str += "=";
    out << value;
    Str += out.str();
    return Str;
}

string SinaParamCount::defaultString(void)
{
    return this->convertToString(this->default_value);
}


/* SinaParamServer 类*/
void SinaParamServer::setParamCount(class SinaApi *api, int value)
{
    api->setUrlString(SINA_PARAM_COUNT, this->SPCount->convertToString(value));
}
