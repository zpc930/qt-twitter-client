/*
 * HotUser.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: Eric
 */

#include <api/sina/SinaApiProvider.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <QtXml/QDomDocument>
#include <http/PostParameter.h>
#include <http/Response.h>
#include <list>

#define FAMILY_NAME "users"
#define PARA_NAME_CATEGORY "category"

using namespace std;

list<User*> SinaApiProvider::getHotUser(enum User_Category_Key category_Key)
{
	list<User*> lsUser;
	Response response;
	PostParameter para;
	string queryUrl;
	QList<PostParameter*> paras;
	SinaUser user;
	/* add parameter: category */
	//paras.append(new PostParameter(PARA_NAME_CATEGORY, SinaUser::Sina_User_Category[category_Index]->toStdString().c_str()));
	paras.append(new PostParameter(PARA_NAME_CATEGORY, (*(SinaUser::Sina_User_Category_Map))[category_Key]->toStdString().c_str()));
	SinaApi *api = new SinaApi(FAMILY_NAME, "hot", HTTP_METHOD_GET);
	queryUrl = api->toString(paras);
#if API_PROVIDER_DEBUG
	cout << "query url:" <<queryUrl<<endl;
#endif
	this->oauth->Request(queryUrl, HTTP_METHOD_GET, &response);
#if API_PROVIDER_DEBUG
	    cout << "result :" <<response.responseAsDocument()->toString().toStdString()<<endl;
#endif
    if (response.responseAsDocument()->elementsByTagName(NODE_USER_ROOT).count() != 0) {
        user.loadListFromXml(*response.responseAsDocument(), lsUser);
    }
    para.releaseParas(paras);
    return lsUser;
}

