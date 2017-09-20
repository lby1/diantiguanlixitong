#include "globalvar.h"

globalvar::globalvar()
{

}
QHash<QString,QString> globalvar::userInfo;
QList<QHash<QString,QString> > globalvar::deviceList;
QList<QHash<QString,QString> > globalvar::tongguoList;//通过审核设备列表
QList<QHash<QString,QString> > globalvar::weitongguoList;//未通过审核设备列表
