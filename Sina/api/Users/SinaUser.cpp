/*
 * SinaUser.cpp
 *
 *  Created on: Jun 17, 2011
 *      Author: Eric
 */
#include <api/sina/SinaUser.h>
#include <api/sina/SinaStatus.h>

SinaUser::SinaUser():status(NULL){

}

void SinaUser::loadFromXml(QDomNode node){
	QDomNodeList lsChild = node.childNodes();
	int lsChildLength=lsChild.length();
	bool dataTransformFlag=false;
	for (int i = 0; i < lsChildLength; ++i) {
		QDomNode child = lsChild.at(i);
		if(child.nodeName()==USER_NODE_NAME_ID){
			setId(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_SCREEN_NAME){
	    	this->setScreen_name(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_NAME){
	    	this->setName(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_PROVINCE){
	    	this->setProvince(child.toElement().text().toInt(&dataTransformFlag,10));
	    }else if(child.nodeName()==USER_NODE_NAME_CITY){
	    	this->setCity(child.toElement().text().toInt(&dataTransformFlag,10));
	    }else if(child.nodeName()==USER_NODE_NAME_LOCATION){
	    	this->setLocation(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_DESCRIPTION){
	    	this->setDescription(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_URL){
	    	this->setUrl(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_PROFILE_IMAGEURL){
	    	this->setProfile_image_url(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_DOMAIN){
	    	this->setDomain(child.toElement().text());
	    }else if(child.nodeName()==USER_NODE_NAME_GENDER){
	    	QString qstr=child.toElement().text();
	    	User_Gender ug;
	    	if(qstr=="m")
	    		ug=GENDER_MALE;
	    	else if(qstr=="f")
	    		ug=GENDER_FEMALE;
	    	else if(qstr=="n")
	    		ug=GENDER_UNKNOWN;
	    	this->setGender(ug);
	    }else if(child.nodeName()==USER_NODE_NAME_FOLLOWERS_COUNT){
	    	this->setFollowers_count(child.toElement().text().toInt(&dataTransformFlag,10));
	    }else if(child.nodeName()==USER_NODE_NAME_STATUSES_COUNT){
	    	this->setStatuses_count(child.toElement().text().toInt(&dataTransformFlag,10));
	    }else if(child.nodeName()==USER_NODE_NAME_FAVOURITES_COUNT){
	    	this->setFavourites_count(child.toElement().text().toInt(&dataTransformFlag,10));
	    }else if(child.nodeName()==USER_NODE_NAME_CREATE_AT){
	    	QDateTime dateTime;
	    	dateTime.fromString(child.toElement().text(),Qt::TextDate);
	    	this->setCreate_at(dateTime);
	    }else if(child.nodeName()==USER_NODE_NAME_FOLLOWING){
	    	QString qstr=child.toElement().text();
	    	bool followingTmp;
	    	if(qstr=="false")
	    		followingTmp=false;
	    	else if(qstr=="true")
	    		followingTmp=true;
	    	this->setFollowing(followingTmp);
	    }else if(child.nodeName()==USER_NODE_NAME_VERIFIED){
	    	QString qstr=child.toElement().text();
	    	bool verifiedTmp;
	    	if(qstr=="false")
	    		verifiedTmp=false;
	    	else if(qstr=="true")
	    		verifiedTmp=true;
	    	this->setVerified(verifiedTmp);
	    }else if(child.nodeName()==USER_NODE_NAME_STATUS){
	    	SinaStatus * statusTmp=new SinaStatus();
	    	statusTmp->loadFromXml(child);
	    	this->setStatus(statusTmp);
	    }
	}
}

void SinaUser::loadListFromXml(QDomDocument docXml, list<User*> & lsUser){
	QDomNodeList lsNode = docXml.elementsByTagName("user");
	    for (unsigned int i = 0; i < lsNode.length(); ++i) {
	        QDomNode node = lsNode.at(i);
	        SinaUser * sinaUser = new SinaUser();
	        sinaUser->loadFromXml(node);
	        lsUser.push_back(sinaUser);
	    }
}

void SinaUser::setStatus(Status* status){
	this->status=status;
}
Status* SinaUser::getStatus(){
	return status;
}
