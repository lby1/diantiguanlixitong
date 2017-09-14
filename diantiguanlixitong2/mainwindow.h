#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QString>
#include <QStandardItemModel>
#include "mytitlebar.h"
#include "basewindow.h"

namespace Ui {
class MainWindow;
}
//typedef struct {
//    QString name;//这条检验的名字
//    QString text_type;//类型ABC
//    QStringList content;//检验项目的内容
//    QStringList method;//检验的方法
//    QStringList results;//检验的结果
//}TEST;//一条检验

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initial();

private slots:
    void on_treeView_doubleClicked(const QModelIndex &index);
    //Treview数据变化的槽
    void on_treeview_datachanged(QModelIndex,QModelIndex,QVector<int>);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

   QHash<int,QStringList> Content_data;// 定期检验报告的内容
   QHash<int,QStringList> Content_data2;// 监督检验报告的内容
   QVector<TEST> T_data;// 定期检验报告的内容
   QVector<TEST> T_data2;// 监督检验报告的内容
   static QStringList testType;
   static QStringList testType2;
   static QStringList testName;
   static QStringList testName2;
   static QVector<QStringList> testMethod;
   static QVector<QStringList> testMethod2;

   QStandardItemModel *model;//Treeview的model
};

#endif // MAINWINDOW_H
