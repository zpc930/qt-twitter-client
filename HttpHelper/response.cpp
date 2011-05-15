/***
* a class to define the http response
* author: 吕进
***/
#include <QtXml/QDomDocument>
#include <cstdlib>
#include <cstring>
#include "response.h"

response::response()
{
    this->statusCode = 0;
    this->asString.clear();
    this->asDocument = NULL;
}

response::response(int statusCode, char* content)
{
    this->statusCode = statusCode;
    this->asString.assign(content);
    this->asDocument = NULL;
}

response::~response()
{
    if (this->asDocument != NULL) {
        delete asDocument;
        asDocument = NULL;
    }
}

string response::responseAsString() const
{
    return this->asString;
}

QDomDocument* response::responseAsDocument()
{
    if (NULL == asDocument) {
    }
    return asDocument;
}

int response::getStatusCode() const
{
    return this->statusCode;
}

void response::setStatusCode(int statusCode)
{
    this->statusCode = statusCode;
}

void response::setResponseAsString(char* content)
{
    if (!this->asString.empty()) {
        asString.clear();
    }
    asString.assign(content); 
}

