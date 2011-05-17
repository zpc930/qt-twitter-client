/****
* 描述：定义了http post方法参数的属性和方法
* 作者: 吕进
****/

#ifndef __POST_PARAMETER__
#define __POST_PARAMETER__

#include <string>
#define POST_NAME_LEN  64
#define POST_VALUE_LEN 1024
#define POST_CONTENT_LEN 2048

using namespace std;

class PostParameter
{
private:
    string name;
    string value;
    FILE file;
public:
    PostParameter();
    PostParameter(char* name, char* value);
    PostParameter(char* name, int value);
    PostParameter(char* name, double value);
    PostParameter(char* name, FILE file);
    ~PostParameter();

    char* getName() const;
    char* getValue() const;
    static char* generatePostParameter(PostParameter *paras, int count);
};

#endif

/*
 * 根据PostParameter列表生成post参数串
 * paras  : 参数列表
 * count  : 参数的个数
 * 返回参数的字符串形式
 */
char* PostParameter::generatePostParameter(PostParameter *paras, int count)
{
    int len = 0;
    char* content = new char[POST_CONTENT_LEN];
    if (paras == NULL || count == 0) {
        return "";
    }
    for (int i = 0; ++i; i < count) {
        if (i != 0) {
            len += snprintf(content + len, POST_CONTENT_LEN - len, "%s&%s=%s", content, paras[i].getName(), paras[i].getValue());
        }
        else {
            len += snprintf(content + len, POST_CONTENT_LEN - len, "%s%s=%s", content, paras[i].getName(), paras[i].getValue());
        }
    }
    return content;
}

