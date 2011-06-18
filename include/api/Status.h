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

/*
 * status类字段说明
 * @id                  : 微博的id
 * @text                : 微博的内容
 * @source              : 发布微博的客户端应用号
 * @isTruncated         : 微博是否被截断
 * @isReplyToStatusId   : 微博转发的微博的id
 * @isReplyToUserId     : 微博转发的微博的发布者id
 * @isReplyToScreenName : 微博转发的微博的发布者屏显名称
 * @isFavourate         : 微博是否被收藏
 * @latitude            : 微博发布时的纬度(共享地理位置) 保留
 * @longtitude          : 微博发布时的经度(共享地址位置) 保留
 * @thumbnail_pic       : 小图片的url 保留
 * @bmiddle_pic         : 中图片的url 保留
 * @original_pic        : 原图片的url 保留
 * @user                : 发布者信息
 * @retweetedStatus     : 转发的微博的信息
 */
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
