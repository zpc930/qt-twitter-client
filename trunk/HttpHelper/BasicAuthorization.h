/*
 * 描述：定义了HTTP基本身份验证方式的属性和方法
 * 作者：吕进
 * 日期：2011-05-18 
 */

#ifndef __BASIC_Authorization_H__
#define __BASIC_Authorization_H__

#include <iostream>
#include <QtCore/QList>
#include "PostParameter.h"
#define AUTH_INFO_LEN 256

class BasicAuthorization
{
    public:
        static void setAuthorization(char* username, char* password, char* authInfo);
    private:
        static char base64_table[];
        static char* base64_encode(char* input);
};

#endif

