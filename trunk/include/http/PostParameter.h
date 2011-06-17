/****
* 描述：定义了http post方法参数的属性和方法
* 作者: 吕进
****/

#ifndef __POST_PARAMETER__
#define __POST_PARAMETER__

#include <QtCore/QList>
#include <string>
#define POST_NAME_LEN  64
#define POST_VALUE_LEN 1024
#define POST_CONTENT_LEN 2048

using namespace std;

class PostParameter
{
private:
    char* name;
    char* value;
    FILE file;
public:
    PostParameter();
    PostParameter(const char* name, const char* value);
    PostParameter(const char* name, const int value);
    PostParameter(const char* name, const double value);
    //PostParameter(char* name, FILE file);
    ~PostParameter();

    char* getName() const;
    char* getValue() const;
    void setName(const char* name);
    void setValue(const char* value);
    void setValue(const int value);
    void setValue(const double value);
    void releaseParas(QList<PostParameter*> paras);
    void encodeUrl(char* paraVal);
    char* generatePostParameter(QList<PostParameter*> &paras);
};

#endif

