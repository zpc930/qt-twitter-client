#ifndef APIPROVIDER_H
#define APIPROVIDER_H

using namespace std;

#include <list>
#include <api/ApiGlobal.h>
#include <oauth/OauthHelper.h>
#include <api/Status.h>

/*tmp*/
class User
{
private:
    int Id;
    char name[16];

public:
    int getId();
    char * getName();
};

class MiniBlogProvider
{
protected:
    class OauthHelper * oauth;
public:
    /*Statuses*/
    virtual list<Status*> getFriendsTimeline(void) = 0;
    virtual int updateStatus(Status& status) = 0;

    /*Users*/
    virtual User getUser(int id) = 0;
};

#endif // APIPROVIDER_H
