/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(306, 201);
        pushButton = new QPushButton(about);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 160, 75, 23));
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(26, 12, 251, 131));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Dialog", 0));
        pushButton->setText(QApplication::translate("about", "OK", 0));
        label->setText(QApplication::translate("about", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic; color:#000000;\">Copyright \302\251 2015</span></p><p align=\"center\"><span style=\" font-size:18pt; font-style:italic; color:#000000;\"> Alitov Vladimir</span></p><p align=\"center\"><span style=\" font-size:18pt; font-style:italic; color:#000000;\">PS-31</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
