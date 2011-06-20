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

static char USER_NODE_NAME_ID[] = "id";
static char USER_NODE_NAME_SCREEN_NAME[] = "screen_name";
static char USER_NODE_NAME_NAME[] = "name";
static char USER_NODE_NAME_PROVINCE[] = "province";
static char USER_NODE_NAME_CITY[] = "city";
static char USER_NODE_NAME_LOCATION[] = "location";
static char USER_NODE_NAME_DESCRIPTION[] = "description";
static char USER_NODE_NAME_URL[] = "url";
static char USER_NODE_NAME_PROFILE_IMAGEURL[] = "profile_image_url";
static char USER_NODE_NAME_DOMAIN[] = "domain";
static char USER_NODE_NAME_GENDER[] = "gender";
static char USER_NODE_NAME_FOLLOWERS_COUNT[] = "followers_count";
static char USER_NODE_NAME_STATUSES_COUNT[] = "statuses_count";
static char USER_NODE_NAME_FAVOURITES_COUNT[] = "favourites_count";
static char USER_NODE_NAME_CREATE_AT[] = "create_at";
static char USER_NODE_NAME_FOLLOWING[] = "following";
static char USER_NODE_NAME_VERIFIED[] = "verified";
static char USER_NODE_NAME_STATUS[] = "status";


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
