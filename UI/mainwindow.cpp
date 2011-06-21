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
    int currentUserId;
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

    // 设置当前用户
    currentUserId = atoi(UserId.c_str());
    this->currentUser = sina->getUser(currentUserId);

    this->ui->webView_Main->setPage(new QWebPage(this));
    //this->timer = new QTimer(this);// timer
    ui->toolButton_UserName->setText(tr("GoDefine"));
    cout<<"UseId"<<currentUserId<<endl;

    ui->toolButton_Friends->setText(tr("微博数 %1").arg(currentUser->getStatuses_count()));
    ui->toolButton_Follower->setText(tr("粉丝数 %1").arg(currentUser->getFollowers_count()));
    ui->toolButton_WeiboCount->setText(tr("收藏数 %1").arg(currentUser->getFavourites_count()));
    ui->toolButton_UserName->setText(currentUser->getScreen_name());
    //ui->toolButton_Logo->setIcon(currentUser->getProfile_image_url());

    ui->webView_Main->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    QObject::connect(ui->toolButton_HomePage, SIGNAL(clicked()), this, SLOT(homePageButtonClicked()) );
    QObject::connect(ui->toolButton_MyWeiboPage, SIGNAL(clicked()), this, SLOT(myWeiboPageButtonClicked()) );
    QObject::connect(ui->toolButton_AtMePage, SIGNAL(clicked()), this, SLOT(mentionMePageButtonClicked()) );
    //QObject::connect(ui->toolButton_configure, SIGNAL(clicked()), this, SLOT(configureButtonClicked()));
    QObject::connect(ui->webView_Main, SIGNAL(linkClicked(QUrl)), this, SLOT(configureButtonClicked(QUrl)));

    QFile basicHtmlFile(":/UI/res/homepage.html");
    if(!basicHtmlFile.open(QFile::ReadOnly))
    {
        qDebug(basicHtmlFile.errorString().toAscii());
    }
    QTextStream stream(&basicHtmlFile);
    basicHtml = stream.readAll();
    basicHtmlFile.close();

    // 初始化status模板HTML
    this->statusHtml="<div style='background-color:#B1D0D9;margin-bottom:3px;'>"\
                        "<div style='font-weight:bold;color:blue;font-size:14px;background-color:#B1D0D9;border-bottom:solid 1px grey'>%1 说：</div>"\
                        "<div style='font-weight:normal;font-family:楷体;font-size:13px;margin:5px 10px 0px 10px;line-height:15px;'>%2</div>"\
                        "<div style='font-weight:normal;font-family:楷体;font-size:13px;margin:5px 10px 0px 10px;text-align:right;'>"\
                        "<a href='comment:%3'>回复</a> <a href='repost:%4'>转发</a>"
                        "</div></div>";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configureButtonClicked(QUrl url)
{
    cout<<"loading"<<endl;
    cout<<url.toString().toStdString()<<endl;
    cout<<"loaded"<<endl;
}

void MainWindow::homePageButtonClicked()
{

    // 清空原有信息
    myWeiboPageHtml.clear();

    // 获取主页微博列表
    lsStatus = sina->getFriendsTimeline();

    QString tmp;
    for (list<Status*>::iterator status = lsStatus.begin(); status != lsStatus.end(); status++) {
        tmp.append(statusHtml
                .arg((*status)->getUser()->getName())
                .arg((*status)->getText())
                .arg((*status)->getId())
                .arg((*status)->getId())
                );
    }
    myWeiboPageHtml.append(tmp.toAscii());
    qDebug("Our return is"+tmp.toAscii());
    myWeiboPageHtml.append( "<a>首页</a>"
            "<a>下一页</a>"
            "");

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

void MainWindow::myWeiboPageButtonClicked()
{

    // 清空原有信息
    myWeiboPageHtml.clear();

    // 获取用户微博列表
    lsStatus = sina->getUserTimeline(currentUser->getId().toInt());

    //QString statusHtml="<div class='status_item'><div class='status_user'>%1 说：</div><div class='status_text'>%2</div></div>";
    QString tmp;
    for (list<Status*>::iterator status = lsStatus.begin(); status != lsStatus.end(); status++) {
        tmp.append(statusHtml
                .arg((*status)->getUser()->getName())
                .arg((*status)->getText())
                .arg((*status)->getId())
                .arg((*status)->getId())
                );
    }
    myWeiboPageHtml.append(tmp.toAscii());
    qDebug("Our return is"+tmp.toAscii());
    myWeiboPageHtml.append( "<a>首页</a>"
            "<a>下一页</a>"
            "");

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

void MainWindow::mentionMePageButtonClicked()
{

    // 清空原有信息
    myWeiboPageHtml.clear();

    // 获取mentions微博列表
    cout<<"Get mentions"<<endl;
    lsStatus = sina->getMentions();

    QString tmp;
    for (list<Status*>::iterator status = lsStatus.begin(); status != lsStatus.end(); status++) {
        tmp.append(statusHtml
                .arg((*status)->getUser()->getName())
                .arg((*status)->getText())
                .arg((*status)->getId())
                .arg((*status)->getId())
                );
    }
    myWeiboPageHtml.append(tmp.toAscii());
    qDebug("Our return is"+tmp.toAscii());
    myWeiboPageHtml.append( "<a>首页</a>"
            "<a>下一页</a>"
            "");
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

