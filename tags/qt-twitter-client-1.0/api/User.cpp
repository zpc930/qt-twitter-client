/*
 * User.cpp
 *
 *  Created on: Jun 17, 2011
 *      Author: Eric
 */
#include "api/User.h"

QString User::getId()
{
	return id;
}



void User::setId(QString id)
{
	this->id=id;
}



QString User::getScreen_name()
{
	return screen_name;
}



void User::setScreen_name(QString screen_name)
{
	this->screen_name=screen_name;
}



QString User::getName()
{
	return name;
}



void User::setName(QString name)
{
	this->name=name;
}



int User::getProvince()
{
	return province;
}



void User::setProvince(int province)
{
	this->province=province;
}



int User::getCity()
{
	return city;
}



void User::setCity(int city)
{
	this->city=city;
}



QString User::getLocation()
{
	return location;
}



void User::setLocation(QString location)
{
	this->location=location;
}



QString User::getDescription()
{
	return description;
}



void User::setDescription(QString description)
{
	this->description=description;
}



QString User::getUrl()
{
	return url;
}



void User::setUrl(QString url)
{
	this->url=url;
}



QString User::getProfile_image_url()
{
	return profile_image_url;
}



void User::setProfile_image_url(QString profile_image_url)
{
	this->profile_image_url=profile_image_url;
}



QString User::getDomain()
{
	return domain;
}



void User::setDomain(QString domain)
{
	this->domain=domain;
}



User_Gender User::getGender()
{
	return gender;
}



void User::setGender(User_Gender gender)
{
	this->gender=gender;
}



int User::getFollowers_count()
{
	return followers_count;
}



void User::setFollowers_count(int followers_count)
{
	this->followers_count=followers_count;
}



int User::getStatuses_count()
{
	return statuses_count;
}



void User::setStatuses_count(int statuses_count)
{
	this->statuses_count=statuses_count;
}



int User::getFavourites_count()
{
	return favourites_count;
}



void User::setFavourites_count(int favourites_count)
{
	this->favourites_count=favourites_count;
}



QDateTime User::getCreate_at()
{
	return create_at;
}



void User::setCreate_at(QDateTime create_at)
{
	this->setCreate_at(create_at);
}



bool User::getFollowing()
{
	return following;
}



void User::setFollowing(bool following)
{
	this->following=following;
}



bool User::getVerified()
{
	return verified;
}



void User::setVerified(bool verified)
{
	this->verified=verified;
}

