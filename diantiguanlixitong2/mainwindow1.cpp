#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "globalvar.h"
#include "qreplytimeout.h"
#include "deviceinfo.h"
#include "itemdelegateforcol.h"
#include "remark.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    init();
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::init()
{
    QFile file("c:/Users/hp/desktop/chuibai.QSS");
     file.open(QIODevice::ReadOnly);
     QString s=file.readAll();
     file.close();
     //this->setStyleSheet(s);
//    this->setWindowFlags(Qt::FramelessWindowHint);
//    MyTitleBar* m_titleBar;
//    m_titleBar = new MyTitleBar(this);
//    m_titleBar->move(0, 0);
//    m_titleBar->setTitleContent("电梯管理系统");
//    m_titleBar->setTitleIcon("C:/Users/hp/Desktop/170823140829.png");

    manager=new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply *)));
    //获取所有设备列表
    getDevicelist(1);
    getDevicelist(2);
    getDevicelist(3);
    //同步获取待审核设备列表
//    QEventLoop loop;
//    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
//    loop.exec();
    model_deviceList=new QStandardItemModel();
    model_deviceList->setColumnCount(2);
    model_deviceList2=new QStandardItemModel();
    model_deviceList3=new QStandardItemModel();
    ui->tableview_daishen->setModel(model_deviceList);
    ui->listView->setModel(model_deviceList2);
    ui->listView_2->setModel(model_deviceList3);
    ui->tableview_daishen->horizontalHeader()->setVisible(false);
    //ui->tableview_tongguo->horizontalHeader()->setVisible(false);
    //ui->tableview_weitongguo->horizontalHeader()->setVisible(false);
    ui->tableview_daishen->verticalHeader()->setVisible(false);
    //ui->tableview_tongguo->verticalHeader()->setVisible(false);
    //ui->tableview_weitongguo->verticalHeader()->setVisible(false);

}

void MainWindow1::getDevicelist(int status)
{
    switch (status) {
    case 1:
    {
        QJsonObject json;
        json.insert("userId",globalvar::userInfo.value("userId"));
        json.insert("deviceStatus", QString::number(status));
        json.insert("deviceCompany", "");
        json.insert("deviceNumber", "");
        QJsonDocument docu;
        docu.setObject(json);
        QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
        //QString json_str(byte_array);
        QNetworkRequest req;
        req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/deviceList"));
        //发送用户数据到服务器
        deviceList_Reply=manager->post(req,byte_array);
        QReplyTimeout *pTimeout = new QReplyTimeout(deviceList_Reply, 10000);
        connect(pTimeout, &QReplyTimeout::timeout, [=]() {
            ui->statusbar->showMessage("网络超时！",10000);
        });
    }
    case 2:
    {
        QJsonObject json;
        json.insert("userId",globalvar::userInfo.value("userId"));
        json.insert("deviceStatus", QString::number(status));
        json.insert("deviceCompany", "");
        json.insert("deviceNumber", "");
        QJsonDocument docu;
        docu.setObject(json);
        QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
        //QString json_str(byte_array);
        QNetworkRequest req;
        req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/deviceList"));
        //发送用户数据到服务器
        tongguoList_Reply=manager->post(req,byte_array);
        QReplyTimeout *pTimeout = new QReplyTimeout(tongguoList_Reply, 10000);
        connect(pTimeout, &QReplyTimeout::timeout, [=]() {
            ui->statusbar->showMessage("网络超时！",10000);
        });
    }
    case 3:
    {
        QJsonObject json;
        json.insert("userId",globalvar::userInfo.value("userId"));
        json.insert("deviceStatus", QString::number(status));
        json.insert("deviceCompany", "");
        json.insert("deviceNumber", "");
        QJsonDocument docu;
        docu.setObject(json);
        QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
        //QString json_str(byte_array);
        QNetworkRequest req;
        req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/deviceList"));
        //发送用户数据到服务器
        weitongguoList_Reply=manager->post(req,byte_array);
        QReplyTimeout *pTimeout = new QReplyTimeout(weitongguoList_Reply, 10000);
        connect(pTimeout, &QReplyTimeout::timeout, [=]() {
            ui->statusbar->showMessage("网络超时！",10000);
        });
    }
        break;
    default:
        break;
    }
}

