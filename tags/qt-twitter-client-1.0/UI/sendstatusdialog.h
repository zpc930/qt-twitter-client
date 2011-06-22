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

#ifndef SENDSTATUSDIALOG_H
#define SENDSTATUSDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oauth.h>
#include <iostream>
#include <oauth/OauthHelper.h>
#include <api/ApiGlobal.h>
#include <api/ApiProvider.h>
#include <factory/ManagerFactory.h>

//发表新微博～回复微博～回复评论～回复状态
enum Send_Category{
    STATUS=1,
    COMMENT,
    COMMENT_REPLY,
    REPOST,
    DIRECT_MESSAGE,
    CATEGORY_MAX
};

namespace Ui {
    class SendStatusDialog;
}

/*! \class SendStatusDialog
 * \brief 发送微博
 *
 */
class SendStatusDialog : public QDialog
{
    Q_OBJECT

public:
    SendStatusDialog(Send_Category category, QString statusId, QString commentId, int userId);
    ~SendStatusDialog();
    
public slots:
    void sendButtonClicked();
    void wordsCount();

signals:
    
private:
    Ui::SendStatusDialog *ui;
    int wordsLimit; //字数限制
    Send_Category dialogType;   //发送类型
    int userId;     //用户ID
    QString statusId;  //微博ID号
    QString commentId;  //评论ID号
};

#endif // SENDSTATUSDIALOG_H
