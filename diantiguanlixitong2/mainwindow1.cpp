#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "globalvar.h"
#include "qreplytimeout.h"
#include "deviceinfo.h"

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
    QFile file("C:/Users/Administrator/Desktop/chuibai.QSS");
     file.open(QIODevice::ReadOnly);
     QString s=file.readAll();
     file.close();
     this->setStyleSheet(s);

    manager=new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply *)));
    //获取待审核设备列表
    getDevicelist();
    //同步获取待审核设备列表
//    QEventLoop loop;
//    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
//    loop.exec();
    model_deviceList=new QStandardItemModel();
    model_deviceList2=new QStandardItemModel();
    model_deviceList3=new QStandardItemModel();
    ui->listView->setModel(model_deviceList);
    ui->listView_2->setModel(model_deviceList2);
    ui->listView_3->setModel(model_deviceList3);
}

void MainWindow1::getDevicelist()
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
        ui->statusbar->showMessage("网络超时！",5000);
    });
}

void MainWindow1::reply(QNetworkReply *rep)
{
    if(rep==deviceList_Reply)//待审核设备列表
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
                        itemlist.append(i);
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
    int row=ui->listView->currentIndex().row();
    deviceInfo *Info=new deviceInfo(row);
    Info->show();
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
    if(ui->listView->hasFocus())
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
    int row=ui->listView->currentIndex().row();
    if(row==-1)
        return;
    //备注信息
    globalvar::deviceList[itemlist.at(row)].insert("deviceRemark",ui->textEdit->toPlainText());
    ui->textEdit->clear();
    //审核结果
    globalvar::deviceList[itemlist.at(row)].insert("deviceStatus","2");
    //从未审核列表移除
    model_deviceList->removeRow(row);
    itemlist2.append(itemlist.at(row));
    itemlist.removeAt(row);
    //添加到已审核列表
    model_deviceList2->appendRow(new QStandardItem(globalvar::deviceList[itemlist2[itemlist2.count()-1]].value("deviceName")));

}

void MainWindow1::on_pushButton_2_clicked()//不通过
{
    int row=ui->listView->currentIndex().row();
    if(row==-1)
        return;
    //备注信息
    globalvar::deviceList[itemlist.at(row)].insert("deviceRemark",ui->textEdit->toPlainText());
    ui->textEdit->clear();
    //审核结果
    globalvar::deviceList[itemlist.at(row)].insert("deviceStatus","3");
    //从未审核列表移除
    model_deviceList->removeRow(row);
    itemlist3.append(itemlist.at(row));
    itemlist.removeAt(row);
    //添加到已审核列表
    model_deviceList3->appendRow(new QStandardItem(globalvar::deviceList[itemlist3[itemlist3.count()-1]].value("deviceName")));
}

void MainWindow1::on_pushButton_3_clicked()//重新审核
{
    if(ui->listView_2->hasFocus())
    {
        int row=ui->listView_2->currentIndex().row();
        if(row==-1)
            return;
        //备注信息
        globalvar::deviceList[itemlist2.at(row)].insert("deviceRemark","");//清空
        ui->textEdit->clear();
        //审核结果
        globalvar::deviceList[itemlist2.at(row)].insert("deviceStatus","1");
        //从未审核列表移除
        model_deviceList2->removeRow(row);
        itemlist.append(itemlist2.at(row));
        itemlist2.removeAt(row);
        //添加到已审核列表
        model_deviceList->appendRow(new QStandardItem(globalvar::deviceList[itemlist[itemlist.count()-1]].value("deviceName")));
    }
    if(ui->listView_3->hasFocus())
    {
        int row=ui->listView_3->currentIndex().row();
        if(row==-1)
            return;
        //备注信息
        globalvar::deviceList[itemlist3.at(row)].insert("deviceRemark","");//清空
        ui->textEdit->clear();
        //审核结果
        globalvar::deviceList[itemlist3.at(row)].insert("deviceStatus","1");
        //从未审核列表移除
        model_deviceList3->removeRow(row);
        itemlist.append(itemlist3.at(row));
        itemlist3.removeAt(row);
        //添加到已审核列表
        model_deviceList->appendRow(new QStandardItem(globalvar::deviceList[itemlist[itemlist.count()-1]].value("deviceName")));
    }
}

void MainWindow1::on_pushButton_4_clicked()//提交审核
{
    QJsonObject json;
    for(int i=0;i<globalvar::deviceList.count();i++)
    {
        QJsonObject device;
        device.insert("deviceId",globalvar::deviceList[i].value("deviceId"));
        device.insert("deviceStatus",globalvar::deviceList[i].value("deviceStatus"));
        device.insert("deviceRemark",globalvar::deviceList[i].value("deviceRemark"));
        json.insert("d"+QString::number(i),device);
    }
    QJsonDocument docu;
    docu.setObject(json);
    QByteArray byte_array = docu.toJson(QJsonDocument::Compact);
    //QString json_str(byte_array);
    QNetworkRequest req;
    req.setUrl(QUrl("http://cddongli.com/quexian/index.php?s=/App/AppDevice2/changeStatus"));
    //发送用户数据到服务器
    tijiaodevice_reply=manager->post(req,byte_array);
    QReplyTimeout *pTimeout = new QReplyTimeout(tijiaodevice_reply, 10000);
    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
        ;
    });
}
