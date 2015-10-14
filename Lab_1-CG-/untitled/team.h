#ifndef TEAM
#define TEAM

#include <QString>

class Team
{
public:
    Team();
    Team(const QString &team, unsigned int rating);
    QString GetTeam() const;
    unsigned int GetRating() const;

private:
    QString m_team;
    unsigned int m_rating;
};

#endif // TEAM

