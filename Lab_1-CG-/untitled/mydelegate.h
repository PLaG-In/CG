#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QAbstractTableModel>
#include <QList>
#include <QAction>
#include <QUndoStack>
#include "team.h"
#include "undoredotable.h"

class TeamModel : public QAbstractTableModel
{
public:
    TeamModel(QAction *save, QObject *parent = 0);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void append(const Team &team);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QList<Team> GetData() const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    void InsertLast(const Team &team);
    void RemoveLast();
    void ChangeData(const QModelIndex &indexRow, const QModelIndex &indexCol, const Team &team);
    void clear();
    bool smthChanged;
private:
    QList<Team> m_data;
    QAction *m_save;
   // QUndoStack *m_stack;
};

#endif // MYDELEGATE_H
