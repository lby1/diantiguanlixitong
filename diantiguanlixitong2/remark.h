#ifndef REMARK_H
#define REMARK_H

#include <QDialog>

namespace Ui {
class remark;
}

class remark : public QDialog
{
    Q_OBJECT

public:
    explicit remark(int row,int col,QWidget *parent = 0);
    ~remark();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::remark *ui;
    int _row,_col;
};

#endif // REMARK_H
