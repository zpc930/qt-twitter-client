#include <iostream>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApiProvider.h>
#include <api/ApiGlobal.h>

using namespace std;

int main(int argc, char ** argv)
{
    class SinaApiProvider SAP;
    SAP.getFriendsTimeline();
    SAP.getFriendsTimeline(4);
    SAP.getFriendsTimeline(3,2);
}
