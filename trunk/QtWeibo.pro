QT             += core gui webkit network xml
HEADERS += \
    UI/mainwindow.h \
    include/oauth/OauthHelper.h \
    include/api/User.h \
    include/api/Status.h \
    include/api/Comment.h \
    include/api/ApiProvider.h \
    include/api/ApiGlobal.h \
    include/api/sina/SinaStatus.h \
    include/api/sina/SinaParam.h \
    include/api/sina/SinaComment.h \
    include/api/sina/SinaApiProvider.h \
    include/api/sina/SinaApi.h \
    include/factory/ManagerFactory.h

INCLUDEPATH += include


LIBS += \
    -L/usr/local/lib \
    -L/trunk/lib \
    -Llib \
    -lQtXml \
    -lQtNetwork \
    -lQtCore \
    -loauth \
    -lOauthHelper \
    -lSinaApiProvider \
    -lApiProvider \
    -lhttphelper \
    -lManagerFactory


SOURCES += \
    UI/mainwindow.cpp \
    UI/QtWeibo.cpp


FORMS += \
    UI/mainwindow.ui \
    UI/sendstatusdialog.ui

RESOURCES += \
    UI/Resources.qrc

unix:release {
        DESTDIR = release/linux
}
