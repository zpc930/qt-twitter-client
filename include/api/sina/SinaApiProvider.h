#ifndef SINAAPIPROVIDER_H
#define SINAAPIPROVIDER_H

#include <api/ApiProvider.h>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaStatus.h>
#include <api/sina/SinaUser.h>
#include <api/User.h>

#define SINA_WEIBO_URL "http://api.t.sina.com.cn"

#define SINA_DEFAULT_APP_KEY "1596803225"
#define SINA_DEFAULT_APP_SECRET "7bc29cb2aa9c02958cae028d26f83902"

using namespace std;

class SinaApiProvider : public  MiniBlogProvider
{
private:
    list<Status*> __getFriendsTimeline(int feature_code, long long since_id, long long max_id, int count, int page, bool base_app, int feature);
public:
    SinaApiProvider(OauthHelper * helper);
    /*Statuses*/
    list<Status*> getFriendsTimeline(void); /*override*/
    list<Status*> getFriendsTimeline(int count);
    list<Status*> getFriendsTimeline(int count,int page);
    list<Status*> getUserTimeline(int userId, int count = 20, int page = 1);
    list<Status*> getMentions(int count = 20, int page = 1);

    /* publish a status */
    int updateStatus(Status& status);

    /* Comments */
    list<Comment*> getCommentByStatus(QString statusId, int count = 20, int page = 1);
    int updateComment(Comment& comment);
    list<Comment*> getCommentsTimeline(int count = 20, int page = 1);
    
    /*Users*/
    User* getUser(int id);
    list<User*> getHotUser(enum User_Category_Key category_Key);
    list<User*> getSuggestionsUser(bool with_reason);
};

#endif // SINAAPIPROVIDER_H
