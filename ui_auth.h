/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Auth
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameField;
    QLabel *passwordLabel;
    QLineEdit *passwordField;
    QPushButton *auth_btn;

    void setupUi(QDialog *Auth)
    {
        if (Auth->objectName().isEmpty())
            Auth->setObjectName(QString::fromUtf8("Auth"));
        Auth->resize(320, 190);
        formLayoutWidget = new QWidget(Auth);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(59, 9, 221, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(formLayoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameField = new QLineEdit(formLayoutWidget);
        usernameField->setObjectName(QString::fromUtf8("usernameField"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameField);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordField = new QLineEdit(formLayoutWidget);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordField);

        auth_btn = new QPushButton(Auth);
        auth_btn->setObjectName(QString::fromUtf8("auth_btn"));
        auth_btn->setGeometry(QRect(100, 150, 119, 32));
        auth_btn->setFlat(false);

        retranslateUi(Auth);

        QMetaObject::connectSlotsByName(Auth);
    } // setupUi

    void retranslateUi(QDialog *Auth)
    {
        Auth->setWindowTitle(QCoreApplication::translate("Auth", "Dialog", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Auth", "\320\233\320\276\320\263\320\270\320\275", nullptr));
#if QT_CONFIG(tooltip)
        usernameField->setToolTip(QCoreApplication::translate("Auth", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
#endif // QT_CONFIG(tooltip)
        passwordLabel->setText(QCoreApplication::translate("Auth", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        auth_btn->setText(QCoreApplication::translate("Auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthDialog: public Ui_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
