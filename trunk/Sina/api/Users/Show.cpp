#include <api/sina/SinaApiProvider.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>

#define FAMILY_NAME "users"
#define PARA_NAME_USER_ID "user_id"

using namespace std;

User* SinaApiProvider::getUser(int userId)
{
    SinaUser* user = new SinaUser();
    Response response;
    PostParameter para;
    string queryUrl;
    QList<PostParameter*> paras;
    
    /* add parameter: user id */
    paras.append(new PostParameter(PARA_NAME_USER_ID, userId));

    SinaApi *api = new SinaApi(FAMILY_NAME, "show", HTTP_METHOD_GET);
    queryUrl = api->toString(paras);

#if API_PROVIDER_DEBUG
    cout << "query url:" <<queryUrl<<endl;
#endif

    this->oauth->Request(queryUrl, HTTP_METHOD_GET, &response);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif

    if (response.responseAsDocument()->elementsByTagName(NODE_USER_ROOT).count() != 0) {
        user->loadFromXml(response.responseAsDocument()->elementsByTagName(NODE_USER_ROOT).at(0));
    }
    para.releaseParas(paras);
    return user;
}