void MainWindow1::getxindanlist()
{
    QJsonObject json;
    json.insert("userId",globalvar::userInfo.value("userId"));
    json.insert("deviceCompany", "");
    json.insert("deviceNumber", "");
    QJsonDocument docu;
    docu.setObject(json);
    QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
    //QString json_str(byte_array);
    QNetworkRequest req;
    req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/deviceList"));
    //发送用户数据到服务器
    deviceList_Reply=manager->post(req,byte_array);
    QReplyTimeout *pTimeout = new QReplyTimeout(deviceList_Reply, 10000);
    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
        ui->statusbar->showMessage("网络超时！",10000);
    });
}

void MainWindow1::reply(QNetworkReply *rep)
{
    if(rep==deviceList_Reply)//获取待审核设备列表
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
                    globalvar::deviceList.clear();//清空原有数据
                    QJsonObject obj = json.object();
                    QJsonArray devicelistarr=obj.take("deviceList").toArray();
                    model_deviceList->clear();
                    //ItemDelegateforCol *delegate=new ItemDelegateforCol(1);
                    //ui->tableview_daishen->setItemDelegateForColumn(1,delegate);
                    for(int i=0;i<devicelistarr.count();i++)
                    {
                        QJsonObject device=devicelistarr.at(i).toObject();
                        QHash<QString,QString> devicexiangqing;
                        devicexiangqing.insert("deviceName",device.take("deviceName").toString());//设备名称
                        devicexiangqing.insert("devicePermit",device.take("devicePermit").toString());//使用登记编号
                        devicexiangqing.insert("deviceCode",device.take("deviceCode").toString());//设备代码
                        devicexiangqing.insert("deviceType",device.take("deviceType").toString());//设备类型
                        devicexiangqing.insert("deviceMode",device.take("deviceMode").toString());//设备形式
                        devicexiangqing.insert("deviceAddress",device.take("deviceAddress").toString());//设备使用地点
                        devicexiangqing.insert("deviceCompany",device.take("deviceCompany").toString());//使用单位ID
                        devicexiangqing.insert("deviceNumber",device.take("deviceNumber").toString());//使用单位代码
                        devicexiangqing.insert("deviceNumber2",device.take("deviceNumber2").toString());//使用单位设备编号
                        devicexiangqing.insert("deviceSafe",device.take("deviceSafe").toString());//安全管理人员
                        devicexiangqing.insert("deviceMt",device.take("deviceMt").toString());//制造日期
                        devicexiangqing.insert("deviceMaker",device.take("deviceMaker").toString());//制造单位
                        devicexiangqing.insert("deviceSpec",device.take("deviceSpec").toString());//规格型号
                        devicexiangqing.insert("deviceMn",device.take("deviceMn").toString());//产品编号
                        devicexiangqing.insert("deviceRe",device.take("deviceRe").toString());// 维护保养单位
                        devicexiangqing.insert("deviceBuild",device.take("deviceBuild").toString());//施工单位
                        devicexiangqing.insert("deviceBuildn",device.take("deviceBuildn").toString());//施工单位许可证编号
                        devicexiangqing.insert("deviceBuildt",device.take("deviceBuildt").toString());//施工类别
                        devicexiangqing.insert("deviceBuilda",device.take("deviceBuilda").toString());//安装地点
                        devicexiangqing.insert("deviceWe",device.take("deviceWe").toString());//额定载重量
                        devicexiangqing.insert("deviceSp",device.take("deviceSp").toString());//额定速度
                        devicexiangqing.insert("deviceHe",device.take("deviceHe").toString());//层站数
                        devicexiangqing.insert("deviceCo",device.take("deviceCo").toString());//控制方式
                        devicexiangqing.insert("deviceCompanyName",device.take("deviceCompanyName").toString());//使用单位中文名称
                        devicexiangqing.insert("deviceId",device.take("deviceId").toString());//设备ID
                        devicexiangqing.insert("deviceStatus",device.take("deviceStatus").toString());//设备审核状态123
                        devicexiangqing.insert("deviceTime",device.take("deviceTime").toString());//设备录入时间
                        devicexiangqing.insert("report",device.take("report").toString());//设备下是否有检测单12
                        globalvar::deviceList.append(devicexiangqing);
                        model_deviceList->appendRow(new QStandardItem(devicexiangqing.value("deviceName")));
                        //通过按钮
                        QPushButton* btn1=new QPushButton("通过");
                        model_deviceList->setItem(i,1,new QStandardItem(""));;
                        ui->tableview_daishen->setIndexWidget(model_deviceList->index(i,1),btn1);
                        btn1->setProperty("row",i);
                        connect(btn1,SIGNAL(clicked(bool)),this,SLOT(onbutton_tongguoclick()));
                        QPushButton* btn2=new QPushButton("不通过");
                        model_deviceList->setItem(i,2,new QStandardItem(""));;
                        ui->tableview_daishen->setIndexWidget(model_deviceList->index(i,2),btn2);
                        btn2->setProperty("row",i);
                        connect(btn2,SIGNAL(clicked(bool)),this,SLOT(onbutton_butongguoclick()));

                        itemlist.append(i);

                    }
                    //ui->tableview_daishen->setItemDelegate(new ItemDelegateforCol(1));
                }
            }
        }
    }
    if(rep==tongguoList_Reply)//获取审核通过设备列表
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
                    globalvar::tongguoList.clear();//清空原有数据
                    QJsonObject obj = json.object();
                    QJsonArray devicelistarr=obj.take("deviceList").toArray();
                    model_deviceList2->clear();
                    //ItemDelegateforCol *delegate=new ItemDelegateforCol(1);
                    //ui->tableview_daishen->setItemDelegateForColumn(1,delegate);
                    for(int i=0;i<devicelistarr.count();i++)
                    {
                        QJsonObject device=devicelistarr.at(i).toObject();
                        QHash<QString,QString> devicexiangqing;
                        devicexiangqing.insert("deviceName",device.take("deviceName").toString());//设备名称
                        devicexiangqing.insert("devicePermit",device.take("devicePermit").toString());//使用登记编号
                        devicexiangqing.insert("deviceCode",device.take("deviceCode").toString());//设备代码
                        devicexiangqing.insert("deviceType",device.take("deviceType").toString());//设备类型
                        devicexiangqing.insert("deviceMode",device.take("deviceMode").toString());//设备形式
                        devicexiangqing.insert("deviceAddress",device.take("deviceAddress").toString());//设备使用地点
                        devicexiangqing.insert("deviceCompany",device.take("deviceCompany").toString());//使用单位ID
                        devicexiangqing.insert("deviceNumber",device.take("deviceNumber").toString());//使用单位代码
                        devicexiangqing.insert("deviceNumber2",device.take("deviceNumber2").toString());//使用单位设备编号
                        devicexiangqing.insert("deviceSafe",device.take("deviceSafe").toString());//安全管理人员
                        devicexiangqing.insert("deviceMt",device.take("deviceMt").toString());//制造日期
                        devicexiangqing.insert("deviceMaker",device.take("deviceMaker").toString());//制造单位
                        devicexiangqing.insert("deviceSpec",device.take("deviceSpec").toString());//规格型号
                        devicexiangqing.insert("deviceMn",device.take("deviceMn").toString());//产品编号
                        devicexiangqing.insert("deviceRe",device.take("deviceRe").toString());// 维护保养单位
                        devicexiangqing.insert("deviceBuild",device.take("deviceBuild").toString());//施工单位
                        devicexiangqing.insert("deviceBuildn",device.take("deviceBuildn").toString());//施工单位许可证编号
                        devicexiangqing.insert("deviceBuildt",device.take("deviceBuildt").toString());//施工类别
                        devicexiangqing.insert("deviceBuilda",device.take("deviceBuilda").toString());//安装地点
                        devicexiangqing.insert("deviceWe",device.take("deviceWe").toString());//额定载重量
                        devicexiangqing.insert("deviceSp",device.take("deviceSp").toString());//额定速度
                        devicexiangqing.insert("deviceHe",device.take("deviceHe").toString());//层站数
                        devicexiangqing.insert("deviceCo",device.take("deviceCo").toString());//控制方式
                        devicexiangqing.insert("deviceCompanyName",device.take("deviceCompanyName").toString());//使用单位中文名称
                        devicexiangqing.insert("deviceId",device.take("deviceId").toString());//设备ID
                        devicexiangqing.insert("deviceStatus",device.take("deviceStatus").toString());//设备审核状态123
                        devicexiangqing.insert("deviceTime",device.take("deviceTime").toString());//设备录入时间
                        devicexiangqing.insert("report",device.take("report").toString());//设备下是否有检测单12
                        globalvar::tongguoList.append(devicexiangqing);
                        model_deviceList2->appendRow(new QStandardItem(devicexiangqing.value("deviceName")));
//                        //通过按钮
//                        QPushButton* btn1=new QPushButton("通过");
//                        model_deviceList->setItem(i,1,new QStandardItem(""));;
//                        ui->tableview_daishen->setIndexWidget(model_deviceList->index(i,1),btn1);
//                        btn1->setProperty("row",i);
//                        connect(btn1,SIGNAL(clicked(bool)),this,SLOT(onbutton_tongguoclick()));
//                        QPushButton* btn2=new QPushButton("不通过");
//                        model_deviceList->setItem(i,2,new QStandardItem(""));;
//                        ui->tableview_daishen->setIndexWidget(model_deviceList->index(i,2),btn2);
//                        btn2->setProperty("row",i);
//                        connect(btn2,SIGNAL(clicked(bool)),this,SLOT(onbutton_butongguoclick()));

//                        itemlist.append(i);

                    }
                }
            }
        }
    }
    if(rep==weitongguoList_Reply)//获取审核未通过设备列表
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
                    globalvar::weitongguoList.clear();//清空原有数据
                    QJsonObject obj = json.object();
                    QJsonArray devicelistarr=obj.take("deviceList").toArray();
                    model_deviceList3->clear();
                    //ItemDelegateforCol *delegate=new ItemDelegateforCol(1);
                    //ui->tableview_daishen->setItemDelegateForColumn(1,delegate);
                    for(int i=0;i<devicelistarr.count();i++)
                    {
                        QJsonObject device=devicelistarr.at(i).toObject();
                        QHash<QString,QString> devicexiangqing;
                        devicexiangqing.insert("deviceName",device.take("deviceName").toString());//设备名称
                        devicexiangqing.insert("devicePermit",device.take("devicePermit").toString());//使用登记编号
                        devicexiangqing.insert("deviceCode",device.take("deviceCode").toString());//设备代码
                        devicexiangqing.insert("deviceType",device.take("deviceType").toString());//设备类型
                        devicexiangqing.insert("deviceMode",device.take("deviceMode").toString());//设备形式
                        devicexiangqing.insert("deviceAddress",device.take("deviceAddress").toString());//设备使用地点
                        devicexiangqing.insert("deviceCompany",device.take("deviceCompany").toString());//使用单位ID
                        devicexiangqing.insert("deviceNumber",device.take("deviceNumber").toString());//使用单位代码
                        devicexiangqing.insert("deviceNumber2",device.take("deviceNumber2").toString());//使用单位设备编号
                        devicexiangqing.insert("deviceSafe",device.take("deviceSafe").toString());//安全管理人员
                        devicexiangqing.insert("deviceMt",device.take("deviceMt").toString());//制造日期
                        devicexiangqing.insert("deviceMaker",device.take("deviceMaker").toString());//制造单位
                        devicexiangqing.insert("deviceSpec",device.take("deviceSpec").toString());//规格型号
                        devicexiangqing.insert("deviceMn",device.take("deviceMn").toString());//产品编号
                        devicexiangqing.insert("deviceRe",device.take("deviceRe").toString());// 维护保养单位
                        devicexiangqing.insert("deviceBuild",device.take("deviceBuild").toString());//施工单位
                        devicexiangqing.insert("deviceBuildn",device.take("deviceBuildn").toString());//施工单位许可证编号
                        devicexiangqing.insert("deviceBuildt",device.take("deviceBuildt").toString());//施工类别
                        devicexiangqing.insert("deviceBuilda",device.take("deviceBuilda").toString());//安装地点
                        devicexiangqing.insert("deviceWe",device.take("deviceWe").toString());//额定载重量
                        devicexiangqing.insert("deviceSp",device.take("deviceSp").toString());//额定速度
                        devicexiangqing.insert("deviceHe",device.take("deviceHe").toString());//层站数
                        devicexiangqing.insert("deviceCo",device.take("deviceCo").toString());//控制方式
                        devicexiangqing.insert("deviceCompanyName",device.take("deviceCompanyName").toString());//使用单位中文名称
                        devicexiangqing.insert("deviceId",device.take("deviceId").toString());//设备ID
                        devicexiangqing.insert("deviceStatus",device.take("deviceStatus").toString());//设备审核状态123
                        devicexiangqing.insert("deviceTime",device.take("deviceTime").toString());//设备录入时间
                        devicexiangqing.insert("report",device.take("report").toString());//设备下是否有检测单12
                        globalvar::weitongguoList.append(devicexiangqing);
                        model_deviceList3->appendRow(new QStandardItem(devicexiangqing.value("deviceName")));
//                        //通过按钮
//                        QPushButton* btn1=new QPushButton("通过");
//                        model_deviceList->setItem(i,1,new QStandardItem(""));;
//                        ui->tableview_daishen->setIndexWidget(model_deviceList->index(i,1),btn1);
//                        btn1->setProperty("row",i);
//                        connect(btn1,SIGNAL(clicked(bool)),this,SLOT(onbutton_tongguoclick()));
//                        QPushButton* btn2=new QPushButton("不通过");
//                        model_deviceList->setItem(i,2,new QStandardItem(""));;
//                        ui->tableview_daishen->setIndexWidget(model_deviceList->index(i,2),btn2);
//                        btn2->setProperty("row",i);
//                        connect(btn2,SIGNAL(clicked(bool)),this,SLOT(onbutton_butongguoclick()));

//                        itemlist.append(i);

                    }
                }
            }
        }
    }
    if(rep==tongguo_reply)//提交通过
    {
        if(rep->error()==QNetworkReply::NoError)
        {
            QByteArray a =rep->readAll();
            qDebug()<<a;
            QJsonParseError jsonError;
            QJsonDocument json = QJsonDocument::fromJson(a, &jsonError);
            if(jsonError.error == QJsonParseError::NoError)//
            {
                if(json.isObject())
                {
                    QJsonObject obj=json.object();
                    int code=obj.take("code").toInt();
                    if(code==1)
                    {
                        getDevicelist(1);
                        getDevicelist(2);
                        getDevicelist(3);
                    }else
                    {

                    }
                }
            }
        }
    }
    if(rep==butongguo_reply)//提交不通过
    {
        if(rep->error()==QNetworkReply::NoError)
        {
            QByteArray a =rep->readAll();
            qDebug()<<a;
            QJsonParseError jsonError;
            QJsonDocument json = QJsonDocument::fromJson(a, &jsonError);
            if(jsonError.error == QJsonParseError::NoError)//
            {
                if(json.isObject())
                {
                    QJsonObject obj=json.object();
                    int code=obj.take("code").toInt();
                    if(code==1)
                    {
                        getDevicelist(1);
                        getDevicelist(2);
                        getDevicelist(3);
                    }else
                    {
                        getDevicelist(1);
                    }
                }
            }
        }
    }
    rep->deleteLater();
}

