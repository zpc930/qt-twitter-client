#ifndef SINAAPI_H
#define SINAAPI_H

#include <string>
#include <api/ApiGlobal.h>

using namespace std;

class SinaApi
{
private:
    string family;
    string name;
    int http_method;
    int required_param;     /*该api必须的参数位图*/
    int all_param;          /*该api允许的参数位图*/
    int needed_param;       /*需要获取默认值的必须参数*/
    string query_string;
public:
    void setUrlString(int param_id, string param_string);

    SinaApi(string family, string name, int http_method, int feature_code, int all_param);
    string toString(class SinaParamServer * SPServer);
};

#endif // SINAAPI_H
