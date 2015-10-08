#include "team.h"

Team::Team()
    :m_team(""), m_total(0), m_win(0), m_lose(0), m_rating(0)
{
}


Team::Team(const QString &team, unsigned int total, unsigned int win,
           unsigned int lose, unsigned int rating)
    :m_team(team), m_total(total), m_win(win), m_lose(lose), m_rating(rating)
{
}

QString Team::GetTeam() const
{
    return m_team;
}

unsigned int Team::GetTotalGames() const
{
    return m_total;
}

unsigned int Team::GetWins() const
{
    return m_win;
}

unsigned int Team::GetLoses() const
{
    return m_lose;
}

unsigned int Team::GetRating() const
{
    return m_rating;
}


