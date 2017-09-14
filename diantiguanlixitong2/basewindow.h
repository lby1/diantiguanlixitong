#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include "mytitlebar.h"
#include "ui_baseWin.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

namespace Ui {
    class Form;
}
typedef struct {
    QString name;//这条检验的名字
    QString text_type;//类型ABC
    QStringList content;//检验项目的内容
    QStringList method;//检验的方法
    QStringList results;//检验的结果
}TEST;//一条检验
class BaseWindow : public QWidget
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

private:
    Ui::Form *ui;
    void initTitleBar();
    void initdata();
    void paintEvent(QPaintEvent *event);
    void loadStyleSheet(const QString &sheetName);
    void initmenebar();
    void layout();

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

    void on_pushButton_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_treeview_datachanged(QModelIndex, QModelIndex, QVector<int>);

    void onRadiobuttonClicked(QAbstractButton*);//切换radiobutton

protected:
    MyTitleBar* m_titleBar;
private:
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
    int currentItem;//当前项目编号
    int currentItem_c;//检验内容编号
    QButtonGroup* buttongroup;//radiobutton
    QMenuBar * menubar;
    QMenu* file;
    QAction* addDevice;

};

#endif // BASEWINDOW_H