void MainWindow1::updateModel(qint64,qint64)
{

}

void MainWindow1::slot_view_device(bool)
{
    int row=ui->tableview_daishen->currentIndex().row();
    deviceInfo *Info=new deviceInfo(row);
    Info->show();
    //MyTitleBar *bar=new MyTitleBar;
    //bar->resize(966+10,723+40);
    //Info->setParent(bar);
    //bar->show();
}

void MainWindow1::createActions()
{
    pop_menu=new QMenu;
    view_device =new QAction(this);
    connect(view_device,SIGNAL(triggered(bool)),this,SLOT(slot_view_device(bool)));
}

void MainWindow1::translateLanguage()
{
    view_device->setText("查看电梯设备信息");
}

void MainWindow1::contextMenuEvent(QContextMenuEvent *e)
{
    if(ui->tableview_daishen->hasFocus())
    {
       createActions();
       translateLanguage();
       pop_menu->clear();
       pop_menu->addAction(view_device);
       //菜单出现的位置为当前鼠标的位置
       pop_menu->exec(QCursor::pos());
       e->accept();
    }

}

void MainWindow1::on_pushButton_clicked()//通过
{

    //    int row=ui->listView->currentIndex().row();
//    if(row==-1)
//        return;
//    //备注信息
//    globalvar::deviceList[itemlist.at(row)].insert("deviceRemark",ui->textEdit->toPlainText());
//    ui->textEdit->clear();
//    //审核结果
//    globalvar::deviceList[itemlist.at(row)].insert("deviceStatus","2");
//    //从未审核列表移除
//    model_deviceList->removeRow(row);
//    itemlist2.append(itemlist.at(row));
//    itemlist.removeAt(row);
//    //添加到已审核列表
//    model_deviceList2->appendRow(new QStandardItem(globalvar::deviceList[itemlist2[itemlist2.count()-1]].value("deviceName")));

}

