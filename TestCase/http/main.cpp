#include <HttpClient.h>
#include <Response.h>
#include <PostParameter.h>
#include <QtCore/QList>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    HttpClient http;
    cout<<"10"<<endl;
    http.setHost("api.t.sina.com.cn");
    cout<<"11"<<endl;
    QList<PostParameter*> paras;
    cout<<"12"<<endl;
    Response *response = http.httpRequest("/statuses/friends_timeline.xml", paras, true);
    cout<<"13"<<endl;
    cout<<response->responseAsString();
    return 0;
}
