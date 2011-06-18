#include <api/Comment.h>

/* constructors */
Comment::Comment()
{
    this->init();
}

Comment::Comment(const QString id, const QString text, const QString statusId, const int userId)
{
    this->init();
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

Comment::~Comment()
{
    if (this->user != NULL) {
        delete this->user;
        this->setUser(NULL);
    }
    if (this->status != NULL) {
        delete this->status;
        this->setStatus(NULL);
    }
}

void Comment::init()
{
    this->setId("");
    this->setText("");
    this->setReplyStatusId("");
    this->setUserId(0);
    this->setNoMention(0);
    this->setCommentOri(0);
    this->setUser(NULL);
    this->setStatus(NULL);
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

User* Comment::getUser() const
{
    return this->user;
}

Status* Comment::getStatus() const
{
    return this->status;
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

void Comment::setUser(User* user)
{
    this->user = user;
}

void Comment::setStatus(Status* status)
{
    this->status = status;
}

