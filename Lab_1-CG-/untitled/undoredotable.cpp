/*#include "undoredotable.h"

UndoRedoTable::UndoRedoTable(TeamModel *model, unsigned int index,
                   Team team, bool wasInsertAct)
    : m_model(model), m_index(index), m_team(team), m_wasInsertAct(wasInsertAct)
{
    if (index >= m_model->rowCount(QModelIndex()))
    {
        m_prevTeam = Team();
    }
    else
    {
        QModelIndex indexRow = m_model->index(index, 0);
        QModelIndex indexCol = m_model->index(index, 1);

        QString newTeam = m_model->data(indexRow, Qt::DisplayRole).toString();
        unsigned int rating = m_model->data(indexCol, Qt::DisplayRole).toInt();
        m_prevTeam = Team(newTeam, rating);
    }
}

void UndoRedoTable::undo()
{
    if (m_wasInsertAct)
    {
        m_model->RemoveLast();
    }
    else
    {
        QModelIndex indexTeam = m_model->index(m_index, 0);
        QModelIndex indexRating = m_model->index(m_index, 1);

        m_model->ChangeData(indexTeam, indexRating, m_prevRating);
    }
}

void UndoRedoTable::redo()
{
    if (m_wasInsertAct)
    {
        m_model->InsertLast(m_team);
    }
    else
    {
        QModelIndex indexTeam = m_model->index(m_index, 0);
        QModelIndex indexRating = m_model->index(m_index, 1);

        m_model->ChangeData(indexTeam, indexRating, m_rating);
    }
}

*/
