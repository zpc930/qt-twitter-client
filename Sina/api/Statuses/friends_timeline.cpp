#include <api/sina/SinaApiProvider.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <iostream>

#define FAMILY_NAME "statuses"

/* getFriendsTimeline
 * 获取当前登录用户及其所关注用户的最新微博消息
 * 必须参数：source
 * 可选参数：since_id, max_id, count, page, base_app, feature
 */
list<Status*> SinaApiProvider::__getFriendsTimeline(int feature_code, long long since_id, long long max_id, int count, int page, bool base_app, int feature)
{
    class SinaApi * api;
    class SinaParamServer * SPServer;
    int required = 0;
    int all = 0;
    string urlquery, result;
    Response response;
    int id;
    list<Status*> statuses;
    SinaStatus status;

    required = SINA_PARAM_SOURCE_B;
    all = SINA_PARAM_SOURCE_B | SINA_PARAM_SINCE_ID_B |
          SINA_PARAM_MAX_ID_B | SINA_PARAM_COUNT_B |
          SINA_PARAM_FEATURE_B | SINA_PARAM_PAGE_B |
          SINA_PARAM_BASE_APP_B ;

    api = new SinaApi(FAMILY_NAME, "friends_timeline", HTTP_METHOD_GET, required, all);

    SPServer = new SinaParamServer();

    id = 0;
    while(feature_code)
    {
        if(BITMAP_TEST(feature_code, id))
        {
            switch(id)
            {
                case SINA_PARAM_COUNT:
                    SPServer->setParamCount(api, count);
                    break;
                case SINA_PARAM_PAGE:
                    SPServer->setParamPage(api, page);
                    break;
                case SINA_PARAM_SINCE_ID:
                case SINA_PARAM_MAX_ID:
                case SINA_PARAM_FEATURE:
                case SINA_PARAM_BASE_APP:
                    break;
            }
            BITMAP_CLEAN(feature_code, id);
        }
        id++;
    }
    urlquery = api->toString(SPServer);
    /*to-be-continue*/
    this->oauth->Request(urlquery, HTTP_METHOD_GET, &response);
    //this->oauth->Request(urlquery, &result);
#if API_PROVIDER_DEBUG
    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif
    statuses.clear();
    if (response.responseAsDocument()->elementsByTagName(NODE_STATUS_ROOT).count() != 0) {
        status.loadListFromXml(*response.responseAsDocument(), statuses);
    }
    return statuses;
}

list<Status*> SinaApiProvider::getFriendsTimeline(void)
{
    int feature = 0;
    return __getFriendsTimeline(feature, 0,0,0,0,0,0);
}

list<Status*> SinaApiProvider::getFriendsTimeline(int count)
{
    int feature = SINA_PARAM_COUNT_B;
    return __getFriendsTimeline(feature, 0, 0, count, 0, 0, 0);
}

list<Status*> SinaApiProvider::getFriendsTimeline(int count, int page)
{
    int feature = SINA_PARAM_COUNT_B | SINA_PARAM_PAGE_B;
    return __getFriendsTimeline(feature, 0, 0, count, page, 0, 0);
}
