#ifndef SINAAPIPROVIDER_H
#define SINAAPIPROVIDER_H

#include <api/ApiProvider.h>
#include <api/sina/SinaParam.h>


#define SINA_WEIBO_URL "http://api.t.sina.com.cn"

#define SINA_DEFAULT_APP_KEY "3270683373"
#define SINA_DEFAULT_APP_SECRET "74eeee59407de92f1e6394157f090a36"

using namespace std;

class SinaApiProvider : public  MiniBlogProvider
{
private:
    list<Status> __getFriendsTimeline(int feature_code, long long since_id, long long max_id, int count, int page, bool base_app, int feature);
public:
    SinaApiProvider(void);
    /*Statuses*/
    list<Status> getFriendsTimeline(void); /*override*/
    list<Status> getFriendsTimeline(int count);
    list<Status> getFriendsTimeline(int count,int page);

    /*Users*/
    User getUser(int id);
};

#endif // SINAAPIPROVIDER_H
