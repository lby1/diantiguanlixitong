#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include "qreplytimeout.h"
#include <QMouseEvent>
#include "globalvar.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void initial();

private slots:
    void on_toolButton_4_clicked();

    void on_toolButton_3_clicked();

    void on_log_in_clicked();
    void replyLOGIN(QNetworkReply*);

private:
    Ui::Login *ui;
    QNetworkAccessManager* manager;
    QPoint previousPos;
protected:
    void mousePressEvent(QMouseEvent*e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // LOGIN_H
