#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oauth.h>
#include <iostream>
#include <include/oauth/OauthHelper.h>
#include <include/api/sina/SinaParam.h>
#include <include/api/sina/SinaApi.h>
#include <include/api/sina/SinaParam.h>
#include <include/api/sina/SinaApiProvider.h>
#include <include/api/ApiGlobal.h>


namespace Ui {
    class MainWindow;
}

/*! \class MainWindow
 * \brief 显示主窗口
 *
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();
    ~MainWindow();


public slots:
    void myWeiboPageButtonClicked();
    void preHtml();

    
private:
    void setWebviewHtml(QString html);
    list<Status*> lsStatus;
    Ui::MainWindow *ui;
    QString basicHtml;
    QString homePageHtml;
    QString atMePageHtml;
    QString myWeiboPageHtml;
    QString favoritePageHtml;
    QString commentPageHtml;
    QString directMessagePageHtml;
    QString contentFrame;
    bool homePageHtmlReady;
    bool homePageStatusReady;
    bool atMePageHtmlReady;
    bool atMePageStatusReady;
    bool myWeiboPageHtmlReady;
    bool myWeiboPageStatusReady;
    bool favoritePageHtmlReady;
    bool favoritePageStatusReady;
    bool commentPageHtmlReady;
    bool commentPageStatusReady;
    bool directMessagePageHtmlReady;
    bool directMessagePageStatusReady;
    int statusUnread;
    int commentsUnread;
    int directMessageUnread;
    int newFollower;
    int atMeMentionsUnread;

    string url;
    string pin;
    class OauthHelper * oauth;
    class SinaApiProvider * sina;
    int ret;

protected:

};

#endif // MAINWINDOW_H