#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QtWebKit>
#include <QtGui>
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

MainWindow::MainWindow() :
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ret=0;
    oauth = new OauthHelper(
            "http://api.t.sina.com.cn",
            "/oauth/request_token",
            "/oauth/authorize",
            "/oauth/access_token",
            "3270683373", "74eeee59407de92f1e6394157f090a36");

    sina = new SinaApiProvider(oauth);
    ret = oauth->LoginStep1(&url);
    cout << "LoginStep 1 result:" << ret << "\nUrl:" << url << endl;
    cout << "Please Enter Pin code :";
    getline(cin, pin);
    ret = oauth->LoginStep2(pin);
    cout << "LoginStep 2 result:" << ret << endl;
    list<Status*> lsStatus = sina->getFriendsTimeline();

    for (list<Status*>::iterator s = lsStatus.begin(); s != lsStatus.end(); s++) {
        cout<<(*s)->getId()<<"\t"<<(*s)->getText()<<endl;
    }

    this->ui->webView_Main->setPage(new QWebPage(this));
    //this->timer = new QTimer(this);// timer
    ui->toolButton_Friends->setText(tr("关注数 %1").arg(100).toAscii());
    ui->toolButton_Follower->setText(tr("鲜花 %1").arg(100).toAscii());
    ui->toolButton_WeiboCount->setText(tr("微博数 %1").arg(100).toAscii());
    ui->toolButton_UserName->setText(tr("GoDefine"));

    this->myWeiboPageHtmlReady = false;
    this->myWeiboPageStatusReady = false;
    
    QObject::connect( ui->toolButton_MyWeiboPage, SIGNAL(clicked()), this, SLOT(myWeiboPageButtonClicked()) );

    QFile basicHtmlFile(":/UI/res/homepage.html");
    if(!basicHtmlFile.open(QFile::ReadOnly))
    {
        qDebug(basicHtmlFile.errorString().toAscii());
    }
    QTextStream stream(&basicHtmlFile);
    basicHtml = stream.readAll();
    basicHtmlFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myWeiboPageButtonClicked()
{
    this->preHtml();
    if(!myWeiboPageHtmlReady)
    {

        if(!myWeiboPageStatusReady)
        {
            lsStatus = sina->getFriendsTimeline();
            myWeiboPageStatusReady=true;
        }
        QString statusHtml="<p><a>%1</a><a>%2</a></p>";
        QString tmp;
        for (list<Status*>::iterator status = lsStatus.begin(); status != lsStatus.end(); status++) {
            tmp.append(statusHtml
                       .arg(tr("Jason:"))
                       .arg((*status)->getText())
                       );
        }
        myWeiboPageHtml.append(tmp.toAscii());
        qDebug("Our return is"+tmp.toAscii());
        myWeiboPageHtml.append( "<a>Ê×Ò³</a>"
                                "<a>ÏÂÒ»Ò³</a>"
                                "");
    }
     ui->webView_Main->setHtml(myWeiboPageHtml);
    //this->setWebviewHtml(myWeiboPageHtml);
//    QString countsInJsonFormat = sina->getStatusCountsByJson(account->userWeiboPageStatus);
//    while(!dealWebkitEvent->isDomReady())
//    {
//        QApplication::processEvents();
//    }
//    dealWebkitEvent->sendStatusesCounts(countsInJsonFormat);
//    delete sina;
}

void MainWindow::preHtml()
{
    ui->webView_Main->setHtml("<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />"
                                            "<center><img src=qrc:/toolButton/images/loading.gif /></center>");
    QObject::disconnect(ui->webView_Main->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                        this, SLOT(addJavaScriptObject()));
}


