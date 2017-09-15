#include "deviceinfo.h"
#include "ui_deviceinfo.h"
#include <QPainter>
#include "globalvar.h"

deviceInfo::deviceInfo(int devicerow,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deviceInfo)
{
    ui->setupUi(this);
    _devicerow=devicerow;
    init();
	int i;
}

deviceInfo::~deviceInfo()
{
    delete ui;
}

void deviceInfo::init()
{
    if(_devicerow==-1)
    {
        return;
    }
    ui->tableWidget->setVisible(false);
    ui->tableWidget2->setVisible(false);
        ui->tableWidget->horizontalHeader()->setVisible(false);
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->tableWidget->setColumnWidth(0,40);
        ui->tableWidget->setColumnWidth(1,110);
        ui->tableWidget->setColumnWidth(2,110);
        ui->tableWidget->setColumnWidth(3,100);
        ui->tableWidget->setColumnWidth(4,110);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(tr("设备名称")));
        ui->tableWidget->setSpan(0, 0, 1, 2);
        ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(tr("使用登记编号")));
        ui->tableWidget->item(0,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(1,0,new QTableWidgetItem(tr("使用单位")));
        ui->tableWidget->setSpan(1, 0, 1, 2);
        ui->tableWidget->setSpan(1, 2, 1, 3);
        ui->tableWidget->item(1,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(2,0,new QTableWidgetItem(tr("设备使用地点")));
        ui->tableWidget->setSpan(2, 0, 1, 2);
        ui->tableWidget->setSpan(2, 2, 1, 3);
        ui->tableWidget->item(2,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(3,0,new QTableWidgetItem(tr("使用单位代码")));
        ui->tableWidget->setSpan(3, 0, 1, 2);
        ui->tableWidget->item(3,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(3,3,new QTableWidgetItem(tr("使用单位设备编号")));
        ui->tableWidget->resizeRowToContents(3);
        ui->tableWidget->item(3,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setRowHeight(3,40);
        ui->tableWidget->setItem(4,0,new QTableWidgetItem(tr("安全管理人员")));
        ui->tableWidget->setSpan(4, 0, 1, 2);
        ui->tableWidget->item(4,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(4,3,new QTableWidgetItem(tr("制造日期")));
        ui->tableWidget->item(4,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(5,0,new QTableWidgetItem(tr("制造单位")));
        ui->tableWidget->setSpan(5, 0, 1, 2);
        ui->tableWidget->setSpan(5, 2, 1, 3);
        ui->tableWidget->item(5,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(6,0,new QTableWidgetItem(tr("规格型号")));
        ui->tableWidget->setSpan(6, 0, 1, 2);
        ui->tableWidget->item(6,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(6,3,new QTableWidgetItem(tr("产品编号")));
        ui->tableWidget->item(6,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(7,0,new QTableWidgetItem(tr("维护保养单位")));
        ui->tableWidget->setSpan(7, 0, 1, 2);
        ui->tableWidget->setSpan(7, 2, 1, 3);
        ui->tableWidget->item(7,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(8,0,new QTableWidgetItem(tr("设备技术参数")));
        ui->tableWidget->setSpan(8, 0, 2, 1);
        ui->tableWidget->resizeRowToContents(8);
        ui->tableWidget->item(8,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(8,1,new QTableWidgetItem(tr("额定载重量")));
        ui->tableWidget->item(8,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(8,2,new QTableWidgetItem("KG"));
        ui->tableWidget->item(8,2)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        ui->tableWidget->setItem(8,3,new QTableWidgetItem(tr("额定速度")));
        ui->tableWidget->item(8,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(8,4,new QTableWidgetItem("            m/s"));
        ui->tableWidget->item(8,4)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        ui->tableWidget->setRowHeight(8,25);
        ui->tableWidget->setItem(9,1,new QTableWidgetItem(tr("层站数")));
        ui->tableWidget->item(9,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(9,2,new QTableWidgetItem(tr("层     站")));
        ui->tableWidget->item(9,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(9,3,new QTableWidgetItem(tr("控制方式")));
        ui->tableWidget->item(9,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setRowHeight(9,40);
        ui->tableWidget->setItem(10,0,new QTableWidgetItem(tr("检验依据")));
        ui->tableWidget->item(10,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->resizeRowToContents(10);
        ui->tableWidget->setItem(10,1,new QTableWidgetItem(tr("《电梯监督检验和定期检验规则-曳引与强制驱动电梯》（TSG T7001-2009）")));
        ui->tableWidget->setSpan(10, 1, 1, 4);
        ui->tableWidget->resizeColumnToContents(10);
        ui->tableWidget->item(10,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(11,0,new QTableWidgetItem(tr("主要检验仪器设备")));
        ui->tableWidget->setSpan(11, 1, 1, 4);
        ui->tableWidget->resizeRowToContents(11);
        ui->tableWidget->item(11,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(12,0,new QTableWidgetItem(tr("检验结论")));
        ui->tableWidget->setSpan(12, 1, 1, 4);
        ui->tableWidget->resizeRowToContents(12);
        ui->tableWidget->item(12,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(13,0,new QTableWidgetItem(tr("备注")));
        ui->tableWidget->setSpan(13, 1, 1, 4);
        ui->tableWidget->item(13,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(14,0,new QTableWidgetItem(tr("检验日期")));
        ui->tableWidget->setSpan(14, 0, 1, 2);
        ui->tableWidget->item(14,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(14,3,new QTableWidgetItem(tr("下次检验日期")));
        ui->tableWidget->item(14,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(15,0,new QTableWidgetItem(tr("检验人员")));
        ui->tableWidget->setSpan(15, 0, 1, 2);
        ui->tableWidget->setSpan(15, 2, 1, 3);
        ui->tableWidget->item(15,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(16,0,new QTableWidgetItem(tr("编制：                       日期：")));
        ui->tableWidget->setSpan(16, 0, 1, 3);
        ui->tableWidget->item(16,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->setItem(17,0,new QTableWidgetItem(tr("审核：                       日期：")));
        ui->tableWidget->setSpan(17, 0, 1, 3);
        ui->tableWidget->item(17,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->setItem(18,0,new QTableWidgetItem(tr("批准：                       日期：")));
        ui->tableWidget->setSpan(18, 0, 1, 3);
        ui->tableWidget->setRowHeight(18,50);
        ui->tableWidget->item(18,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->setSpan(16, 3, 3, 2);
        ui->tableWidget->setItem(16,3,new QTableWidgetItem(tr("检验机构核准证号:                                                                                                                    （检验机构公章或检验专用章）               年   月   日")));
        ui->tableWidget->item(16,3)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(0,0)->setFlags(ui->tableWidget->item(0,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(0,3)->setFlags(ui->tableWidget->item(0,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(1,0)->setFlags(ui->tableWidget->item(1,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(2,0)->setFlags(ui->tableWidget->item(2,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(3,0)->setFlags(ui->tableWidget->item(3,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(3,3)->setFlags(ui->tableWidget->item(3,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(4,0)->setFlags(ui->tableWidget->item(4,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(4,3)->setFlags(ui->tableWidget->item(4,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(5,0)->setFlags(ui->tableWidget->item(5,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(6,0)->setFlags(ui->tableWidget->item(6,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(6,3)->setFlags(ui->tableWidget->item(6,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(7,0)->setFlags(ui->tableWidget->item(7,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(8,0)->setFlags(ui->tableWidget->item(8,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(8,1)->setFlags(ui->tableWidget->item(8,1)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(8,3)->setFlags(ui->tableWidget->item(8,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(9,1)->setFlags(ui->tableWidget->item(9,1)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(9,3)->setFlags(ui->tableWidget->item(9,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget->item(10,1)->setFlags(ui->tableWidget->item(10,1)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(10,0)->setFlags(ui->tableWidget->item(10,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(11,0)->setFlags(ui->tableWidget->item(11,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(12,0)->setFlags(ui->tableWidget->item(12,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(13,0)->setFlags(ui->tableWidget->item(13,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(14,0)->setFlags(ui->tableWidget->item(14,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(14,3)->setFlags(ui->tableWidget->item(14,3)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(15,0)->setFlags(ui->tableWidget->item(15,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(16,0)->setFlags(ui->tableWidget->item(16,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(17,0)->setFlags(ui->tableWidget->item(17,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(18,0)->setFlags(ui->tableWidget->item(18,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget->item(16,3)->setFlags(ui->tableWidget->item(16,3)->flags()
                                          & ~Qt::ItemIsEditable);

        int _width=0;
        for(int i=0;i<ui->tableWidget->columnCount();i++)
        {
            _width+=ui->tableWidget->columnWidth(i);
        }
        int _height=0;
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            _height+=ui->tableWidget->rowHeight(i);
        }
        ui->tableWidget->resize(_width+5,_height+5);
        ui->tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ui->tableWidget->setVisible(true);

        /*******************************************table2**************************************/
        ui->tableWidget2->setColumnCount(5);
        ui->tableWidget2->setRowCount(19);
        ui->tableWidget2->horizontalHeader()->setVisible(false);
        ui->tableWidget2->verticalHeader()->setVisible(false);
        ui->tableWidget2->setColumnWidth(0,40);
        ui->tableWidget2->setColumnWidth(1,110);
        ui->tableWidget2->setColumnWidth(2,110);
        ui->tableWidget2->setColumnWidth(3,100);
        ui->tableWidget2->setColumnWidth(4,110);
        ui->tableWidget2->setItem(0,0,new QTableWidgetItem(tr("设备名称")));
        ui->tableWidget2->setSpan(0, 0, 1, 2);
        ui->tableWidget2->item(0,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(0,3,new QTableWidgetItem(tr("规格型号")));
        ui->tableWidget2->item(0,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(1,0,new QTableWidgetItem(tr("制造单位")));
        ui->tableWidget2->setSpan(1, 0, 1, 2);
        ui->tableWidget2->setSpan(1, 2, 1, 3);
        ui->tableWidget2->item(1,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(2,0,new QTableWidgetItem(tr("产品编号")));
        ui->tableWidget2->setSpan(2, 0, 1, 2);
        ui->tableWidget2->item(2,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(2,3,new QTableWidgetItem(tr("制造日期")));
        ui->tableWidget2->item(2,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(3,0,new QTableWidgetItem(tr("施工单位")));
        ui->tableWidget2->setSpan(3, 0, 1, 2);
        ui->tableWidget2->setSpan(3, 2, 1, 3);
        ui->tableWidget2->item(3,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->resizeRowToContents(3);
        ui->tableWidget2->setItem(4,0,new QTableWidgetItem(tr("施工单位许可证号")));
        ui->tableWidget2->setSpan(4, 0, 1, 2);
        ui->tableWidget2->item(4,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(4,3,new QTableWidgetItem(tr("施工类别")));
        ui->tableWidget2->item(4,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(5,0,new QTableWidgetItem(tr("安装地点")));
        ui->tableWidget2->setSpan(5, 0, 1, 2);
        ui->tableWidget2->item(5,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(5,3,new QTableWidgetItem(tr("使用登记编号")));
        ui->tableWidget2->item(5,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(6,0,new QTableWidgetItem(tr("使用单位")));
        ui->tableWidget2->setSpan(6, 0, 1, 2);
        ui->tableWidget2->setSpan(6, 2, 1, 3);
        ui->tableWidget2->item(6,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(7,0,new QTableWidgetItem(tr("维护保养单位")));
        ui->tableWidget2->setSpan(7, 0, 1, 2);
        ui->tableWidget2->setSpan(7, 2, 1, 3);
        ui->tableWidget2->item(7,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(8,0,new QTableWidgetItem(tr("设备技术参数")));
        ui->tableWidget2->setSpan(8, 0, 2, 1);
        ui->tableWidget2->resizeRowToContents(8);
        ui->tableWidget2->item(8,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(8,1,new QTableWidgetItem(tr("额定载重量")));
        ui->tableWidget2->item(8,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(8,2,new QTableWidgetItem("KG"));
        ui->tableWidget2->item(8,2)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        ui->tableWidget2->setItem(8,3,new QTableWidgetItem(tr("额定速度")));
        ui->tableWidget2->item(8,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(8,4,new QTableWidgetItem("            m/s"));
        ui->tableWidget2->item(8,4)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        ui->tableWidget2->setRowHeight(8,25);
        ui->tableWidget2->setItem(9,1,new QTableWidgetItem(tr("层站数")));
        ui->tableWidget2->item(9,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(9,2,new QTableWidgetItem(tr("层     站")));
        ui->tableWidget2->item(9,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(9,3,new QTableWidgetItem(tr("控制方式")));
        ui->tableWidget2->item(9,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setRowHeight(9,40);
        ui->tableWidget2->setItem(10,0,new QTableWidgetItem(tr("检验依据")));
        ui->tableWidget2->item(10,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->resizeRowToContents(10);
        ui->tableWidget2->setItem(10,1,new QTableWidgetItem(tr("《电梯监督检验和定期检验规则-曳引与强制驱动电梯》（TSG T7001-2009）")));
        ui->tableWidget2->setSpan(10, 1, 1, 4);
        ui->tableWidget2->resizeColumnToContents(10);
        ui->tableWidget2->item(10,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(11,0,new QTableWidgetItem(tr("主要检验仪器设备")));
        ui->tableWidget2->setSpan(11, 1, 1, 4);
        ui->tableWidget2->resizeRowToContents(11);
        ui->tableWidget2->item(11,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(12,0,new QTableWidgetItem(tr("检验结论")));
        ui->tableWidget2->setSpan(12, 1, 1, 4);
        ui->tableWidget2->resizeRowToContents(12);
        ui->tableWidget2->item(12,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(13,0,new QTableWidgetItem(tr("备注")));
        ui->tableWidget2->setSpan(13, 1, 1, 4);
        ui->tableWidget2->item(13,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(14,0,new QTableWidgetItem(tr("检验日期")));
        ui->tableWidget2->setSpan(14, 0, 1, 2);
        ui->tableWidget2->item(14,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(14,3,new QTableWidgetItem(tr("下次检验日期")));
        ui->tableWidget2->item(14,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(15,0,new QTableWidgetItem(tr("检验人员")));
        ui->tableWidget2->setSpan(15, 0, 1, 2);
        ui->tableWidget2->setSpan(15, 2, 1, 3);
        ui->tableWidget2->item(15,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget2->setItem(16,0,new QTableWidgetItem(tr("编制：                       日期：")));
        ui->tableWidget2->setSpan(16, 0, 1, 3);
        ui->tableWidget2->item(16,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget2->setItem(17,0,new QTableWidgetItem(tr("审核：                       日期：")));
        ui->tableWidget2->setSpan(17, 0, 1, 3);
        ui->tableWidget2->item(17,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget2->setItem(18,0,new QTableWidgetItem(tr("批准：                       日期：")));
        ui->tableWidget2->setSpan(18, 0, 1, 3);
        ui->tableWidget2->setRowHeight(18,50);
        ui->tableWidget2->item(18,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget2->setSpan(16, 3, 3, 2);
        ui->tableWidget2->setItem(16,3,new QTableWidgetItem(tr("检验机构核准证号:                                                                                                                    （检验机构公章或检验专用章）               年   月   日")));
        ui->tableWidget2->item(16,3)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget2->item(0,0)->setFlags(ui->tableWidget2->item(0,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(0,3)->setFlags(ui->tableWidget2->item(0,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(1,0)->setFlags(ui->tableWidget2->item(1,0)->flags()
                                        & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(2,0)->setFlags(ui->tableWidget2->item(2,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(3,0)->setFlags(ui->tableWidget2->item(3,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(4,0)->setFlags(ui->tableWidget2->item(4,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(4,3)->setFlags(ui->tableWidget2->item(4,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(5,0)->setFlags(ui->tableWidget2->item(5,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(6,0)->setFlags(ui->tableWidget2->item(6,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(7,0)->setFlags(ui->tableWidget2->item(7,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(8,0)->setFlags(ui->tableWidget2->item(8,0)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(8,1)->setFlags(ui->tableWidget2->item(8,1)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(8,3)->setFlags(ui->tableWidget2->item(8,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(9,1)->setFlags(ui->tableWidget2->item(9,1)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(9,3)->setFlags(ui->tableWidget2->item(9,3)->flags()
                                         & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(10,1)->setFlags(ui->tableWidget2->item(10,1)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(10,0)->setFlags(ui->tableWidget2->item(10,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(11,0)->setFlags(ui->tableWidget2->item(11,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(12,0)->setFlags(ui->tableWidget2->item(12,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(13,0)->setFlags(ui->tableWidget2->item(13,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(14,0)->setFlags(ui->tableWidget2->item(14,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(14,3)->setFlags(ui->tableWidget2->item(14,3)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(15,0)->setFlags(ui->tableWidget2->item(15,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(16,0)->setFlags(ui->tableWidget2->item(16,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(17,0)->setFlags(ui->tableWidget2->item(17,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(18,0)->setFlags(ui->tableWidget2->item(18,0)->flags()
                                          & ~Qt::ItemIsEditable);
        ui->tableWidget2->item(16,3)->setFlags(ui->tableWidget2->item(16,3)->flags()
                                          & ~Qt::ItemIsEditable);

         _width=0;
        for(int i=0;i<ui->tableWidget2->columnCount();i++)
        {
            _width+=ui->tableWidget2->columnWidth(i);
        }
         _height=0;
        for(int i=0;i<ui->tableWidget2->rowCount();i++)
        {
            _height+=ui->tableWidget2->rowHeight(i);
        }
        ui->tableWidget2->resize(_width+5,_height+5);
        ui->tableWidget2->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ui->tableWidget2->setVisible(true);

        /**************************数据填入************************************/
        setData1(0,2,globalvar::deviceList[_devicerow].value("deviceName"));
        setData1(0,4,globalvar::deviceList[_devicerow].value("devicePermit"));
        setData1(1,2,globalvar::deviceList[_devicerow].value("deviceCompanyName"));
        setData1(2,2,globalvar::deviceList[_devicerow].value("deviceAddress"));
        setData1(3,2,globalvar::deviceList[_devicerow].value("deviceNumber"));
        setData1(3,4,globalvar::deviceList[_devicerow].value("deviceNumber2"));
        setData1(4,2,globalvar::deviceList[_devicerow].value("deviceSafe"));
        setData1(4,4,globalvar::deviceList[_devicerow].value("deviceMt"));
        setData1(5,2,globalvar::deviceList[_devicerow].value("deviceMaker"));
        setData1(6,2,globalvar::deviceList[_devicerow].value("deviceSpec"));
        setData1(6,4,globalvar::deviceList[_devicerow].value("deviceMn"));
        setData1(7,2,globalvar::deviceList[_devicerow].value("deviceRe"));
        setData1(8,2,globalvar::deviceList[_devicerow].value("deviceWe"));
        setData1(8,4,globalvar::deviceList[_devicerow].value("deviceSp"));
        setData1(9,2,globalvar::deviceList[_devicerow].value("deviceHe"));
        setData1(9,4,globalvar::deviceList[_devicerow].value("deviceCo"));

        setData2(0,2,globalvar::deviceList[_devicerow].value("deviceName"));
        setData2(0,4,globalvar::deviceList[_devicerow].value("deviceSpec"));
        setData2(1,2,globalvar::deviceList[_devicerow].value("deviceMaker"));
        setData2(2,2,globalvar::deviceList[_devicerow].value("deviceMn"));
        setData2(2,4,globalvar::deviceList[_devicerow].value("deviceMt"));
        setData2(3,2,globalvar::deviceList[_devicerow].value("deviceBuild"));
        setData2(4,2,globalvar::deviceList[_devicerow].value("deviceBuildn"));
        setData2(4,4,globalvar::deviceList[_devicerow].value("deviceBuildt"));
        setData2(5,2,globalvar::deviceList[_devicerow].value("deviceBuilda"));
        setData2(5,4,globalvar::deviceList[_devicerow].value("devicePermit"));
        setData2(6,2,globalvar::deviceList[_devicerow].value("deviceCompanyName"));
        setData2(7,2,globalvar::deviceList[_devicerow].value("deviceRe"));
        setData2(8,2,globalvar::deviceList[_devicerow].value("deviceWe"));
        setData2(8,4,globalvar::deviceList[_devicerow].value("deviceSp"));
        setData2(9,2,globalvar::deviceList[_devicerow].value("deviceHe"));
        setData2(9,4,globalvar::deviceList[_devicerow].value("deviceCo"));

}

void deviceInfo::setData1(int row, int col, QString value)
{
    QTableWidgetItem *item =ui->tableWidget->item(row,col);
    if(item==NULL)
    {
        ui->tableWidget->setItem(row,col,new QTableWidgetItem(value));
    }else
    {
        item->setText(value);
    }
}

void deviceInfo::setData2(int row, int col, QString value)
{
    QTableWidgetItem *item =ui->tableWidget2->item(row,col);
    if(item==NULL)
    {
        ui->tableWidget2->setItem(row,col,new QTableWidgetItem(value));
    }else
    {
        item->setText(value);
    }
}

void deviceInfo::paintEvent(QPaintEvent *event)
{
    //设置背景色;
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(240, 240, 240)));
//    painter.fillPath(pathBack, QBrush(QPixmap("C:/Users/hp/Desktop/timg.jpg")));

    return QWidget::paintEvent(event);
}
