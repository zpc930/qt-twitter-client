#include <string>
#include <sstream>
#include <ApiProvider/SinaParam.h>
#include <ApiProvider/SinaApi.h>

using namespace std;

SinaParamPage::SinaParamPage(int default_count)
{
    this->name = "page";
    this->default_value = default_count;
}
/*
 * page 最大值是1000
 */
bool SinaParamPage::checkValidity(int value)
{
    return ((value > 0 && value <= 1000) ? true: false);
}

string SinaParamPage::convertToString(int value)
{
    stringstream out;
    string Str(this->name);

    Str += "=";
    out << value;
    Str += out.str();
    return Str;
}

string SinaParamPage::defaultString(void)
{
    return this->convertToString(this->default_value);
}


/* SinaParamServer 类*/
void SinaParamServer::setParamPage(class SinaApi *api, int value)
{
    api->setUrlString(SINA_PARAM_PAGE, this->SPPage->convertToString(value));
}
