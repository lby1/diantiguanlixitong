#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "basewindow.h"
#include "mainwindow1.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    initial();
}

Login::~Login()
{
    delete ui;
}

void Login::initial()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(replyLOGIN(QNetworkReply *)));
    //回车登录
    connect(ui->l_password,SIGNAL(returnPressed()),this,SLOT(on_log_in_clicked()));
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框
    //登陆窗口大小固定
    this->setFixedSize(400,250);
    //全局变量
    //this->setMouseTracking(true);
    ui->label->setText("");
    QHash<QString,QString> usermap;
    //globalvar::userInfo = usermap;

    QRegExp rx("[a-zA-Z0-9][a-zA-Z0-9.-]+$");/*限制第一位只能输a-zA-Z0-9，之后只能输入a-zA-Z0-9.-这几类字符*/

    QValidator *vali=new QRegExpValidator(rx,ui->l_password);
    ui->l_password->setValidator(vali);
    ui->l_password->setMaxLength(12);//限制输入长度,最大为128
}

void Login::on_toolButton_4_clicked()
{
    this->showMinimized();
}

void Login::on_toolButton_3_clicked()
{
    this->close();
}

void Login::on_log_in_clicked()
{
    ui->label->setText("登陆中···");
    QJsonObject json;
    json.insert("userName", ui->l_username->text());
    json.insert("passWord", ui->l_password->text());
    json.insert("memberType","7");
    QJsonDocument docu;
    docu.setObject(json);
    QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
    //QString json_str(byte_array);
    QNetworkRequest req;
    req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/app/AppLogin/login"));
    //发送用户数据到服务器
    QNetworkReply *pReply=manager->post(req,byte_array);
    QReplyTimeout *pTimeout = new QReplyTimeout(pReply, 10000);
    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
        ui->label->setText("网络超时！");
    });
}

void Login::replyLOGIN(QNetworkReply *rep)
{
    if(rep->error()==QNetworkReply::NoError)
    {
        QByteArray a =rep->readAll();
        QJsonParseError jsonError;
        QJsonDocument json = QJsonDocument::fromJson(a, &jsonError);
        if(jsonError.error == QJsonParseError::NoError)//
        {
            if(json.isObject())
            {

                QJsonObject obj = json.object();
                int code =obj.take("code").toInt();
                if(code==1)
                {
                    //QMessageBox::information(0,tr("提示"),tr("成功"));
                    globalvar::userInfo.insert("userId",obj.take("userId").toString());
                    globalvar::userInfo.insert("userName",obj.take("userName").toString());
                    globalvar::userInfo.insert("memberType",obj.take("memberType").toString());
                    MainWindow1 *w=new MainWindow1;
                    w->show();
                }else
                {

                }
            }
        }
    }
}

void Login::mousePressEvent(QMouseEvent *e)
{
    previousPos=e->pos();
}

void Login::mouseMoveEvent(QMouseEvent *e)
{
    if(e->y()<=100)
    {

     this->move(this->pos().x()+e->pos().x()-previousPos.x(),this->pos().y()+e->pos().y()-previousPos.y());

    }
}
