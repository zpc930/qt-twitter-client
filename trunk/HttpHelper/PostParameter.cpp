/****
* 描述：定义了http post方法参数的属性和方法
* 作者: 吕进
****/
#include <iostream>
#include <QtCore/QList>
#include <string>
#include <http/PostParameter.h>
using namespace std;

/*
 * 默认参数构造函数
 */
PostParameter::PostParameter()
{
    this->name = NULL;
    this->value = NULL;
}

/*
 * 带参数的构造函数：value为字符串类型
 * name  : 参数的名称
 * value : 参数的值
 */
PostParameter::PostParameter(const char* name, const char* value)
{
    this->name = NULL;
    this->value = NULL;
    this->setName(name);
    this->setValue(value);
}

/*
 * 带参数的构造函数：value为整型
 * name  : 参数的名称
 * value : 参数的值
 */
PostParameter::PostParameter(const char* name, const int value)
{
    this->name = NULL;
    this->value = NULL;
    this->setName(name);
    this->setValue(value);
}

/*
 * 带参数的构造函数：value为浮点型
 * name  : 参数的名称
 * value : 参数的值
 */
PostParameter::PostParameter(const char* name, const double value)
{
    this->name = NULL;
    this->value = NULL;
    this->setName(name);
    this->setValue(value);
}

/*
 * 析构函数
 */
PostParameter::~PostParameter()
{
    if (this->name != NULL) {
        delete[] name;
        name = NULL;
    }
    if (this->value != NULL) {
        delete[] value;
        value = NULL;
    }
}

/*
 * 获取参数名称
 * 返回参数的名称
 */
char* PostParameter::getName() const
{
    return this->name;
}

/*
 * 获取参数的值，字符串类型
 * 返回参数的值的字符串类型
 */
char* PostParameter::getValue() const
{
    return this->value;
}

/*
 * 设置参数名称
 * name : 参数名称
 */
void PostParameter::setName(const char* name)
{
    if (this->name != NULL) {
        delete[] this->name;
        this->name = NULL;
    }
    this->name = new char[POST_NAME_LEN + 1];
    strncpy(this->name, name, POST_NAME_LEN);
    this->name[POST_NAME_LEN] = '\0';
}

/*
 * 设置参数的值：字符串类型
 * value : 参数的值
 */
void PostParameter::setValue(const char* value)
{
    if (this->value != NULL) {
        delete[] this->value;
        this->value = NULL;
    }
    this->value = new char[POST_VALUE_LEN + 1];
    strncpy(this->value, value, POST_VALUE_LEN);
    this->value[POST_VALUE_LEN] = '\0';
}

/*
 * 设置参数的值：整型
 * value : 参数的值
 */
void PostParameter::setValue(const int value)
{
    if (this->value != NULL) {
        delete[] this->value;
        this->value = NULL;
    }
    this->value = new char[POST_VALUE_LEN + 1];
    snprintf(this->value, POST_VALUE_LEN + 1, "%d", value);
}

/*
 * 设置参数的值：浮点型
 * value : 参数的值
 */
void PostParameter::setValue(const double value)
{
    if (this->value != NULL) {
        delete[] this->value;
        this->value = NULL;
    }
    this->value = new char[POST_VALUE_LEN + 1];
    snprintf(this->value, POST_VALUE_LEN + 1, "%lf", value);
}

/*
 * 根据PostParameter列表生成post参数串
 * paras  : 参数列表
 * count  : 参数的个数
 * 返回参数的字符串形式
 */
char* PostParameter::generatePostParameter(QList<PostParameter*> &paras)
{
    int len = 0;
    char* content = new char[POST_CONTENT_LEN + 1];
    content[0] = '\0';
    int count = paras.count();
    if (count == 0) {
        return content;
    }
    cout<<"before for:"<<POST_CONTENT_LEN<<"count:"<<count<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<"len:"<<len<<"i:"<<i<<endl;
        if (i != 0) {
            len += snprintf(content + len, POST_CONTENT_LEN - len, "&%s=%s", paras[i]->getName(), paras[i]->getValue());
        }
        else {
            len += snprintf(content + len, POST_CONTENT_LEN - len, "%s=%s", paras[i]->getName(), paras[i]->getValue());
        }
        cout<<"content:"<<content<<endl;
    }
    cout<<"after for"<<endl;
    return content;
}

