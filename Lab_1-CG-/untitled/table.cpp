#include "table.h"
#include "ui_table.h"
#include "qdebug.h"
#include <QAbstractItemModel>

table::table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    ui->tableView->move(0, 0);
    model = new TeamModel(this);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

table::~table()
{
    delete ui;
    if (model)
    {
        delete model;
    }
}

void table::on_actionInsert_row_triggered()
{
    input dlg;

   // model->append(Team("",0,0,0,0));
    dlg.setModal(true);
    if (dlg.exec() == QDialog::Accepted)
    {
        model->append(dlg.NewTeamRow);
    }
}

void table::resizeEvent(QResizeEvent*)
{
    ui->tableView->resize(size());
    ui->tableView->setColumnWidth(0, ui->tableView->width() / 5);
}

void table::on_actionDelete_row_triggered()
{
    /*QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("The question ?"));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    for(int i = 0; i < 4; ++i) {
        QLineEdit *lineEdit = new QLineEdit(&dialog);
        QString label = QString("Value %1").arg(i + 1);
        form.addRow(label, lineEdit);

        fields << lineEdit;
    }

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        foreach(QLineEdit * lineEdit, fields) {
            qDebug() << lineEdit->text();
        }
    }*/
}

void table::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open"),"c:/",tr("JSON Files (*.json)"));
    QFile f(filename);
    if( f.open( QIODevice::ReadOnly ) )
    {
        QTextStream ts( &f );
        QStringList strList;
        int i = 0;
        f.close();
        }
}



void table::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save"),"c:/",tr("JSON Files (*.json)"));
    QFile f(filename);
    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream ts(&f);
        QStringList strList;
        strList << "" "";
        for(int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)//запись заголовков таблицы
        {
            strList << ui->tableView->model()->headerData(c, Qt::Horizontal).toString();
        }
        ts << strList.join(" ")+"\n";
        for(int r = 0; r < ui->tableView->verticalHeader()->count(); ++r)//запись данных таблицы
        {
            strList.clear();
            strList << ui->tableView->model()->headerData(r, Qt::Vertical).toString();
            for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
            {
                strList << ui->tableView->model()->data(ui->tableView->model()->index(r, c), Qt::DisplayRole).toString();
            }
            ts << strList.join(" ")+"\n";
        }
        f.close();
    }
}

void table::on_actionNew_triggered()
{

}

void table::on_actionAbout_Application_triggered()
{
    QMessageBox box;
    box.setWindowTitle("About author");
    box.setText("Statics Editor");
    box.setInformativeText("Copyright © 2015 Alitov Vladimir");
    box.exec();
}
