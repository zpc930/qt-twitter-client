#include <QtXml/QDomDocument>
#include <api/sina/SinaApiProvider.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaStatus.h>
#include <http/PostParameter.h>
#include <http/Response.h>

#define FAMILY_NAME "statuses"
#define PARA_NAME_USER_ID "user_id"
#define PARA_NAME_PAGE "page"
#define PARA_NAME_COUNT "count"

list<Status*> SinaApiProvider::getUserTimeline(int userId, int count, int page)
{
    list<Status*> lsStatus;
    Response response;
    PostParameter para;
    string queryUrl;
    QList<PostParameter*> paras;
    SinaStatus status;
    
    /* add parameter: user id */
    paras.append(new PostParameter(PARA_NAME_USER_ID, userId));

    /* add parameter: page */
    paras.append(new PostParameter(PARA_NAME_PAGE, page));

    /* add parameter: count per page */
    if (count >= 0 && count <= 200) {
        paras.append(new PostParameter(PARA_NAME_COUNT, count));
    }

    SinaApi *api = new SinaApi(FAMILY_NAME, "user_timeline", HTTP_METHOD_GET);
    queryUrl = api->toString(paras);

#if API_PROVIDER_DEBUG
    cout << "query url:" <<queryUrl<<endl;
#endif

    this->oauth->Request(queryUrl, HTTP_METHOD_GET, &response);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif

    if (response.responseAsDocument()->elementsByTagName(NODE_STATUS_ROOT).count() != 0) {
        status.loadListFromXml(*response.responseAsDocument(), lsStatus);
    }
    para.releaseParas(paras);
    return lsStatus;
}

