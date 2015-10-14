/*#ifndef UNDOREDO_H
#define UNDOREDOTABLE_H

#include <QUndoCommand>
#include <QTableView>
#include "mydelegate.h"
#include "team.h"

class UndoRedoTable : public QUndoCommand
{
public:
    UndoRedoTable(TeamModel *model, unsigned int index, Team team, bool wasInsertAct);

signals:

public slots:
    void redo();
    void undo();

private:
    TeamModel *m_model;
    bool m_wasInsertAct;
    Team m_team;
    Team m_prevTeam;
    unsigned int m_index;
};

#endif // UNDOREDOTABLE_H
*/
