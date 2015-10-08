#ifndef TEAM
#define TEAM

#include <QString>

class Team
{
public:
    Team();
    Team(const QString &team, unsigned int total,
         unsigned int win, unsigned int lose, unsigned int rating);
    QString GetTeam() const;
    unsigned int GetTotalGames() const;
    unsigned int GetWins() const;
    unsigned int GetLoses() const;
    unsigned int GetRating() const;

private:
    QString m_team;
    unsigned int m_total;
    unsigned int m_win;
    unsigned int m_lose;
    unsigned int m_rating;
};

#endif // TEAM

