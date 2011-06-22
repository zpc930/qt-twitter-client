#ifndef APIPROVIDER_H
#define APIPROVIDER_H

using namespace std;

#include <list>
#include <api/ApiGlobal.h>
#include <oauth/OauthHelper.h>
#include <api/Status.h>
#include <api/Comment.h>
#include <api/User.h>

class MiniBlogProvider
{
protected:
    class OauthHelper * oauth;
public:
    /*Statuses*/
    virtual list<Status*> getFriendsTimeline(void) = 0;
    virtual list<Status*> getUserTimeline(int userId, int count = 20, int page = 1) = 0;
    virtual list<Status*> getMentions(int count = 20, int page = 1) = 0;
    virtual int updateStatus(Status& status) = 0;

    /* comments */
    virtual list<Comment*> getCommentByStatus(QString statusId, int count = 20, int page = 1) = 0;
    virtual int updateComment(Comment& comment) = 0;
    virtual list<Comment*> getCommentsTimeline(int count = 20, int page = 1) = 0;

    /*Users*/
    virtual User* getUser(int id) = 0;
    virtual list<User*> getHotUser(enum User_Category_Key category_Key)=0;
    virtual list<User*> getSuggestionsUser(bool with_reason)=0;

    /*oauth*/
    int OauthStep1(string * url);
    int OauthStep2(string pin);
    void RevertLoginStatus(string AccessToken, string AccessSecret, string Verifier, string UserId);
    int ExportLoginData(string * AccessToken, string * AccessSecret, string * Verifier, string * UserId);
};

#endif // APIPROVIDER_H
