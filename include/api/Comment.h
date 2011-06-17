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
    QString replyCommentId;
    int noMention;
    int commentOri;
    int userId;
    void init();
public:
    /* constructors */
    Comment();
    Comment(const QString id, const QString text, const QString statusId, const int userId);
    Comment(const QString text, const QString statusId, const QString replyCommentId);

    /* getters */
    QString getId() const;
    QString getText() const;
    QString getReplyStatusId() const;
    QString getReplyCommentId() const;
    int getNoMention() const;
    int getCommentOri() const;
    int getUserId() const;

    /* setters */
    void setId(const QString id);
    void setText(const QString text);
    void setReplyStatusId(const QString statusId);
    void setReplyCommentId(const QString commentId);
    void setNoMention(const int noMention);
    void setCommentOri(const int commentOri);
    void setUserId(const int userId);
};

#endif //__COMMENT_H__
