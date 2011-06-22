/*
 * SuggestionsUser.cpp
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
#define PARA_NAME_WITH_REASON "with_reason"

using namespace std;

list<User*> SinaApiProvider::getSuggestionsUser(bool with_reason)
{
	list<User*> lsUser;
	Response response;
	PostParameter para;
	string queryUrl;
	QList<PostParameter*> paras;
	SinaUser user;
	/* add parameter: category */
	paras.append(new PostParameter(PARA_NAME_WITH_REASON, (with_reason?1:0)));
	SinaApi *api = new SinaApi(FAMILY_NAME, "suggestions", HTTP_METHOD_GET);
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
