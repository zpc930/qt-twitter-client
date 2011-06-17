QT             += core gui webkit network xml
HEADERS += \
    UI/mainwindow.h 

SOURCES += \
    UI/mainwindow.cpp \
    UI/QtWeibo.cpp

FORMS += \
    UI/mainwindow.ui
 
RESOURCES += \
    UI/Resources.qrc

unix:release {
        DESTDIR = release/linux
}
