#include <api/sina/SinaStatus.h>

/* constructors */
SinaStatus::SinaStatus()
{
}

SinaStatus::SinaStatus(char* text):Status(text)
{
}

/* loaders */
void SinaStatus::loadFromXml(QDomNode node)
{
    QDomNodeList lsChild = node.childNodes();
    char rpy_status_id[STATUS_ID_LEN + 1];
    int rpy_usr_id = 0;
    for (int i = 0; i < lsChild.length(); ++i) {
        QDomNode child = lsChild.at(i);
        if(child.nodeName() == NODE_NAME_ID) {
#if API_PROVIDER_DEBUG
            cout<<child.toElement().text().toStdString().c_str()<<endl;
#endif
            this->setId(child.toElement().text().toStdString().c_str());
        }
        else if(child.nodeName() == NODE_NAME_TEXT) {
            this->setText(child.toElement().text().toStdString().c_str());
        }
        else if(child.nodeName() == NODE_NAME_SOURCE) {
            this->setSource(child.toElement().text().toStdString().c_str());
        }
        else if(child.nodeName() == NODE_NAME_FAVOURATE) {
            if (child.toElement().text() == "true") {
                this->setIsFavourate(1);
            }
            else {
                this->setIsFavourate(0);
            }
        }
        else if(child.nodeName() == NODE_NAME_TRUNCATED) {
            if (child.toElement().text() == "true") {
                this->setIsTruncated(1);
            }
            else {
                this->setIsTruncated(0);
            }
        }
        else if(child.nodeName() == NODE_NAME_REPLY_STSTUS_ID) {
            strncpy(rpy_status_id, child.toElement().text().toStdString().c_str(), STATUS_ID_LEN);
            rpy_status_id[STATUS_ID_LEN] = '\0';
        }
        else if(child.nodeName() == NODE_NAME_REPLY_USER_ID) {
            rpy_usr_id = atoi(child.toElement().text().toStdString().c_str());
        }
        else if(child.nodeName() == NODE_NAME_REPLY_SCREEN_NAME) {
            this->setInReplyInfo(rpy_status_id, rpy_usr_id, child.toElement().text().toStdString().c_str());
        }
        else if(child.nodeName() == NODE_NAME_USER) {
            SinaUser *user = new SinaUser();
            user->loadFromXml(child);
            this->setUser(user);
        }
        else if (child.nodeName() == NODE_NAME_RETWEETED) {
            SinaStatus* status = new SinaStatus();
            status->loadFromXml(child);
            this->setRetweetedStatus(status);
        }
    }
}

void SinaStatus::loadListFromXml(QDomDocument docXml, list<Status*>& lsStatus)
{
    QDomNodeList lsNode = docXml.elementsByTagName(NODE_STATUS_ROOT);
    for (int i = 0; i < lsNode.length(); ++i) {
        QDomNode node = lsNode.at(i);
        SinaStatus* status = new SinaStatus();
        status->loadFromXml(node);
        lsStatus.push_back(status);
    }
}
