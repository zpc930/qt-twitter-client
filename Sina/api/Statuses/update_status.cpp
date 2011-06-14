#include <api/sina/SinaStatus.h>

/* getters */
long SinaStatus::getId() const
{
    return this->id;
}

char* SinaStatus::getText() const
{
    return this->text;
}

char* SinaStatus::getSource() const
{
    return this->source;
}

int SinaStatus::getIsTruncated() const
{
    return this->isTruncated;
}

long SinaStatus::getInReplyToStatusId() const
{
    return this->inReplyToStatusId;
}

int SinaStatus::getInReplyToUserId() const
{
    return this->inReplyToUserId;
}

int SinaStatus::getIsFavourate() const
{
    return this->isFavourate;
}

char* SinaStatus::getInReplyToScreenName() const
{
    return this->inReplyToScreenName;
}

/* setters */
void SinaStatus::setText(const char* text)
{
    strncpy(this->text, text, STATUS_TEXT_LEN);
    this->text[STATUS_TEXT_LEN] = '\0';
}
void SinaStatus::setSource(const char* source)
{
    strncpy(this->source, source, STATUS_SOURCE_LEN);
    this->source[STATUS_SOURCE_LEN] = '\0';
}

void SinaStatus::setInReplyInfo(const long statusId,const int userId,const char* screenName)
{
    this->inReplyToStatusId = statusId;
    this->inReplyToUserId = userId;
    if (statusId != 0) {
        strncpy(this->inReplyToScreenName, screenName, STATUS_SCREEN_NAME_LEN);
        this->inReplyToScreenName[STATUS_SCREEN_NAME_LEN] = '\0';
    }
}

void SinaStatus::setIsFavourate(const int isFavourate)
{
    this->isFavourate = isFavourate;
}

void SinaStatus::setIsTruncated(const int isTruncated)
{
    this->isTruncated = isTruncated;
}

void SinaStatus::setId(const long id)
{
    this->id = id;
}

/* constructors */
SinaStatus::Status()
{
    this->setInReplyInfo(0, 0, NULL);
}
SinaStatus::Status(char* text)
{
    Status();
    this->setText(text);
}

/* loaders */
void SinaStatus::loadFromXml(QDomNode node)
{
    QDomNodeList lsChild = node.childNodes();
    long rpy_status_id = 0;
    int rpy_usr_id = 0;
    for (int i = 0; i < lsChild.length(); ++i) {
        QDomNode child = lsChild.at(i);
        if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_ID)) {
            this->id = atol(child.toElement().text().toStdString().c_str());
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_TEXT)) {
            this->setText(child.toElement().text().toStdString().c_str());
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_SOURCE)) {
            this->setSource(child.toElement().text().toStdString().c_str());
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_FAVOURATE)) {
            if (!strcmp(child.toElement().text().toStdString().c_str(), "true")) {
                this->setIsFavourate(1);
            }
            else {
                this->setIfFavourate(0);
            }
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_TRUNCATED)) {
            if (!strcmp(child.toElement().text().toStdString().c_str(), "true")) {
                this->setIsTruncated(1);
            }
            else {
                this->setIfTruncated(0);
            }
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_REPLY_STSTUS_ID)) {
            rpy_status_id = atol(child.toElement().text().toStdString().c_str());
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_REPLY_USER_ID)) {
            rpy_usr_id = atoi(child.toElement().text().toStdString().c_str());
        }
        else if(!strcmp(child.nodeName().toStdString.c_str(), NODE_NAME_REPLT_SCREEN_NAME)) {
            this->setReplyInfo(rpy_status_id, rpy_usr_id, child.toElement().text().toStdString().c_str());
        }
    }
}

void SinaStatus::loadListFromXml(QDomDocument docXml, list<Status>& lsStatus)
{
    QDomNodeList lsNode = docXml.elementsByTagName("status");
    for (int i = 0; i < lsNode.length(); ++i) {
        QDomNode node = lsNode.at(i);
        SinaStatus status;
        status.loadFromXml(node);
        lsStatus.push_back(status);
    }
}
