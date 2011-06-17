/*
 * PROVIDERFactory类，定义了微博类工厂的字段和方法
 * 作者：吕进
 * 日期：2011-06-14
 */

#ifndef __PROVIDER_FACTORY_H__
#define __PROVIDER_FACTORY_H__
#include <api/ApiProvider.h>
#include <api/sina/SinaApiProvider.h>

typedef enum e_provider
{
    PROVIDER_SINA,
    PROVIDER_MAX
} e_provider_t;

class ManagerFactory
{
private:
    ManagerFactory();
    static ManagerFactory* instance;
    MiniBlogProvider* lsProvider[PROVIDER_MAX];
public:
    static ManagerFactory* getInstance();
    MiniBlogProvider* getProvider(e_provider_t provider);
};

#endif //__PROVIDER_FACTORY_H__
