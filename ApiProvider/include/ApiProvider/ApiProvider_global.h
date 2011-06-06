#ifndef APIPROVIDER_GLOBAL_H
#define APIPROVIDER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(APIPROVIDER_LIBRARY)
#  define APIPROVIDERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define APIPROVIDERSHARED_EXPORT Q_DECL_IMPORT
#endif

#define OK 0
#define FAIL 1

#define NUM_TO_BIT(id)          (1 << (id))
#define BITMAP_SET(map, id)     ((map) |= NUM_TO_BIT(id))
#define BITMAP_TEST(map, id)    ((map) & NUM_TO_BIT(id))
#define BITMAP_CLEAN(map, id)   ((map) &= ~(NUM_TO_BIT(id)))

#define SINA_DEFAULT_APP_KEY "3270683373"
#define SINA_DEFAULT_APP_SECRET "74eeee59407de92f1e6394157f090a36"

#define API_PROVIDER_DEBUG 1

#ifdef API_PROVIDER_DEBUG
#include <iostream>
#endif

#endif // APIPROVIDER_GLOBAL_H