void MainWindow1::on_pushButton_2_clicked()//不通过
{
//    int row=ui->listView->currentIndex().row();
//    if(row==-1)
//        return;
//    //备注信息
//    globalvar::deviceList[itemlist.at(row)].insert("deviceRemark",ui->textEdit->toPlainText());
//    ui->textEdit->clear();
//    //审核结果
//    globalvar::deviceList[itemlist.at(row)].insert("deviceStatus","3");
//    //从未审核列表移除
//    model_deviceList->removeRow(row);
//    itemlist3.append(itemlist.at(row));
//    itemlist.removeAt(row);
//    //添加到已审核列表
//    model_deviceList3->appendRow(new QStandardItem(globalvar::deviceList[itemlist3[itemlist3.count()-1]].value("deviceName")));
}

void MainWindow1::on_pushButton_3_clicked()//重新审核
{
//    if(ui->listView_2->hasFocus())
//    {
//        int row=ui->listView_2->currentIndex().row();
//        if(row==-1)
//            return;
//        //备注信息
//        globalvar::deviceList[itemlist2.at(row)].insert("deviceRemark","");//清空
//        ui->textEdit->clear();
//        //审核结果
//        globalvar::deviceList[itemlist2.at(row)].insert("deviceStatus","1");
//        //从未审核列表移除
//        model_deviceList2->removeRow(row);
//        itemlist.append(itemlist2.at(row));
//        itemlist2.removeAt(row);
//        //添加到已审核列表
//        model_deviceList->appendRow(new QStandardItem(globalvar::deviceList[itemlist[itemlist.count()-1]].value("deviceName")));
//    }
//    if(ui->listView_3->hasFocus())
//    {
//        int row=ui->listView_3->currentIndex().row();
//        if(row==-1)
//            return;
//        //备注信息
//        globalvar::deviceList[itemlist3.at(row)].insert("deviceRemark","");//清空
//        ui->textEdit->clear();
//        //审核结果
//        globalvar::deviceList[itemlist3.at(row)].insert("deviceStatus","1");
//        //从未审核列表移除
//        model_deviceList3->removeRow(row);
//        itemlist.append(itemlist3.at(row));
//        itemlist3.removeAt(row);
//        //添加到已审核列表
//        model_deviceList->appendRow(new QStandardItem(globalvar::deviceList[itemlist[itemlist.count()-1]].value("deviceName")));
//    }
}

