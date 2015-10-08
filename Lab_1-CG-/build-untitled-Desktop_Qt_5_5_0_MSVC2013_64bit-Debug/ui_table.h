/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_table
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionInsert_row;
    QAction *actionDelete_row;
    QAction *actionAbout_Application;
    QWidget *centralWidget;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuInsert;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *table)
    {
        if (table->objectName().isEmpty())
            table->setObjectName(QStringLiteral("table"));
        table->resize(560, 620);
        actionOpen = new QAction(table);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew = new QAction(table);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(table);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(table);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionInsert_row = new QAction(table);
        actionInsert_row->setObjectName(QStringLiteral("actionInsert_row"));
        actionDelete_row = new QAction(table);
        actionDelete_row->setObjectName(QStringLiteral("actionDelete_row"));
        actionAbout_Application = new QAction(table);
        actionAbout_Application->setObjectName(QStringLiteral("actionAbout_Application"));
        centralWidget = new QWidget(table);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 20, 531, 541));
        table->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(table);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 560, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        table->setMenuBar(menuBar);
        mainToolBar = new QToolBar(table);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        table->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(table);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        table->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuInsert->addAction(actionInsert_row);
        menuInsert->addAction(actionDelete_row);
        menuAbout->addAction(actionAbout_Application);

        retranslateUi(table);

        QMetaObject::connectSlotsByName(table);
    } // setupUi

    void retranslateUi(QMainWindow *table)
    {
        table->setWindowTitle(QApplication::translate("table", "table", 0));
        actionOpen->setText(QApplication::translate("table", "Open...", 0));
        actionOpen->setShortcut(QApplication::translate("table", "Ctrl+O", 0));
        actionNew->setText(QApplication::translate("table", "New", 0));
        actionNew->setShortcut(QApplication::translate("table", "Ctrl+N", 0));
        actionSave->setText(QApplication::translate("table", "Save", 0));
        actionSave->setShortcut(QApplication::translate("table", "Ctrl+S", 0));
        actionSave_as->setText(QApplication::translate("table", "Save as...", 0));
        actionInsert_row->setText(QApplication::translate("table", "Insert row", 0));
        actionDelete_row->setText(QApplication::translate("table", "Delete row", 0));
        actionAbout_Application->setText(QApplication::translate("table", "About Application", 0));
        menuFile->setTitle(QApplication::translate("table", "File", 0));
        menuInsert->setTitle(QApplication::translate("table", "Insert", 0));
        menuAbout->setTitle(QApplication::translate("table", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class table: public Ui_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
