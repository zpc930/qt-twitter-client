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
    virtual int updateStatus(Status& status) = 0;

    /* comments */
    virtual list<Comment*> getCommentByStatus(QString statusId, int count = 20, int page = 1) = 0;
    virtual int updateComment(Comment& comment) = 0;

    /*Users*/
    virtual User getUser(int id) = 0;

    /*oauth*/
    int OauthStep1(string * url);
    int OauthStep2(string pin);
};

#endif // APIPROVIDER_H
