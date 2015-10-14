#include "team.h"

Team::Team()
    :m_team(""), m_rating(0)
{
}


Team::Team(const QString &team, unsigned int rating)
    :m_team(team), m_rating(rating)
{
}

QString Team::GetTeam() const
{
    return m_team;
}

unsigned int Team::GetRating() const
{
    return m_rating;
}


