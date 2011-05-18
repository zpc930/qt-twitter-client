/*
 * 描述：定义了HTTP基本身份验证方式的属性和方法
 * 作者：吕进
 * 日期：2011-05-18 
 */

#include <iostream>
#include <QtCore/QList>
#include "PostParameter.h"
#include "BasicAuthorization.h"

/*
 * Base64编码映射表
 */
char BasicAuthorization::base64_table[] =
       {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
        'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
        'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
        'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/','='};

/*
 * 对输入字符串进行base64编码，返回结果
 * 要编码的输入字符串
 * 返回编码后的字符串
 */
char* BasicAuthorization::base64_encode(char* input)
{
    int len = strlen(input);
    char* output = new char[len * 2]; 
    int index = 0;
    int j = 0;
    if (len % 3 == 0) {
        for (index = 0; index < len; index += 3) {
            output[j++] = base64_table[input[index]>>2];
            output[j++] = base64_table[(input[index] & 0x3)<<4 | (input[index + 1]>>4)];
            output[j++] = base64_table[(input[index + 1] & 0xF)<<2 | (input[index + 2]>>6)];
            output[j++] = base64_table[input[index+2] & 0x3F];
        }
    }   
    else if (len % 3 == 1) {
        for (index = 0; index < len - 1; index += 3) {
            output[j++] = base64_table[input[index]>>2];
            output[j++] = base64_table[(input[index] & 0x3)<<4 | (input[index + 1]>>4)];
            output[j++] = base64_table[(input[index + 1] & 0xF)<<2 | (input[index + 2]>>6)];
            output[j++] = base64_table[input[index+2] & 0x3F];
        }
        output[j++] = base64_table[input[index]>>2];
        output[j++] = base64_table[(input[index] & 0x3)<<4];
        output[j++] = base64_table[64];
        output[j++] = base64_table[64];
    }
    else if (len % 3 == 2) {
        for (index = 0; index < len - 2; index += 3) {
            output[j++] = base64_table[input[index]>>2];
            output[j++] = base64_table[(input[index] & 0x3)<<4 | (input[index + 1]>>4)];
            output[j++] = base64_table[(input[index + 1] & 0xF)<<2 | (input[index + 2]>>6)];
            output[j++] = base64_table[input[index+2] & 0x3F];
        }
        output[j++] = base64_table[input[index]>>2];
        output[j++] = base64_table[(input[index] & 0x3)<<4 | (input[index + 1]>>4)];
        output[j++] = base64_table[(input[index + 1] & 0xF)<<2];
        output[j++] = base64_table[64];
    }
    output[j] = '\0';
    return output;
}

/*
 * 根据验证信息添加HTTP基本验证方式的参数
 * paras    : post方法参数列表
 * username : 用户名信息
 * password : 密码信息
 */
void BasicAuthorization::setAuthorization(char* username, char* password, char* authInfo)
{
    char authStr[AUTH_INFO_LEN + 1];
    char* encodedAuth = NULL;
    
    // 拼接用户名密码
    snprintf(authStr, AUTH_INFO_LEN, "%s:%s", username, password);

    // 对用户名密码进行base64编码
    encodedAuth = base64_encode(authStr);

    // 为返回结果赋值
    sprintf(authInfo, "Basic %s", encodedAuth);

    delete[] encodedAuth;
}

