#include "input.h"
#include "ui_input.h"

input::input(QWidget *parent) :
    QDialog(parent),
    NewTeamRow(Team("", 0, 0, 0, 0)),
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
    if (!ui->teamEdit->text().isEmpty()
            && ui->winBox->value() >= 0
            && ui->loseBox->value() >= 0
            && ui->totalBox->value() >= 0
            && ui->ratingBox->value() > 0)
    {
            NewTeamRow = Team(ui->teamEdit->text(), ui->winBox->value(),
                           ui->loseBox->value(), ui->totalBox->value(),
                           ui->ratingBox->value());
    }
}

void input::on_buttonBox_rejected()
{
    this->reject();
    close();
}
