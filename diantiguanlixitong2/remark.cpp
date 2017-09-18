#include "remark.h"
#include "ui_remark.h"
#include "globalvar.h"

remark::remark(int row,int col,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remark),
    _row(row),
    _col(col)
{
    ui->setupUi(this);
}

remark::~remark()
{
    delete ui;
}

void remark::on_pushButton_2_clicked()
{
    globalvar::deviceList[_row].insert("deviceRemark",ui->textEdit->toPlainText());
    this->accept();
}
