/***
* 描述：定义了http response的相关属性和方法
* 作者：吕进
***/

#include <QtXml/QDomDocument>
#include <cstdlib>
#include <cstring>
#include <http/Response.h>

/*
 * 默认参数构造函数
 * 对response进行初始化
 */
Response::Response()
{
    this->statusCode = 0;
    this->asString.clear();
    this->asDocument = NULL;
}

/*
* 带参数的构造函数
* statusCode : response的状态码
* content    : response的内容串
*/
Response::Response(int statusCode, char* content)
{
    this->statusCode = statusCode;
    this->asString.assign(content);
    this->asDocument = NULL;
}

/*
 * 析构函数
 * 释放资源
 */
Response::~Response()
{
    if (this->asDocument != NULL) {
        delete asDocument;
        asDocument = NULL;
    }
}

/*
 * 以字符串形式获取response
 * 返回response的内容字符串
 */
string Response::responseAsString() const
{
    return this->asString;
}

/*
 * 以XML文档的形式获取response
 * 返回response的XML内容
 */
QDomDocument* Response::responseAsDocument()
{
    /*if (this->asString.empty()) {
        return NULL;
    }*/
    if (NULL == asDocument) {
        this->asDocument = new QDomDocument();
        QString str(this->asString.c_str());
        this->asDocument->setContent(str);
    }
    return asDocument;
}

/*
 * 获取response的状态码
 * 返回repsonse的状态码：200为成功，其他为失败
 */
int Response::getStatusCode() const
{
    return this->statusCode;
}

/*
 * 设置response的状态码
 * statusCode : 状态码
 */
void Response::setStatusCode(const int statusCode)
{
    this->statusCode = statusCode;
}

/*
 * 以字符串设置response内容
 * content : response的内容字符串
 */
void Response::setResponseAsString(const char* content)
{
    if (!this->asString.empty()) {
        asString.clear();
    }
    asString.assign(content); 
}

