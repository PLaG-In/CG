#ifndef INPUT_H
#define INPUT_H

#include <QDialog>
#include "team.h"

namespace Ui {
class input;
}

class input : public QDialog
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = 0);
    ~input();

    Team NewTeamRow;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::input *ui;
};

#endif // INPUT_H
