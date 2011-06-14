/*
* 功能：定义了Http协议的相关属性和方法
* 作者：吕进
*/

#include <iostream>
#include <QtNetwork/QHttp>
#include <QtNetwork/QHttpResponseHeader>
#include <QtNetwork/QHttpRequestHeader>
#include <QtCore/QEventLoop>
#include <http/HttpClient.h>
#include <http/Response.h>

using namespace std;

/*
 * 默认参数构造函数
 */
HttpClient::HttpClient()
{
    this->host = NULL;
    this->loop = new QEventLoop(this);
    this->http = new QHttp(this);
    status = 0;
}

/*
 * 带参数的构造函数
 * host : 请求的服务器地址
 */
HttpClient::HttpClient(char* host)
{
    this->setHost(host);
    this->loop = new QEventLoop(this);
    this->http = new QHttp(this);
    status = 0;
}

/*
 * 发送http请求，获取response
 * url           : 请求的url
 * postParams    : post方法的所有参数
 * authInfo      : 验证信息字符串，为NULL表示不需要验证
 * httpMethod    : 请求方法：GET or POST or DELETE
 * 返回服务器的response
 */
Response* HttpClient::httpRequest(char* url, QList<PostParameter*>& postParams, char* authInfo, char* httpMethod)
{
    Response* response = new Response();
    QHttpRequestHeader header;
    
    // 判断是否需要身份验证
    if (authInfo != NULL) {
        header.setValue("Authorization", authInfo);
    }

    // 注册收到response header的事件响应
    connect(this->http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader&)),
            this, SLOT(responseReceived(const QHttpResponseHeader &)));

    // 注册请求结束的事件响应
    connect(this->http, SIGNAL(done(bool)),
            this, SLOT(httpDone(bool)));
    
    // 如果host不为空，根据method发送请求
    if (this->host != NULL) {
        http->setHost(this->host);
        if (httpMethod == HTTP_METHOD_POST) {
            // 生成post参数列表并发送post请求
            header.setRequest(HTTP_METHOD_POST, url);
            QString paras = PostParameter::generatePostParameter(postParams);
            http->request(header, paras.toUtf8());
        }
        else if (httpMethod == HTTP_METHOD_GET) {
            // 发送get请求
            header.setRequest(HTTP_METHOD_GET, url);
            http->request(header);
        }
        else if (httpMethod == HTTP_METHOD_DELETE) {
            // 发送delete请求
            header.setRequest(HTTP_METHOD_DELETE, url);
            http->request(header);
        }

        // 请求发送完后，进入循环等待
        loop->exec();

        // 循环结束，如果请求成功，为response赋值
        cout<<"http status:"<<status<<endl;
        if (status == HTTP_STATUS_SUCCESS) {
            response->setResponseAsString(http->readAll().constData());
        }
    }
    response->setStatusCode(this->status);
    
    return response;
}

/*
 * 发送http请求，获取response
 * url           : 请求的url
 * authInfo      : 身份验证信息，为NULL表示不需要身份验证
 * 返回服务器的response
 */
Response* HttpClient::httpRequest(char* url, char* authInfo)
{
    QList<PostParameter*> paras;
    return this->httpRequest(url, paras, authInfo, HTTP_METHOD_GET);
}
/*
 * 获取服务器的地址Host
 * 返回服务器的地址host
 */
char* HttpClient::getHost() const
{
    return this->host;
}

/*
 * 设置服务器的地址Host
 * host : 服务器的地址Host
 */
void HttpClient::setHost(char* host)
{
    if (this->host != NULL) {
        delete[] this->host;
    }
    this->host = new char[HOST_NAME_LEN + 1];
    strncpy(this->host, host, HOST_NAME_LEN);
    this->host[HOST_NAME_LEN] = '\0';
}

/*
 * 收到服务器response头的事件响应
 * header : respones头
 */
void HttpClient::responseReceived(const QHttpResponseHeader& header)
{
    this->status = header.statusCode();
}

/*
 * http请求完成的事件响应
 * error : 请求是否错误
 */
void HttpClient::httpDone(bool error)
{
    if (error) {
        cout<<"error"<<endl;
    }
    else {
        cout<<"success"<<endl;
    }
    loop->exit();
}


/****************************************************************************
** Meta object code from reading C++ file 'HttpClient.h'
**
** Created: Tue Jun 14 14:10:37 2011
**      by: The Qt Meta Object Compiler version 59 (Qt 4.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_HttpClient[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   11,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HttpClient[] = {
    "HttpClient\0\0finished(char*)\0responseReceived(QHttpResponseHeader)\0"
    "httpDone(bool)\0"
};

const QMetaObject HttpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpClient,
      qt_meta_data_HttpClient, 0 }
};

const QMetaObject *HttpClient::metaObject() const
{
    return &staticMetaObject;
}

void *HttpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HttpClient))
	return static_cast<void*>(const_cast<HttpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: responseReceived((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 2: httpDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HttpClient::finished(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
