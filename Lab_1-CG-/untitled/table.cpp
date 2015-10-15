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

void table::on_actionAbout_Application_triggered()
{
    QMessageBox box;
    box.setWindowTitle("About author");
    box.setText("Statics Editor");
    box.setInformativeText("Copyright © 2015 Alitov Vladimir");
    box.exec();
}


void table::on_actionSave_as_triggered()
{
    SaveAs();
}

bool table::SaveRequest()
{
    auto confDlg = QMessageBox::question(this, tr("Save request"), tr("Do you want to save changes?"),
                                  QMessageBox::Yes|QMessageBox::No);
    return (confDlg == QMessageBox::Yes);
}

void table::Save(QString filePath)
{
    //QString filePath = QFileDialog::getSaveFileName(this,tr("Save"),QString(),tr("JSON Files (*.json)"));
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

        if (QFileInfo(filePath).completeSuffix() != "json")
        {
            filePath += ".json";
        }
        QFile f(filePath);
        QJsonObject obj;
        if(f.open(QIODevice::WriteOnly))
        {
            QJsonArray teams, ratings;
            for (int i = 0; i < m_model->rowCount(QModelIndex()); ++i)
            {
                teams.append(m_model->data(m_model->index(i, 0), Qt::DisplayRole).toString());
                ratings.append(m_model->data(m_model->index(i, 1), Qt::DisplayRole).toInt());
            }

            obj["Team"] = teams;
            obj["Rating"] = ratings;

            QJsonDocument doc(obj);
            f.write(doc.toJson());
            f.close();
       /* QStringList strList;
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
        f.close();*/
        }
    }
}

void table::SaveAs()
{
    auto filePath = QFileDialog::getSaveFileName(this, tr("Save file"), QString(), "*.json");
    if (filePath != "")
    {
        Save(filePath);
    }
}

void table::Open()
{
    /* QString filename = QFileDialog::getOpenFileName(this,tr("Open"),QString(),tr("JSON Files (*.json)"));
     QFile f(filename);
     if( f.open( QIODevice::ReadOnly ) )
     {
         QTextStream ts( &f );
         QStringList strList;
         int i = 0;
         f.close();
         }*/
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

         QFile file(fileName);
         file.open(QIODevice::ReadOnly | QIODevice::Text);
         if (!file.isOpen())
         {
             return;
         }

         QString data = file.readAll();
         file.close();

         QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
         if (doc.isNull())
         {
             return;
         }

         auto items = doc.object();
         QJsonArray teams = items.value("Team").toArray();
         QJsonArray ratings = items.value("Rating").toArray();

         if (teams.size() != ratings.size())
         {
             QMessageBox::warning(this, tr("Error"), tr("File is corrupted"));
             return;
         }
         m_model->clear();

         for (int i = 0; i < teams.size(); ++i)
         {
             Team team(teams[i].toString(), ratings[i].toInt());
             m_model->append(team);
         }

         m_fileName = fileName;
         m_model->smthChanged = false;
         ui->actionSave->setEnabled(false);
     }
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
