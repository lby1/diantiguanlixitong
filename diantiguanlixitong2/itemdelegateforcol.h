#ifndef ITEMDELEGATEFORCOL_H
#define ITEMDELEGATEFORCOL_H
#include <QStyledItemDelegate>
#include <QStyleOptionButton>

class ItemDelegateforCol : public QStyledItemDelegate
{
public:
    ItemDelegateforCol(int _colunm,QObject* parent=0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event,QAbstractItemModel *model,
                                       const QStyleOptionViewItem &option,const QModelIndex &index);
    //QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void setPixPath(const QString &path);
private:
    int colunm;
    QMap<QModelIndex, QStyleOptionButton*> m_btns;
    QString pixPath;
signals:
    void cellclick(QModelIndex);
};

#endif // ITEMDELEGATEFORCOL_H
