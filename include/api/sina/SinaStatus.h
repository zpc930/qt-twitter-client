/*
 * Status类：定义了微博状态相关的字段和函数
 * 作者：吕进
 * 日期：2011-06-14
 */

#ifndef __SINA_STATUS_H__
#define __SINA_STATUS_H__

#include <api/Status.h>
#include <http/Response.h>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>

#define NODE_NAME_ID "id"
#define NODE_NAME_TEXT "text"
#define NODE_NAME_SOURCE "source"
#define NODE_NAME_FAVOURATE "favourated"
#define NODE_NAME_TRUNCATED "truncated"
#define NODE_NAME_REPLY_STSTUS_ID "in_reply_to_status_id"
#define NODE_NAME_REPLY_USER_ID "in_reply_to_user_id"
#define NODE_NAME_REPLY_SCREEN_NAME "in_reply_to_screen_name"

class SinaStatus : public Status
{
public:
    SinaStatus();
    SinaStatus(char* text);
    void loadFromXml(QDomNode node);
    void loadListFromXml(QDomDocument docXml, list<Status*>& lsStatus);
};

#endif
