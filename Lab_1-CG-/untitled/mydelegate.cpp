#include "mydelegate.h"

TeamModel::TeamModel(QObject *parent) :
    QAbstractTableModel(parent), wasChanged(false)
{

}

int TeamModel::rowCount(const QModelIndex&) const
{
    return m_data.count();
}

int TeamModel::columnCount(const QModelIndex&) const
{
    return 5;
}

QVariant TeamModel::data(const QModelIndex &index, int role) const
{
       if (role != Qt::DisplayRole && role != Qt::EditRole)
           return QVariant();

       const Team &tm = m_data[index.row()];
       switch (index.column())
       {
        case 0: return tm.GetTeam();
        case 1: return tm.GetTotalGames();
        case 2: return tm.GetWins();
        case 3: return tm.GetLoses();
        case 4: return tm.GetRating();
        default: return QVariant();
       };
 }

QVariant TeamModel::headerData(int section, Qt::Orientation orientation, int role) const
{
       if (orientation != Qt::Horizontal)
           return QVariant();
       if (role != Qt::DisplayRole)
           return QVariant();

       switch (section)
       {
        case 0: return "Team";
        case 1: return "Total games";
        case 2: return "Win";
        case 3: return "Lose";
        case 4: return "Rating";
        default: return QVariant();
       }
}

void TeamModel::append(const Team &team)
{
       beginInsertRows(QModelIndex(), m_data.count(), m_data.count());
       m_data.append(team);
       endInsertRows();
       wasChanged = true;
       m_save->setEnabled(true);
}

Qt::ItemFlags TeamModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool TeamModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        auto team = m_data[index.row()].GetTeam();
        auto win = m_data[index.row()].GetWins();
        auto lose = m_data[index.row()].GetLoses();
        auto total = m_data[index.row()].GetTotalGames();
        auto rating = m_data[index.row()].GetRating();
        Team newTeam;
        if (index.column() == 0)
        {
            if (value.toString().length() == 0)
            {
                return false;
            }

            auto newTm = value.toString();
            if (team != newTm)
            {
                wasChanged = true;
                m_save->setEnabled(true);
            }

            newTeam = Team(newTm, win, lose, total, rating);
        }
        if (index.column() == 1)
        {
            unsigned int newWin = value.value<unsigned int>();
            if (win != newWin)
            {
                wasChanged = true;
                m_save->setEnabled(true);
            }

            newTeam = Team(team, newWin, lose, total, rating);
        }
        if (index.column() == 2)
        {
            unsigned int newLose = value.value<unsigned int>();
            if (lose != newLose)
            {
                wasChanged = true;
                m_save->setEnabled(true);
            }

            newTeam = Team(team, win, newLose, total, rating);
        }
        if (index.column() == 3)
        {
            unsigned int newTotal = value.value<unsigned int>();
            if (total != newTotal)
            {
                wasChanged = true;
                m_save->setEnabled(true);
            }

            newTeam = Team(team, win, lose, newTotal, rating);
        }
        if (index.column() == 4)
        {
            unsigned int newRating = value.value<unsigned int>();
            if (rating != newRating)
            {
                wasChanged = true;
                m_save->setEnabled(true);
            }

            newTeam = Team(team, win, lose, total, newRating);
        }
        m_data.replace(index.row(), newTeam);
        emit dataChanged(index, index);
        return true;
    }

    return false;
}
