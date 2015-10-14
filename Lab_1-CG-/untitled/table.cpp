#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent) :
    QMainWindow(parent),
   // m_stack(new QUndoStack(this)),
    ui(new Ui::table)
{
    ui->setupUi(this);
    ui->tableView->move(0, 0);
    m_model = new TeamModel(ui->actionSave, this);
    ui->tableView->setModel(m_model);
    ui->actionSave->setEnabled(false);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    m_isSomethingChanged = false;
   // QObject::connect(m_model, SIGNAL(SomethingChanged()), this, SLOT(on_SomethingChanged()));
}

table::~table()
{
    delete ui;
    if (m_model)
    {
        delete m_model;
    }
    /*if (m_stack)
    {
        delete m_stack;
    }*/
}

void table::resizeEvent(QResizeEvent*)
{
    ui->tableView->resize(size());
    ui->tableView->setColumnWidth(0, ui->tableView->width() / 2);
}

void table::on_actionInsert_row_triggered()
{
    input dlg;
    dlg.setModal(true);
    if (dlg.exec() == dlg.Accepted)
    {
        m_model->append(dlg.newTeamRow);
    }
}

void table::on_actionDelete_row_triggered()
{
    m_model->RemoveLast();
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

void table::on_SomethingChanged()
{
    m_isSomethingChanged = true;
    ui->actionSave->setEnabled(true);
}

void table::on_actionAbout_Application_triggered()
{
    QMessageBox box;
    box.setWindowTitle("About author");
    box.setText("Statics Editor");
    box.setInformativeText("Copyright © 2015 Alitov Vladimir");
    box.exec();
}

