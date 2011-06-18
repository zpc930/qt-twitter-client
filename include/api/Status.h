/*
 * Status类：定义了微博状态相关的字段和函数
 * 作者：吕进
 * 日期：2011-06-14
 */

#ifndef __STATUS_H__
#define __STATUS_H__

#include <iostream>
#include <string.h>
#include <list>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <http/Response.h>
#include <api/ApiGlobal.h>
#include <api/User.h>

#define STATUS_ID_LEN 32
#define STATUS_TEXT_LEN 300
#define STATUS_SOURCE_LEN 64
#define STATUS_SCREEN_NAME_LEN 64

using namespace std;
class User;
class Status
{
private:
    char id[STATUS_ID_LEN + 1];
    char text[STATUS_TEXT_LEN + 1];
    char source[STATUS_SOURCE_LEN + 1];
    int isTruncated;
    char inReplyToStatusId[STATUS_ID_LEN + 1];
    int inReplyToUserId;
    char inReplyToScreenName[STATUS_SCREEN_NAME_LEN + 1];
    int isFavourate;
    double latitude;
    double longitude;
    char* thumbnail_pic;
    char* bmiddle_pic;
    char* original_pic;
    User* user;
    Status* retweetedStatus;
    void init();
public:
    /* getters */
    const char* getId() const;
    const char* getText() const;
    const char* getSource() const;
    int getIsTruncated() const;
    const char* getInReplyToStatusId() const;
    int getInReplyToUserId() const;
    const char* getInReplyToScreenName() const;
    int getIsFavourate() const;
    User* getUser() const;
    Status* getRetweetedStatus() const;
    
    /* setters */
    void setText(const char* text);
    void setSource(const char* source);
    void setInReplyInfo(const char* statusId,const int userId,const char* screenName);
    void setIsFavourate(const int isFavourate);
    void setIsTruncated(const int isTruncated);
    void setId(const char* id);
    void setUser(User* user);
    void setRetweetedStatus(Status* status);

    /* constructors */
    Status();
    Status(char* text);

    ~Status();
};

#endif
