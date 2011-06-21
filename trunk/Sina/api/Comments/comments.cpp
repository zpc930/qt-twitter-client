#include <QtXml/QDomDocument>
#include <api/sina/SinaApiProvider.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaComment.h>
#include <http/PostParameter.h>
#include <http/Response.h>

#define FAMILY_NAME "statuses"
#define PARA_NAME_PAGE "page"
#define PARA_NAME_ID "id"
#define PARA_NAME_COUNT "count"

list<Comment*> SinaApiProvider::getCommentByStatus(QString statusId, int count, int page)
{
    list<Comment*> lsComment;
    Response response;
    PostParameter para;
    string queryUrl;
    QList<PostParameter*> paras;
    SinaComment comment;
    
    /* add parameter: status id */
    paras.append(new PostParameter(PARA_NAME_ID, statusId.toStdString().c_str()));

    /* add parameter: page */
    paras.append(new PostParameter(PARA_NAME_PAGE, page));

    /* add parameter: count per page */
    if (count >= 0 && count <= 200) {
        paras.append(new PostParameter(PARA_NAME_COUNT, count));
    }

    SinaApi *api = new SinaApi(FAMILY_NAME, "comments", HTTP_METHOD_GET);
    queryUrl = api->toString(paras);

#if API_PROVIDER_DEBUG
    cout << "query url:" <<queryUrl<<endl;
#endif

    this->oauth->Request(queryUrl, HTTP_METHOD_GET, &response);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif

    if (response.responseAsDocument()->elementsByTagName(NODE_COMMENT_ROOT).count() != 0) {
        comment.loadListFromXml(*response.responseAsDocument(), lsComment);
    }
    para.releaseParas(paras);
    return lsComment;
}
