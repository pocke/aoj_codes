#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Team
{
  public:
    Team(char name, const vector<int>& scores, int index);

    bool operator<(const Team& right) const;
    char Name() const;

  private:
    char m_name;
    int m_win;
    int m_lose;
    int m_index;
};

Team::Team(char name, const vector<int>& scores, int index) :
  m_name(name), m_win(0), m_lose(0), m_index(index)
{
  for (auto score : scores)
  {
    switch(score)
    {
      case 0:
        m_win++;
        break;
      case 1:
        m_lose++;
        break;
    }
  }
}

bool Team::operator<(const Team& right) const
{
  return m_win == right.m_win ? ( m_lose == right.m_lose ? m_index > right.m_index : m_lose > right.m_lose ) : m_win < right.m_win;
}

char Team::Name() const
{
  return m_name;
}

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<Team> teams;
    for (int i = 0; i < n; ++i)
    {
      char name;
      cin >> name;
      vector<int> scores;
      for (int j = 0, buf; j < n - 1; ++j)
      {
        cin >> buf;
        scores.push_back(buf);
      }
      teams.push_back(Team(name, scores, i) );
    }

    sort(teams.rbegin(), teams.rend() );
    for (auto t : teams)
    {
      cout << t.Name() << endl;
    }
  }
  return 0;
}