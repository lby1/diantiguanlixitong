#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QWidget>

namespace Ui {
class deviceInfo;
}
enum Type{
    Jiandu=1,
    Dingqi=2
};
class deviceInfo : public QWidget
{
    Q_OBJECT

public:
    explicit deviceInfo(int deviceRow,QWidget *parent = 0);
    ~deviceInfo();
    void init();
    void setData1(int row,int col,QString value);//table1
    void setData2(int row,int col,QString value);//tabel2
private:
    Ui::deviceInfo *ui;
    void paintEvent(QPaintEvent *event);
    Type _type;
    int _devicerow;
};

#endif // DEVICEINFO_H
