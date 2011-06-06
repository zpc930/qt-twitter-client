#ifndef SINAAPIPROVIDER_H
#define SINAAPIPROVIDER_H

#include "SinaParam.h"
#include "apiprovider.h"

#define SINA_WEIBO_URL "api.t.sina.com.cn"

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
