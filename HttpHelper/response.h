/***
* a class to define the http response
* author: 吕进
***/
#include <QtXml/QDomDocument>
#include <cstdlib>
#include <string>
using namespace std;

class response
{
public:
    response();
    response(int statusCode, char* content);
    ~response();
    string responseAsString() const;
    QDomDocument* responseAsDocument();
    void setStatusCode(int statusCode);
    int getStatusCode() const;
    void setResponseAsString(char* content);
private:
    int statusCode;
    string asString;
    QDomDocument* asDocument;
};

