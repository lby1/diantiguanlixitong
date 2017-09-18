#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QContextMenuEvent>

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow//
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = 0);
    ~MainWindow1();
    void init();
    void getDevicelist();//获取待审核设备列表
    void getxindanlist();//新单确认列表
private slots:
    void reply(QNetworkReply *);//manager的reply
    void updateModel(qint64,qint64);//下载进度
    void slot_view_device(bool);//查看设备信息

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void onbutton_tongguoclick();//通过按钮的槽

    void onbutton_butongguoclick();//不通过按钮的槽

private:
    Ui::MainWindow1 *ui;
    QNetworkAccessManager*manager;
    QNetworkReply* deviceList_Reply;//待审核设备列表
    QNetworkReply* tijiaodevice_reply;//提交审核
    QNetworkReply* tongguo_reply;//提交审核
    QNetworkReply* butongguo_reply;//提交审核
    QNetworkReply* xindanqueren_reply;//提交审核
    QStandardItemModel*model_deviceList;//未审核设备列表的model
    QStandardItemModel*model_deviceList2;//审核通过设备列表的model
    QStandardItemModel*model_deviceList3;//审核未通过设备列表的model
    QAction* view_device;
    QMenu*pop_menu;
    QList<int> itemlist;//存放所有未审核设备的序号方便查找设备信息
    QList<int> itemlist2;//存放所有审核通过设备的序号方便查找设备信息
    QList<int> itemlist3;//存放所有审核未通过设备的序号方便查找设备信息
private:
    void createActions();//添加菜单选项
    void translateLanguage();//设置菜单中文
    void contextMenuEvent(QContextMenuEvent* e);//右键菜单事件
};

#endif // MAINWINDOW1_H
