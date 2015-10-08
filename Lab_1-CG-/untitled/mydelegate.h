#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QAbstractTableModel>
#include <QList>
#include <QAction>
#include "team.h"

class TeamModel : public QAbstractTableModel
{
public:
    TeamModel(QObject *parent = 0);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void append(const Team &team);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool wasChanged;
private:
    QList<Team> m_data;
    QAction *m_save;
};

#endif // MYDELEGATE_H
