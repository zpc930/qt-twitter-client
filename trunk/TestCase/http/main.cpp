#include <HttpClient.h>
#include <Response.h>
#include <PostParameter.h>
#include <BasicAuthorization.h>
#include <QtCore>
#include <QtCore/QList>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3) {
        cout<<"http <username> <password>"<<endl;
        return 0;
    }
    HttpClient http;
    QCoreApplication app(argc, argv);
    http.setHost("api.t.sina.com.cn");
    char authInfo[AUTH_INFO_LEN];
    BasicAuthorization::setAuthorization(argv[1], argv[2], authInfo);
    Response *response = http.httpRequest("/statuses/friends_timeline.xml?source=1596803225&page=0&count=100", authInfo);
    //cout<<response->responseAsString();
    cout<<response->responseAsDocument()->toString().toStdString()<<endl;
    return app.exec();
}
