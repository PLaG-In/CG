/********************************************************************************
** Form generated from reading UI file 'input.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_input
{
public:
    QSpinBox *winBox;
    QLineEdit *teamEdit;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *loseBox;
    QSpinBox *totalBox;
    QSpinBox *ratingBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *input)
    {
        if (input->objectName().isEmpty())
            input->setObjectName(QStringLiteral("input"));
        input->resize(474, 109);
        winBox = new QSpinBox(input);
        winBox->setObjectName(QStringLiteral("winBox"));
        winBox->setGeometry(QRect(110, 30, 71, 22));
        winBox->setMaximum(9999);
        teamEdit = new QLineEdit(input);
        teamEdit->setObjectName(QStringLiteral("teamEdit"));
        teamEdit->setGeometry(QRect(20, 30, 71, 20));
        buttonBox = new QDialogButtonBox(input);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 70, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(input);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 47, 13));
        label_2 = new QLabel(input);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 10, 47, 13));
        loseBox = new QSpinBox(input);
        loseBox->setObjectName(QStringLiteral("loseBox"));
        loseBox->setGeometry(QRect(200, 30, 71, 22));
        loseBox->setMaximum(9999);
        totalBox = new QSpinBox(input);
        totalBox->setObjectName(QStringLiteral("totalBox"));
        totalBox->setGeometry(QRect(290, 30, 71, 22));
        totalBox->setMaximum(9999);
        ratingBox = new QSpinBox(input);
        ratingBox->setObjectName(QStringLiteral("ratingBox"));
        ratingBox->setGeometry(QRect(380, 30, 71, 22));
        ratingBox->setMaximum(9999);
        label_3 = new QLabel(input);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 10, 47, 13));
        label_4 = new QLabel(input);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(294, 9, 61, 16));
        label_5 = new QLabel(input);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(390, 10, 47, 13));

        retranslateUi(input);

        QMetaObject::connectSlotsByName(input);
    } // setupUi

    void retranslateUi(QDialog *input)
    {
        input->setWindowTitle(QApplication::translate("input", "Dialog", 0));
        label->setText(QApplication::translate("input", "Team", 0));
        label_2->setText(QApplication::translate("input", "Wins", 0));
        label_3->setText(QApplication::translate("input", "Loses", 0));
        label_4->setText(QApplication::translate("input", "Total games", 0));
        label_5->setText(QApplication::translate("input", "Rating", 0));
    } // retranslateUi

};

namespace Ui {
    class input: public Ui_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
