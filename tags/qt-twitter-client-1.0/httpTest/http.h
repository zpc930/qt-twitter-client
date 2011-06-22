#include <QtNetwork/QHttp>
#include <QtNetwork/QHttpResponseHeader>
#include <iostream>
#include <QtCore/QEventLoop>
using namespace std;
class MyHttp: public QObject
{
    Q_OBJECT
public:
    MyHttp(char* host = 0, char* url = 0);
    int getStatus();
public slots:
    void showPage(const QHttpResponseHeader &);
    void requestStart(int);
    void httpDone(bool);
signals:
    void finish(QString);
private:
    QHttp *http;
    QEventLoop *loop;
    int status;
};

