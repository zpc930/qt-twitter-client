/*
* 功能：定义了Http协议的相关属性和方法
* 作者：吕进
*/

#include <iostream>
#include <QtNetwork/QHttp>
#include <QtNetwork/QHttpResponseHeader>
#include <QtNetwork/QHttpRequestHeader>
#include <QtCore/QEventLoop>
#include "HttpClient.h"
#include "Response.h"

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
            cout<<http->readAll().constData()<<endl;
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
