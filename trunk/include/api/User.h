/*
 * User.h
 *
 *  Created on: Jun 16, 2011
 *      Author: Eric
 */
/*
    * id: 用户UID
    * screen_name: 微博昵称
    * name: 友好显示名称，如Bill Gates(此特性暂不支持)
    * province: 省份编码（参考省份编码表）
    * city: 城市编码（参考城市编码表）
    * location：地址
    * description: 个人描述
    * url: 用户博客地址
    * profile_image_url: 自定义图像
    * domain: 用户个性化URL
    * gender: 性别,m--男，f--女,n--未知
    * followers_count: 粉丝数
    * friends_count: 关注数
    * statuses_count: 微博数
    * favourites_count: 收藏数
    * created_at: 创建时间
    * following: 是否已关注(此特性暂不支持)
    * verified: 加V标示，是否微博认证用户
*/


#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include <string.h>
#include <http/Response.h>
#include <api/ApiGlobal.h>
#include <list>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <QtCore/QDateTime>
#include <api/Status.h>

enum User_Gender{
	GENDER_MALE,
	GENDER_FEMALE,
	GENDER_UNKNOWN
};

class User
{
public:
    //User();
    QString getId();
    void setId(QString id);
    QString getScreen_name();
    void setScreen_name(QString screen_name);
    QString getName();
    void setName(QString name);
    int getProvince();
    void setProvince(int province);
    int getCity();
    void setCity(int city);
    QString getLocation();
    void setLocation(QString location);
    QString getDescription();
    void setDescription(QString description);
    QString getUrl();
    void setUrl(QString url);
    QString getProfile_image_url();
    void setProfile_image_url(QString profile_image_url);
    QString getDomain();
    void setDomain(QString domain);
    User_Gender getGender();
    void setGender(User_Gender gender);
    int getFollowers_count();
    void setFollowers_count(int followers_count);
    int getStatuses_count();
    void setStatuses_count(int statuses_count);
    int getFavourites_count();
    void setFavourites_count(int favourites_count);
    QDateTime getCreate_at();
    void setCreate_at(QDateTime create_at);
    bool getFollowing();
    void setFollowing(bool following);
    bool getVerified();
    void setVerified(bool verified);

//    virtual void loadFromXml(QDomNode node) = 0;
//    virtual void loadListFromXml(QDomDocument docXml, list<User*>& lsUser) = 0;

private:
    QString id;
    QString screen_name;
    QString name;
    int province;
    int city;
    QString location;
    QString description;
    QString url;
    QString profile_image_url;
    QString domain;
    User_Gender gender;
    int followers_count;
    int statuses_count;
    int favourites_count;
    QDateTime create_at;
    bool following;
    bool verified;
};


#endif /* USER_H_ */
