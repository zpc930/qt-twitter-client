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
#include <api/User.h>

using namespace std;

/*
 * comment类字段说明
 * @id              : 评论的id
 * @text            : 评论的内容
 * @replyStatusId   : 评论回复的微博的id (发布评论操作的时候需要设置此值)
 * @replyCommentId  : 评论回复的评论的id (发布评论操作的时候需要设置此值，与replyStatusId二选一，如果都填了，默认回复评论)
 * @noMention       : 在评论中禁用 @好友 功能: 0为不禁用，其他为禁用，默认为0
 * @commentOri      : 如果评论的微博是转发微博，是否同时评论原微博，0为不评论，1为评论，模认为0
 * @user            : 评论的发布者信息
 * @status          : 评论回复的微博的信息，读取评论的时候可以读取此字段
 * @userId          : 评论的发布者id
 */
class Comment
{
private:
    QString id;
    QString text;
    QString replyStatusId;
    QString replyCommentId;
    int noMention;
    int commentOri;
    User* user;
    Status* status;
    int userId;
    void init();
public:
    /* constructors */
    Comment();
    Comment(const QString id, const QString text, const QString statusId, const int userId);
    Comment(const QString text, const QString statusId, const QString replyCommentId);

    ~Comment();

    /* getters */
    QString getId() const;
    QString getText() const;
    QString getReplyStatusId() const;
    QString getReplyCommentId() const;
    int getNoMention() const;
    int getCommentOri() const;
    int getUserId() const;
    User* getUser() const;
    Status* getStatus() const;

    /* setters */
    void setId(const QString id);
    void setText(const QString text);
    void setReplyStatusId(const QString statusId);
    void setReplyCommentId(const QString commentId);
    void setNoMention(const int noMention);
    void setCommentOri(const int commentOri);
    void setUserId(const int userId);
    void setUser(User* user);
    void setStatus(Status* status);
};

#endif //__COMMENT_H__
