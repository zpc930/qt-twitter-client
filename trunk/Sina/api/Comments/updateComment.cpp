#include <api/sina/SinaComment.h>
#include <api/sina/SinaApiProvider.h>
#include <http/PostParameter.h>
#include <http/Response.h>
#include <api/sina/SinaApi.h>

#define FAMILY_NAME "statuses"
#define PARA_NAME_COMMENT "comment"
#define PARA_NAME_SID "id"
#define PARA_NAME_CID "cid"
#define PARA_NAME_NO_MENTION "without_mention"
#define PARA_NAME_COMMENT_ORI "comment_ori"

int SinaApiProvider::updateComment(Comment& comment)
{
    int ret = 0;
    string queryUrl;
    QList<PostParameter*> paras;
    Response response;
    PostParameter para;

    /* add parameter: text */
    paras.append(new PostParameter(PARA_NAME_COMMENT, comment.getText().toStdString().c_str()));

    /* add parameter: status id to reply */
    paras.append(new PostParameter(PARA_NAME_SID, comment.getReplyStatusId().toStdString().c_str()));

    /* add parameter: comment id to reply */
    paras.append(new PostParameter(PARA_NAME_CID, comment.getReplyCommentId().toStdString().c_str()));

    /* add parameter: without_metion */
    if (comment.getNoMention()) {
        paras.append(new PostParameter(PARA_NAME_NO_MENTION, comment.getNoMention()));
    }

    /* add parameter: comment original */
    if (comment.getCommentOri()) {
        paras.append(new PostParameter(PARA_NAME_COMMENT_ORI, comment.getCommentOri()));
    }
    SinaApi *api = new SinaApi(FAMILY_NAME, "comment", HTTP_METHOD_POST);
    queryUrl = api->toString(paras);
    
#if API_PROVIDER_DEBUG
    cout << "query url:" <<queryUrl<<endl;
#endif

    this->oauth->Request(queryUrl, HTTP_METHOD_POST, &response);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif
    
    if (response.responseAsDocument()->elementsByTagName(NODE_COMMENT_ROOT).count() == 0) {
        ret = -1;
    }
    return ret;
}

