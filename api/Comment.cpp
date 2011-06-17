#include <api/Comment.h>

/* constructors */
Comment::Comment()
{
    this->init();
}

Comment::Comment(const QString id, const QString text, const QString statusId, const int userId)
{
    this->setId(id);
    this->setText(text);
    this->setReplyStatusId(statusId);
    this->setUserId(userId);
}

Comment::Comment(const QString text,const QString statusId, const QString replyCommentId)
{
    this->init();
    this->setText(text);
    this->setReplyStatusId(statusId);
    this->setReplyCommentId(replyCommentId);
}

void Comment::init()
{
    this->setId("");
    this->setText("");
    this->setReplyStatusId("");
    this->setUserId(0);
    this->setNoMention(0);
    this->setCommentOri(0);
}

/* getters */
QString Comment::getId() const
{
    return this->id;
}

QString Comment::getText() const
{
    return this->text;
}

QString Comment::getReplyStatusId() const
{
    return this->replyStatusId;
}

int Comment::getUserId() const
{
    return this->userId;
}

QString Comment::getReplyCommentId() const
{
    return this->replyCommentId;
}

int Comment::getNoMention() const
{
    return this->noMention;
}

int Comment::getCommentOri() const
{
    return this->commentOri;
}

/* setters */
void Comment::setId(const QString id)
{
    this->id = QString(id);
}

void Comment::setText(const QString text)
{
    this->text = QString(text);
}

void Comment::setReplyStatusId(const QString statusId)
{
    this->replyStatusId = QString(statusId);
}

void Comment::setUserId(const int userId)
{
    this->userId = userId;
}

void Comment::setReplyCommentId(const QString commentId)
{
    this->replyCommentId = commentId;
}

void Comment::setNoMention(const int noMention)
{
    if (noMention) {
        this->noMention = 1;
    }
    else {
        this->noMention = 0;
    }
}

void Comment::setCommentOri(const int commentOri)
{
    if (commentOri) {
        this->commentOri = 1;
    }
    else {
        this->commentOri = 0;
    }
}

