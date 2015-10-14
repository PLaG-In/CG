#ifndef TABLE_H
#define TABLE_H

#include <QTextStream>
#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QAbstractItemModel>
#include <QFile>
#include <QFileDialog>
#include <QTextCodec>
#include <QFormLayout>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "mydelegate.h"
#include "input.h"

namespace Ui {
class table;
}
class TeamModel;

class table : public QMainWindow
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();

public slots:
     void on_SomethingChanged();

private slots:
    void on_actionInsert_row_triggered();

    void on_actionDelete_row_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionNew_triggered();

    void on_actionAbout_Application_triggered();

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    Ui::table *ui;
    TeamModel *m_model;
    bool m_isSomethingChanged;
    //QUndoStack *m_stack;

};

#endif // TABLE_H
