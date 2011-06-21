 /***************************************************************************
 *   Copyright (C) 2010 by ZhangShine , All Rights Reserved                                  
 *   zhangshine0125@gmail.com                                              
 *                                                                         
 *   This program is free software; you can redistribute it and/or modify  
 *   it under the terms of the GNU General Public License as published by  
 *   the Free Software Foundation; either version 2 of the License, or     
 *   (at your option) any later version.                                   
 *                                                                         
 *   This program is distributed in the hope that it will be useful,       
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
 *   GNU General Public License for more details.                          
 *                                                                         
 *   You should have received a copy of the GNU General Public License     
 *   along with this program; if not, write to the                         
 *   Free Software Foundation, Inc.,                                       
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             
 ***************************************************************************/

#include "sendstatusdialog.h"
#include "ui_sendstatusdialog.h"
#include <QTextCursor>
#include <QFileDialog>
#include <QtWebKit>
#include <QMessageBox>

char* sendCategoryStr[CATEGORY_MAX] = {
    "",
    "发布新微博",
    "发布评论",
    "回复评论",
    "转发微博",
    "发私信"
    };

SendStatusDialog::SendStatusDialog(Send_Category category, QString statusId, QString commentId, int userId):
        ui(new Ui::SendStatusDialog)
{
    this->dialogType = category;
    this->userId = userId;
    this->statusId = statusId;
    this->commentId = commentId;
    ui->setupUi(this);
    this->wordsLimit = 140;
    this->setWindowTitle(tr(sendCategoryStr[category]));
    QObject::connect(ui->pushButton_SendStatus, SIGNAL(clicked()), this, SLOT(sendButtonClicked()));
    qDebug("type:%d, userId:%d, status:%s, comment:%s",
           category, userId, statusId.toStdString().c_str(), commentId.toStdString().c_str());
}

SendStatusDialog::~SendStatusDialog()
{
    delete ui;
    qDebug(" deleted !");
}

void SendStatusDialog::sendButtonClicked()
{
    MiniBlogProvider* provider = ManagerFactory::getInstance()->getProvider(PROVIDER_SINA);
    Status* status;
    Comment* comment;
    int ret = 0;
    ui->pushButton_SendStatus->setEnabled(false);
    ui->pushButton_SendStatus->setText("发表中...");
    qDebug("content is %s",ui->textEdit_statusContent->toPlainText().toStdString().c_str());
    switch(this->dialogType) {
        case STATUS:
            status = new Status(ui->textEdit_statusContent->toPlainText().toStdString().c_str());
            ret = provider->updateStatus(*status);
            delete status;
            break;
        case COMMENT:
        case COMMENT_REPLY:
            qDebug("comment id is %s", this->commentId.toStdString().c_str());
            comment = new Comment(ui->textEdit_statusContent->toPlainText().toStdString().c_str(), this->statusId, this->commentId);
            ret = provider->updateComment(*comment);
            delete comment;
            break;
        case REPOST:
            status = new Status(ui->textEdit_statusContent->toPlainText().toStdString().c_str());
            status->setInReplyInfo(this->statusId.toStdString().c_str(), 0, "");
            ret = provider->updateStatus(*status);
            delete status;
            break;
        default:
            break;
    }
    if (ret == 0) {
        ui->pushButton_SendStatus->setText("发表成功!");
    }
    close();
}


void SendStatusDialog::wordsCount()
{
    QString content = ui->textEdit_statusContent->document()->toPlainText();
    int length = content.length();
    if(length>0&&length<=wordsLimit)
        ui->pushButton_SendStatus->setEnabled(true);
    else
        ui->pushButton_SendStatus->setEnabled(false);
    ui->label_wordsCount->setText(QString::number(wordsLimit - content.length()));
}
