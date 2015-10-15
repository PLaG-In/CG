#include "mydelegate.h"

TeamModel::TeamModel(QAction *save, QObject *parent) :
    QAbstractTableModel(parent), smthChanged(false), m_save(save)
{
}

int TeamModel::rowCount(const QModelIndex&) const
{
    return m_data.size();
}

int TeamModel::columnCount(const QModelIndex&) const
{
    return 2;
}

QVariant TeamModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    const Team &team = m_data[index.row()];

    if (index.column() == 0)
        return team.GetTeam();
    else
        return team.GetRating();
 }

QVariant TeamModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal)
        return QVariant();
    if (role != Qt::DisplayRole)
        return QVariant();

    if (section == 0)
        return "Team";
    else
        return "Rating";
}

void TeamModel::append(const Team &team)
{
    beginInsertRows(QModelIndex(), m_data.count(), m_data.count());
    m_data.append(team);
    endInsertRows();
    smthChanged = true;
    m_save->setEnabled(true);

}

Qt::ItemFlags TeamModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool TeamModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return QAbstractTableModel::setData(index, value, role);

    auto team = m_data[index.row()].GetTeam();
    auto rating = m_data[index.row()].GetRating();
    Team newTeam;
    if (index.column() == 0)
    {
        newTeam = Team(value.toString(), rating);
        smthChanged = true;
        m_save->setEnabled(true);
    }
    else
    {
        newTeam = Team(team, value.toUInt());
        smthChanged = true;
        m_save->setEnabled(true);
    }

    m_data.replace(index.row(), newTeam);
    emit layoutChanged();
    return true;
}

QList<Team> TeamModel::GetData() const
{
    return m_data;
}

void TeamModel::InsertLast(const Team &team)
{
    beginInsertRows(QModelIndex(), m_data.count(), m_data.count());
    m_data.append(team);
    endInsertRows();
    emit layoutChanged();
}

void TeamModel::RemoveLast()
{
    beginRemoveRows(QModelIndex(), 0, m_data.count());
    m_data.removeLast();
    endRemoveRows();
    emit layoutChanged();
}

void TeamModel::ChangeData(const QModelIndex &indexRow, const QModelIndex &indexCol, const Team &team)
{
    m_data.replace(indexRow.row(), team);
    emit dataChanged(indexRow, indexRow);
    emit dataChanged(indexCol, indexCol);
    emit layoutChanged();
}

void TeamModel::clear()
{
    m_data.clear();
    emit layoutChanged();
}
