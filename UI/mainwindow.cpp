#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QtWebKit>
#include <QtGui>

MainWindow::MainWindow() :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->webView_Main->setPage(new QWebPage(this));
    this->timer = new QTimer(this);// timer

    ui->toolButton_Friends->setText(tr("��ע�� %1").arg(100));
    ui->toolButton_Follower->setText(tr("��˿�� %1").arg(100));
    ui->toolButton_WeiboCount->setText(tr("΢���� %1").arg(100));
    ui->toolButton_UserName->setText(tr("GoDefine"));
    

    QFile basicHtmlFile(":/res/homepage.html");
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

