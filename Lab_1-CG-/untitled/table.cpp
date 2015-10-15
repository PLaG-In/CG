#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::table),
    m_fileName("")
{
    ui->setupUi(this);
    ui->tableView->move(0, 0);
    m_model = new TeamModel(ui->actionSave, this);
    ui->tableView->setModel(m_model);
    ui->actionSave->setEnabled(false);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

table::~table()
{
    delete ui;
    if (m_model)
    {
        delete m_model;
    }
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
    Open();
}

void table::on_actionSave_triggered()
{
    Save();
}

void table::on_actionNew_triggered()
{
    New();
}

void table::on_actionSave_as_triggered()
{
    SaveAs();
}

void table::on_actionAbout_Application_triggered()
{
    QMessageBox box;
    box.setWindowTitle("About author");
    box.setText("Statistics Editor");
    box.setInformativeText("Copyright © 2015 Alitov Vladimir");
    box.exec();
}

bool table::SaveRequest()
{
    auto confirmDlg = QMessageBox::question(this, tr("Save request"), tr("Do you want to save changes?"),
                                  QMessageBox::Yes|QMessageBox::No);
    return (confirmDlg == QMessageBox::Yes);
}

void table::Save(QString filePath)
{
    if (m_model->smthChanged || filePath != "")
    {
        if (m_fileName == "" && filePath == "")
        {
            SaveAs();
            return;
        }
        if (filePath == "")
        {
            filePath = m_fileName;
        }
        QFile f(filePath);
        if(f.open(QIODevice::WriteOnly))
        {
            QVariantMap data;
            for (int i = 0; i < m_model->rowCount(QModelIndex()); ++i)
            {
                data.insert(m_model->data(m_model->index(i, 0), Qt::DisplayRole).toString(),
                            m_model->data(m_model->index(i, 1), Qt::DisplayRole).toInt());
            }
            QJsonDocument doc;
            f.write(doc.fromVariant(data).toJson());
            f.close();
        }
        m_model->smthChanged = false;
        ui->actionSave->setEnabled(false);
    }
}

void table::SaveAs()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("Open"),QString(),tr("JSON Files (*.json)"));
    if (filePath != "")
    {
        Save(filePath);
    }
}

void table::Open()
{
    if (m_model->smthChanged)
    {
        if (SaveRequest())
        {
            Save();
        }
    }
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open"),QString(),tr("JSON Files (*.json)"));
    if (fileName == "")
    {
        return;
    }
    QFile f(fileName);
    QString data = "";
    if(f.open(QIODevice::ReadOnly))
    {
        data = f.readAll();
        f.close();
    }
    QJsonParseError  parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8(), &parseError);
    if(parseError.error)
    {
        QMessageBox::warning(this, tr("Error"), tr("Parse error"));
        return;
    }
    auto items = doc.object();
    m_model->clear();
    for (QJsonObject::Iterator iter = items.begin(); iter != items.end(); ++iter)
    {
        Team newTeam(iter.key(), iter.value().toInt());
        m_model->append(newTeam);
    }

    m_fileName = fileName;
    m_model->smthChanged = false;
    ui->actionSave->setEnabled(false);
}

void table::New()
{
    if (m_model->smthChanged)
    {
        if (SaveRequest())
        {
            if (m_fileName == "")
            {
                SaveAs();
            }
            else
            {
                Save();
            }
        }
    }
    m_fileName = "";
    m_model->clear();
    m_model->smthChanged = false;
}

void table::closeEvent(QCloseEvent*)
{
    if(m_model->smthChanged)
    {
      if(SaveRequest())
      {
          Save();
      }
    }
}
