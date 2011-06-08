#ifndef APIPROVIDER_H
#define APIPROVIDER_H

using namespace std;

#include <list>
#include <api/ApiGlobal.h>

class ApiProvider {
public:
    ApiProvider();
};

/*tmp*/
class Status
{
private:
    int Id;
    char text[256];
public:
    int getId();
    char * getText();
};

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
public:
    /*Statuses*/
    virtual list<Status> getFriendsTimeline(void) = 0;

    /*Users*/
    virtual User getUser(int id) = 0;
};

#endif // APIPROVIDER_H
