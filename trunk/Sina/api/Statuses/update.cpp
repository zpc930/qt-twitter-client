#include <api/sina/SinaApiProvider.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <http/PostParameter.h>
#include <iostream>

#define FAMILY_NAME "statuses"

int SinaApiProvider::update(string text)
{
    class SinaApi * api;
    class SinaParamServer * SPServer;
    int required = 0;
    int all = 0;
    string urlquery;
    Response response;
    QList<PostParameter *> list;
    list.clear();
    list.append(new PostParameter("status", text.c_str()));

    required = SINA_PARAM_SOURCE_B;
    all = SINA_PARAM_SOURCE_B;

    api = new SinaApi(FAMILY_NAME, "update", HTTP_METHOD_POST, required, all);

    SPServer = new SinaParamServer();
    urlquery = api->toString(SPServer) + "&status=" + text;
    this->oauth->Request(urlquery, HTTP_METHOD_POST, &response);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif
    return 0;
}

