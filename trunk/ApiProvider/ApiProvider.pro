#-------------------------------------------------
#
# Project created by QtCreator 2011-05-31T00:24:57
#
#-------------------------------------------------

QT       += xml

QT       -= gui

TARGET = ApiProvider
TEMPLATE = lib

DEFINES += APIPROVIDER_LIBRARY

SOURCES += \
    SinaApi.cpp \
    param/count.cpp \
    param/source.cpp \
    SinaApiProvider.cpp \
    SinaParam.cpp \
    api/Statuses/friends_timeline.cpp \
    api/Users/Show.cpp \
    param/page.cpp

HEADERS +=\
    include/APiProvider/SinaParam.h \
    include/APiProvider/SinaApiProvider.h \
    include/APiProvider/ApiProvider_global.h \
    include/APiProvider/apiprovider.h \
    include/ApiProvider/SinaParam.h \
    include/ApiProvider/SinaApiProvider.h \
    include/ApiProvider/ApiProvider_global.h \
    include/ApiProvider/apiprovider.h \
    include/ApiProvider/SinaApi.h

OTHER_FILES +=
