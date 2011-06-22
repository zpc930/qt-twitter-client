#include <api/sina/SinaComment.h>
#include <api/sina/SinaStatus.h>

/* constructors */
SinaComment::SinaComment()
{
}

SinaComment::SinaComment(const QString id, const QString text, const QString statusId, const int userId):Comment(id, text, statusId, userId)
{
}

/* loaders: override functions */
void SinaComment::loadFromXml(QDomNode node)
{
    QDomNodeList lsChild = node.childNodes();
    for (int i = 0; i < lsChild.length(); ++i) {
        QDomNode child = lsChild.at(i);

        if (child.nodeName() == NODE_NAME_ID) {
            /* set comment id */
            this->setId(child.toElement().text());
        }
        else if (child.nodeName() == NODE_NAME_TEXT) {
            /* set comment text */
            this->setText(child.toElement().text());
        }
        else if (child.nodeName() == NODE_NAME_STATUS) {
            /* set repliy status id */
            SinaStatus* status = new SinaStatus();
            status->loadFromXml(child);
            this->setReplyStatusId(status->getId());
            this->setStatus(status);
        }
        else if (child.nodeName() == NODE_NAME_USER) {
            /* set comment user id  */
            SinaUser* user = new SinaUser();
            user->loadFromXml(child);
            this->setUser(user);
        }
    }
}

void SinaComment::loadListFromXml(QDomDocument docXml, list<Comment*>& lsComment)
{
    QDomNodeList lsNode = docXml.elementsByTagName(NODE_COMMENT_ROOT);
    SinaComment* comment = NULL;
    for (int i = 0; i < lsNode.length(); ++i) {
        QDomNode node = lsNode.at(i);
        comment = new SinaComment();
        comment->loadFromXml(node);
        lsComment.push_back(comment);
    }
}
