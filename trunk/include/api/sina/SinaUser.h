/*
 * SinaUser.h
 *
 *  Created on: Jun 16, 2011
 *      Author: Eric
 */
#ifndef _SINAUSER_H_
#define _SINAUSER_H_
#include <api/User.h>
#include <iostream>
#include <string.h>
#include <http/Response.h>
#include <api/ApiGlobal.h>
#include <list>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <api/Status.h>

#define NODE_USER_ROOT "user"
#define USER_NODE_NAME_ID "id"
#define USER_NODE_NAME_SCREEN_NAME "screen_name"
#define USER_NODE_NAME_NAME "name"
#define USER_NODE_NAME_PROVINCE "province"
#define USER_NODE_NAME_CITY "city"
#define USER_NODE_NAME_LOCATION "location"
#define USER_NODE_NAME_DESCRIPTION "description"
#define USER_NODE_NAME_URL "url"
#define USER_NODE_NAME_PROFILE_IMAGEURL "profile_image_url"
#define USER_NODE_NAME_DOMAIN "domain"
#define USER_NODE_NAME_GENDER "gender"
#define USER_NODE_NAME_FOLLOWERS_COUNT "followers_count"
#define USER_NODE_NAME_STATUSES_COUNT "statuses_count"
#define USER_NODE_NAME_FAVOURITES_COUNT "favourites_count"
#define USER_NODE_NAME_CREATE_AT "create_at"
#define USER_NODE_NAME_FOLLOWING "following"
#define USER_NODE_NAME_VERIFIED "verified"
#define USER_NODE_NAME_STATUS "status"


class SinaUser:public User
{
public:
	SinaUser();
	void loadFromXml(QDomNode node);
	void loadListFromXml(QDomDocument docXml, list<User*>& lsUser);
	void setStatus(Status* status);
	Status* getStatus();

private:
	Status* status;
};

#endif /* SINAUSER_H_ */
