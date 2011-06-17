#include <QtXml/QDomDocument>
#include <api/sina/SinaStatus.h>
#include <api/sina/SinaApiProvider.h>
#include <http/PostParameter.h>
#include <http/Response.h>
#include <api/sina/SinaApi.h>

#define FAMILY_NAME "statuses"

int SinaApiProvider::updateStatus(Status& status)
{
    int ret = 0;
    SinaApi *api;
    QList<PostParameter*> paras;
    string queryUrl;
    Response response;
    // set status text parameter
    paras.append(new PostParameter("status", status.getText()));

    // set status reply parameter
    if (strcmp(status.getInReplyToStatusId(), "")) {
        paras.append(new PostParameter("in_reply_to_status_id", status.getInReplyToStatusId()));
    }
    api = new SinaApi(FAMILY_NAME, "update", HTTP_METHOD_POST);
    queryUrl = api->toString(paras);

    this->oauth->Request(queryUrl, HTTP_METHOD_POST, &response);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif

    // 如果返回结果中含有<status>标签，说明发不成功，否则失败
    if (response.responseAsDocument()->elementsByTagName("status").count() == 0) {
        ret = -1;
    }
    return ret;
}
