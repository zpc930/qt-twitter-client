#include <iostream>
#include "../ApiProvider/include/ApiProvider/SinaParam.h"
#include "../ApiProvider/include/ApiProvider/SinaApi.h"
#include "../ApiProvider/include/ApiProvider/SinaParam.h"
#include "../ApiProvider/include/ApiProvider/SinaApiProvider.h"
#include "../ApiProvider/include/ApiProvider/ApiProvider_global.h"

using namespace std;

int main(int argc, char ** argv)
{
    class SinaApiProvider SAP;
    SAP.getFriendsTimeline();
    SAP.getFriendsTimeline(4);
    SAP.getFriendsTimeline(3,2);
}
