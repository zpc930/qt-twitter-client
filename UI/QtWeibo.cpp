#include <QApplication>
#include <QtGui>
#include <QTextCodec>
#include <QtCore>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication weibo(argc, argv);
    QApplication::setOrganizationName("GoDefine");
    QApplication::setApplicationName("QtWeibo");
    QApplication::setOrganizationDomain("GoDefine");

    /* Set Software Encoding */
    QTextCodec *encoding = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForTr(encoding);
    QTextCodec::setCodecForLocale(encoding);
    QTextCodec::setCodecForCStrings(encoding);
    QApplication::setQuitOnLastWindowClosed(true);
    MainWindow w;
    w.show();
    return weibo.exec();
}