void MainWindow1::on_pushButton_4_clicked()//提交审核
{
//    QJsonObject json;
//    for(int i=0;i<globalvar::deviceList.count();i++)
//    {
//        QJsonObject device;
//        device.insert("deviceId",globalvar::deviceList[i].value("deviceId"));
//        device.insert("deviceStatus",globalvar::deviceList[i].value("deviceStatus"));
//        device.insert("deviceRemark",globalvar::deviceList[i].value("deviceRemark"));
//        json.insert("d"+QString::number(i),device);
//    }
//    QJsonDocument docu;
//    docu.setObject(json);
//    QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
//    //QString json_str(byte_array);
//    QNetworkRequest req;
//    req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/changeStatus"));
//    //发送用户数据到服务器
//    tijiaodevice_reply=manager->post(req,byte_array);
//    QReplyTimeout *pTimeout = new QReplyTimeout(tijiaodevice_reply, 10000);
//    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
//        ;
    //    });
}

void MainWindow1::onbutton_tongguoclick()//通过
{
    QPushButton* button=(QPushButton*)sender();
    int row =button->property("row").toInt();
    QJsonObject json;
    json.insert("deviceId",globalvar::deviceList[row].value("deviceId"));
    json.insert("deviceStatus","2");
    json.insert("deviceRemark",globalvar::deviceList[row].value("deviceRemark"));
    QJsonDocument docu;
    docu.setObject(json);
    QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
    //QString json_str(byte_array);
    QNetworkRequest req;
    req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/changeStatus"));
    //发送用户数据到服务器
    tongguo_reply=manager->post(req,byte_array);
    QReplyTimeout *pTimeout = new QReplyTimeout(tongguo_reply, 10000);
    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
        ;
        });
}

void MainWindow1::onbutton_butongguoclick()//不通过
{

    QPushButton* button=(QPushButton*)sender();
    int row =button->property("row").toInt();
    remark *mark=new remark(row,0);
    int result=mark->exec();
    if(result==1)//accept
    {

    }
    if(result==0)//reject
    {
        return;
    }
    QJsonObject json;
    json.insert("deviceId",globalvar::deviceList[row].value("deviceId"));
    json.insert("deviceStatus","3");
    json.insert("deviceRemark",globalvar::deviceList[row].value("deviceRemark"));
    QJsonDocument docu;
    docu.setObject(json);
    QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
    //QString json_str(byte_array);
    QNetworkRequest req;
    req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/changeStatus"));
    //发送用户数据到服务器
    butongguo_reply=manager->post(req,byte_array);
    QReplyTimeout *pTimeout = new QReplyTimeout(butongguo_reply, 10000);
    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
        ;
        });
}
