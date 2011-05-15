/*
* a class to process HTTP request/response
* Author: 吕进
**/

#include <QtNetwork/QHttp>
#include <QtNetwork/QHttpResponse>
#include <QtNetwork/QHttpRequest>

class httpClient: public QObject
{
    Q_OBJECT
public:
    httpClient();
    httpClient(char* host);
    response request();
    char* getResponseString() const;
public slots:
    void responseReceived(const QHttpResponseHeader &);
    void httpDone(bool);
signals:
    void finished(char *);
pvivate:
    char* host;
    QEventLoop *loop;
    char* responseString;
    int status;
};
