/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *username;
    QLineEdit *l_username;
    QHBoxLayout *horizontalLayout;
    QLabel *password;
    QLineEdit *l_password;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *log_in;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 259);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 400, 100));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/hp/Desktop/00.png")));
        label_2->setScaledContents(false);
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(284, 0, 111, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(layoutWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));

        horizontalLayout_4->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(layoutWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));

        horizontalLayout_4->addWidget(toolButton_3);

        layoutWidget_2 = new QWidget(Login);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(70, 100, 241, 121));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        username = new QLabel(layoutWidget_2);
        username->setObjectName(QStringLiteral("username"));

        horizontalLayout_2->addWidget(username);

        l_username = new QLineEdit(layoutWidget_2);
        l_username->setObjectName(QStringLiteral("l_username"));

        horizontalLayout_2->addWidget(l_username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        password = new QLabel(layoutWidget_2);
        password->setObjectName(QStringLiteral("password"));

        horizontalLayout->addWidget(password);

        l_password = new QLineEdit(layoutWidget_2);
        l_password->setObjectName(QStringLiteral("l_password"));
        l_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        l_password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(l_password);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        log_in = new QPushButton(layoutWidget_2);
        log_in->setObjectName(QStringLiteral("log_in"));

        horizontalLayout_3->addWidget(log_in);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 230, 381, 20));
        label->setFont(font);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        label_2->setText(QString());
        toolButton_4->setText(QApplication::translate("Login", "\346\234\200\345\260\217\345\214\226", 0));
        toolButton_3->setText(QApplication::translate("Login", "\345\205\263\351\227\255", 0));
        username->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        l_username->setText(QApplication::translate("Login", "\347\224\265\346\242\257\346\243\200\346\265\213\345\215\225\344\275\2153", 0));
        password->setText(QApplication::translate("Login", "\345\257\206  \347\240\201\357\274\232", 0));
        l_password->setText(QApplication::translate("Login", "123123", 0));
        log_in->setText(QApplication::translate("Login", "\347\231\273\351\231\206", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
