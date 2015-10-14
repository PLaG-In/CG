#include "input.h"
#include "ui_input.h"

input::input(QWidget *parent) :
    QDialog(parent),
    newTeamRow(Team()),
    ui(new Ui::input)
{
    ui->setupUi(this);
    QDialog::setFixedSize(size());

}

input::~input()
{
    delete ui;
}

void input::on_buttonBox_accepted()
{
    if (!ui->teamEdit->text().isEmpty() && ui->ratingBox->value() > 0)
    {
            newTeamRow = Team(ui->teamEdit->text(), ui->ratingBox->value());
            accept();
    }
}

void input::on_buttonBox_rejected()
{
    this->reject();
    close();
}
