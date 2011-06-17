#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

namespace Ui {
    class MainWindow;
}

/*! \class MainWindow
 * \brief Ö÷´°¿Ú
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

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QString basicHtml;
    QString homePageHtml;
    QString atMePageHtml;
    QString myWeiboPageHtml;
    QString favoritePageHtml;
    QString commentPageHtml;
    QString directMessagePageHtml;
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
    
private:
    void setWebviewHtml(QString html);
protected:

};

#endif // MAINWINDOW_H
