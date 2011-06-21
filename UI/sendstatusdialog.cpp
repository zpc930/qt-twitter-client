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

SendStatusDialog::SendStatusDialog(Send_Category category,int user_id,int comment_id):
    ui(new Ui::SendStatusDialog)
{
    this->diadialogType=category;
    this->userId=user_id;
    this->commentId=comment_id;

    ui->setupUi(this);
    this->wordsLimit=140;
    this->setWindowTitle(tr("发表新微博"));
    QObject::connect(ui->pushButton_SendStatus,SIGNAL(clicked()), this, SLOT(sendButtonClicked()));

}

SendStatusDialog::SendStatusDialog(Send_Category category,int user_id,Status st):
        ui(new Ui::SendStatusDialog)
{
    this->diadialogType=category;
    this->userId=user_id;
    this->st=new Status(st);
    ui->setupUi(this);
    this->wordsLimit=140;
    this->setWindowTitle(tr("发表新微博"));
    QObject::connect(ui->pushButton_SendStatus,SIGNAL(clicked()), this, SLOT(sendButtonClicked()));

}

SendStatusDialog::~SendStatusDialog()
{
    delete ui;
    qDebug(" deleted !");
}

void SendStatusDialog::sendButtonClicked()
{
    ui->pushButton_SendStatus->setEnabled(false);
    ui->pushButton_SendStatus->setText("发表中...");
    qDebug("dialog type is %d", dialogType);

    if(dialogType==)
    {
        sendStatus(ui->textEdit_statusContent->document()->toPlainText());
    }
    else if(dialogType==)
       repost(id, ui->textEdit_statusContent->document()->toPlainText());
    else if(dialogType==)
        commentStatus(id, ui->textEdit_statusContent->document()->toPlainText());
    else if(dialogType==)
        this->replyComment(cid, id, ui->textEdit_statusContent->document()->toPlainText());
    else if(dialogType==)
        this->sendDirectMessage(id, ui->textEdit_statusContent->document()->toPlainText());
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


void SendStatusDialog::setText(QString text)
{
    ui->textEdit_statusContent->append(text);
}
