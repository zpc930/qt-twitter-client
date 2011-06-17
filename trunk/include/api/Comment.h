/*
 * Comment类，定义了微博评论相关的字段和方法
 * 作者：吕进
 * 日期：2011-06-17
 */

#ifndef __COMMENT_H__
#define __COMMENT_H__

#include <string>
#include <iostream>
#include <QtXml/QDomDocument>
#include <api/Status.h>

using namespace std;

class Comment
{
private:
    QString id;
    QString text;
    QString replyStatusId;
    int userId;
    void init();
public:
    /* constructors */
    Comment();
    Comment(const QString id, const QString text, const QString statusId, const int userId);

    /* getters */
    QString getId() const;
    QString getText() const;
    QString getReplyStatusId() const;
    int getUserId() const;

    /* setters */
    void setId(const QString id);
    void setText(const QString text);
    void setReplyStatusId(const QString statusId);
    void setUserId(const int userId);

    /* loaders */
    virtual void loadFromXml(QDomNode node) = 0;
    virtual void loadListFromXml(QDomDocument docXml, list<Comment*>& lsComment) = 0;
};

#endif //__COMMENT_H__
