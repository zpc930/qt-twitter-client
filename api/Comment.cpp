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

void Comment::init()
{
    this->setId("");
    this->setText("");
    this->setReplyStatusId("");
    this->setUserId(0);
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

