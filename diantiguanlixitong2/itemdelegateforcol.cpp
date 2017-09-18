#include "itemdelegateforcol.h"
#include <QPainter>
#include <QTextOption>
#include <QPushButton>
#include <QApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QDialog>
#include <QDesktopWidget>

ItemDelegateforCol::ItemDelegateforCol(int _colunm,QObject* parent):
    QStyledItemDelegate(parent)
{
        colunm =_colunm;

        pixPath = QString("");
}

void ItemDelegateforCol::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(colunm==index.column())
    {
        QStyleOptionButton* button = m_btns.value(index);
            if (!button) {
                button = new QStyleOptionButton();
                button->rect = option.rect.adjusted(4, 4, -4, -4);
                button->text = option.text;
                button->state |= QStyle::State_Enabled;

                (const_cast<ItemDelegateforCol *>(this))->m_btns.insert(index, button);
            }
            painter->save();

            if (option.state & QStyle::State_Selected) {
                //painter->drawRect(option.rect);

            }
            painter->restore();
            QApplication::style()->drawControl(QStyle::CE_PushButton, button, painter);
    }

}

bool ItemDelegateforCol::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(colunm==index.column())
    {
        if (event->type() == QEvent::MouseButtonPress) {

                QMouseEvent* e =(QMouseEvent*)event;

                if (option.rect.adjusted(4, 4, -4, -4).contains(e->x(), e->y()) && m_btns.contains(index)) {
                    m_btns.value(index)->state |= QStyle::State_Sunken;
                }
            }
            if (event->type() == QEvent::MouseButtonRelease) {
                QMouseEvent* e =(QMouseEvent*)event;

                if (option.rect.adjusted(4, 4, -4, -4).contains(e->x(), e->y()) && m_btns.contains(index)) {
                    m_btns.value(index)->state &= (~QStyle::State_Sunken);

//                    QDialog *d = new QDialog();
//                    d->setGeometry(0, 0, 200, 200);
//                    d->move(QApplication::desktop()->screenGeometry().center() - d->rect().center());
//                    d->show();
                }
            }
    }

}


void ItemDelegateforCol::setPixPath(const QString &path)
{
    pixPath = path;
}
