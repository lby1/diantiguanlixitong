#ifndef GLOBALVAR_H
#define GLOBALVAR_H
#include <QHash>


class globalvar
{
public:
    globalvar();
    static QHash<QString,QString> userInfo;
    static QList<QHash<QString,QString> > deviceList;//待审核设备列表
};
#endif // GLOBALVAR_H
