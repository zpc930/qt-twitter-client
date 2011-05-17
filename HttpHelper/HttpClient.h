/*
* a class to process HTTP request/response
* Author: 吕进
**/

#ifndef __HTTP_CLIENT_H__
#define __HTTP_CLIENT_H__

#include <QtNetwork/QHttp>
#include <QtNetwork/QHttpResponseHeader>
#include <QtNetwork/QHttpRequestHeader>
#include <QtCore/QEventLoop>
#include "Response.h"
#include "PostParameter.h"

#define HOST_NAME_LEN 256
#define HTTP_METHOD_GET "GET"
#define HTTP_METHOD_POST "POST"
#define HTTP_METHOD_DELETE "DELETE"
#define HTTP_STATUS_SUCCESS 200

class HttpClient: public QObject
{
    Q_OBJECT
public:
    HttpClient();
    HttpClient(char* host);
    char* getHost() const;
    void setHost(char* host);
    Response* httpRequest(char* url, PostParameter* postParams, int count, bool authenticated, char* httpMethod);
    Response* httpRequest(char* url, bool authenticated);
public slots:
    void responseReceived(const QHttpResponseHeader &);
    void httpDone(bool);
signals:
    void finished(char *);
private:
    char* host;
    QHttp* http;
    QEventLoop* loop;
    int status;
};

#endif

