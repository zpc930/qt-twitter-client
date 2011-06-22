/*
 * SinaComment类：定义了新浪微博评论的相关字段和方法
 * 作者：吕进
 * 日期：2011-06-17
 */

#ifndef __SINA_COMMENT_H__
#define __SINA_COMMENT_H__

#include <iostream>
#include <string>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <api/Comment.h>
#include <api/sina/SinaStatus.h>
#include <api/sina/SinaUser.h>

#define NODE_COMMENT_ROOT "comment"
#define NODE_NAME_ID "id"
#define NODE_NAME_TEXT "text"
#define NODE_NAME_STATUS "status"
#define NODE_NAME_USER "user"

class SinaComment: public Comment
{
public:
    /* constructors */
    SinaComment();
    SinaComment(const QString id, const QString text, const QString statusId, const int userId);

    /* loaders: override functions */
    void loadFromXml(QDomNode node);
    void loadListFromXml(QDomDocument docXml, list<Comment*>& lsComment);
};

#endif //__SINA_COMMENT_H__
