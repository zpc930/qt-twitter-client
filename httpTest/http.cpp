#include <QtNetwork/QHttp>
#include <QtNetwork/QHttpResponseHeader>
#include <iostream>
#include <http.h>
#include <QtCore/QEventLoop>

using namespace std;

MyHttp::MyHttp(char* host, char* url)
{
    loop = new QEventLoop(this);
    http = new QHttp(this);
    connect(http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)), 
            this, SLOT(showPage(const QHttpResponseHeader &)));
    connect(http, SIGNAL(requestStarted(int)),
            this, SLOT(requestStart(int)));
    connect(http, SIGNAL(done(bool)), 
            this, SLOT(httpDone(bool)));
    http->setHost(host);
    http->get(url);
    cout<<"call get"<<endl;
    loop->exec();
    cout<<http->readAll().constData()<<endl;
}

void MyHttp::requestStart(int id)
{
    cout<<"start to request: "<<id<<endl;
}

void MyHttp::httpDone(bool res)
{
    loop->exit();
    cout<<"the request is done: ";
    if (res)
    {
        cout<<"failed!"<<endl;
    }
    else
    {
        cout<<"successful!"<<endl;
    }
}

void MyHttp::showPage(const QHttpResponseHeader &header)
{
    cout<<"get response"<<endl;
    cout<<header.statusCode()<<endl;
    cout<<header.toString().toStdString();
}

int MyHttp::getStatus()
{
    return status;
}
