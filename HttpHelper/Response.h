/***
* 描述：定义了http response的相关属性和方法
* 作者：吕进
***/

#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <QtXml/QDomDocument>
#include <cstdlib>
#include <string>
using namespace std;

class Response
{
public:
    Response();
    Response(int statusCode, char* content);
    ~Response();
    string responseAsString() const;
    QDomDocument* responseAsDocument();
    void setStatusCode(const int statusCode);
    int getStatusCode() const;
    void setResponseAsString(const char* content);
private:
    int statusCode;
    string asString;
    QDomDocument* asDocument;
};

#endif

