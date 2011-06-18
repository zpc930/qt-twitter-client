#include <api/Status.h>

/* getters */
const char* Status::getId() const
{
    return this->id;
}

const char* Status::getText() const
{
    return this->text;
}

const char* Status::getSource() const
{
    return this->source;
}

int Status::getIsTruncated() const
{
    return this->isTruncated;
}

const char* Status::getInReplyToStatusId() const
{
    return this->inReplyToStatusId;
}

int Status::getInReplyToUserId() const
{
    return this->inReplyToUserId;
}

int Status::getIsFavourate() const
{
    return this->isFavourate;
}

const char* Status::getInReplyToScreenName() const
{
    return this->inReplyToScreenName;
}

User* Status::getUser() const
{
    return this->user;
}

/* setters */
void Status::setText(const char* text)
{
    strncpy(this->text, text, STATUS_TEXT_LEN);
    this->text[STATUS_TEXT_LEN] = '\0';
}
void Status::setSource(const char* source)
{
    strncpy(this->source, source, STATUS_SOURCE_LEN);
    this->source[STATUS_SOURCE_LEN] = '\0';
}

void Status::setInReplyInfo(const char* statusId,const int userId,const char* screenName)
{
    strncpy(this->inReplyToStatusId, statusId, STATUS_ID_LEN);
    this->inReplyToStatusId[STATUS_ID_LEN] = '\0';
    this->inReplyToUserId = userId;
    if (statusId != 0) {
        strncpy(this->inReplyToScreenName, screenName, STATUS_SCREEN_NAME_LEN);
        this->inReplyToScreenName[STATUS_SCREEN_NAME_LEN] = '\0';
    }
}

void Status::setIsFavourate(const int isFavourate)
{
    this->isFavourate = isFavourate;
}

void Status::setIsTruncated(const int isTruncated)
{
    this->isTruncated = isTruncated;
}

void Status::setId(const char* id)
{
    strncpy(this->id, id, STATUS_ID_LEN);
    this->id[STATUS_ID_LEN] = '\0';
}

void Status::setUser(User* user)
{
    this->user = user;
}

void Status::init()
{
    this->latitude = 0;
    this->longitude = 0;
    this->bmiddle_pic = NULL;
    this->original_pic = NULL;
    this->thumbnail_pic = NULL;
    this->setInReplyInfo("", 0, "");
    this->setUser(NULL);
}

/* constructors */
Status::Status()
{
    this->init();
}
Status::Status(char* text)
{
    this->init();
    this->setText(text);
}

Status::~Status()
{
    if (this->user != NULL) {
        delete this->user;
        this->setUser(NULL);
    }
}
