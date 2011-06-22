/*
 * SinaStatus类：定义了新浪微博状态相关的字段和函数
 * 作者：吕进
 * 日期：2011-06-14
 */

#ifndef __SINA_STATUS_H__
#define __SINA_STATUS_H__

#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <api/Status.h>
#include <api/sina/SinaUser.h>
#include <http/Response.h>

#define NODE_STATUS_ROOT "status"
#define NODE_NAME_ID "id"
#define NODE_NAME_TEXT "text"
#define NODE_NAME_SOURCE "source"
#define NODE_NAME_FAVOURATE "favourated"
#define NODE_NAME_TRUNCATED "truncated"
#define NODE_NAME_REPLY_STSTUS_ID "in_reply_to_status_id"
#define NODE_NAME_REPLY_USER_ID "in_reply_to_user_id"
#define NODE_NAME_REPLY_SCREEN_NAME "in_reply_to_screen_name"
#define NODE_NAME_USER "user"
#define NODE_NAME_RETWEETED "retweeted_status"

class SinaStatus : public Status
{
public:
    SinaStatus();
    SinaStatus(char* text);
    void loadFromXml(QDomNode node);
    void loadListFromXml(QDomDocument docXml, list<Status*>& lsStatus);
};

#endif
