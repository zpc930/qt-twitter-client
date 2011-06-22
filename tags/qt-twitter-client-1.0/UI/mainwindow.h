#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QtCore/QUrl>
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
#include <qtimer.h>
#include "sendstatusdialog.h"

namespace Ui {
    class MainWindow;
}
/*当前所在页面枚举类型*/
enum Current_Position{
	HOMEPAGE,
	MYWEIBOPAGE,
	MENTIONMEPAGE,
	COMMENTPAGE
};

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
    void showHomePage();

public slots:
    void newWeiboButtonClicked();
    void myWeiboPageButtonClicked();
    void homePageButtonClicked();
    void mentionMePageButtonClicked();
    void commentPageButtonClicked();
    void linkButtonClicked(QUrl url);
    void preHtml();
    void timeHere();

    
private:
    void setWebviewHtml(QString html);
    list<Status*> lsStatus;
    list<Comment*> lsComment;
    Ui::MainWindow *ui;
    QString statusHtml;
    QString basicHtml;
    QString homePageHtml;
    QString atMePageHtml;
    QString myWeiboPageHtml;
    QString favoritePageHtml;
    QString commentPageHtml;
    QString directMessagePageHtml;
    QString contentFrame;
    int statusUnread;
    int commentsUnread;
    int directMessageUnread;
    int newFollower;
    int atMeMentionsUnread;

    string url;
    string pin;
    MiniBlogProvider * sina;
    User *currentUser;
    int ret;

    /*定时器，控制定时刷新当前所在页面*/
    QTimer * mainTimer;
    /*记录当前所在页面，与定时器配合使用*/
    enum Current_Position currentposition;
    int refreshGap;



protected:

};

#endif // MAINWINDOW_H
