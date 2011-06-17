#include <factory/ManagerFactory.h>

ManagerFactory* ManagerFactory::instance = NULL;

/* constructors */
ManagerFactory::ManagerFactory()
{
    lsProvider[PROVIDER_SINA] = new SinaApiProvider(
            new OauthHelper(
                "http://api.t.sina.com.cn",
                "/oauth/request_token",
                "/oauth/authorize",
                "/oauth/access_token",
                "3270683373", "74eeee59407de92f1e6394157f090a36"));
}

/* Singleton */
ManagerFactory* ManagerFactory::getInstance()
{
    if (instance == NULL) {
        instance = new ManagerFactory();
    }
    return instance;
}

/* getter */
MiniBlogProvider* ManagerFactory::getProvider(e_provider_t provider)
{
    return this->lsProvider[PROVIDER_SINA];
}
