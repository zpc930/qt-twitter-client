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
#include <fstream>
#include <oauth/OauthHelper.h>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApi.h>
#include <api/sina/SinaParam.h>
#include <api/sina/SinaApiProvider.h>
#include <api/ApiGlobal.h>
#include <factory/ManagerFactory.h>

MainWindow::MainWindow() :
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ret=0;
    ifstream fin;
    ofstream fout;
    string AccessToken, AccessSecret, Verifier, UserId;

    sina = ManagerFactory::getInstance()->getProvider(PROVIDER_SINA);

    /* 从文件读取登录信息，如果存在，则无需再登录，否则登录，并保存登录状态文件 */
    fin.open("login.data", ios::in);
    fin>>AccessToken
        >>AccessSecret
        >>Verifier
        >>UserId;
    fin.close();
    cout<<AccessToken<<" "<<AccessSecret<<" "<<Verifier<<" "<<UserId<<endl;
    if (AccessToken == "" || AccessSecret == "" || Verifier == "" || UserId == "") {
        ret = sina->OauthStep1(&url);
        cout << "LoginStep 1 result:" << ret << "\nUrl:" << url << endl;
        cout << "Please Enter Pin code :";
        getline(cin, pin);
        ret = sina->OauthStep2(pin);
        cout << "LoginStep 2 result:" << ret << endl;

        /* 将登录信息导出到文件 */
        sina->ExportLoginData(&AccessToken, &AccessSecret, &Verifier, &UserId);
        fout.open("login.data", ios::out);
        fout<<AccessToken<<" "<<AccessSecret<<" "<<Verifier<<" "<<UserId<<endl;
        fout.close();
    }
    else {
        sina->RevertLoginStatus(AccessToken, AccessSecret, Verifier, UserId);
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
        QString statusHtml="<p><div style='font-weight:bold;font-size:14px;background-color:#B1D0D9'>%1 说：</div>"\
            "<div style='font-weight:normal;font-size:12px'>%2</div></p>";
        QString tmp;
        for (list<Status*>::iterator status = lsStatus.begin(); status != lsStatus.end(); status++) {
            tmp.append(statusHtml
                    .arg((*status)->getUser()->getName())
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


