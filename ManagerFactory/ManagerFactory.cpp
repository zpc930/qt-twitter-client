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
                "1596803225", "7bc29cb2aa9c02958cae028d26f83902"));
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
