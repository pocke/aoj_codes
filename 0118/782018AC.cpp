#include <iostream>
#include <vector>
using namespace std;

struct Point
{
  int i;
  int j;
};

class Orchard
{
  public:
    Orchard(int height, int width);
    
    int section_num();

  private:
    bool CheckIndex(const Point& p) const;
    void Passed(const Point& p, char tree);

  private:
    const int m_height;
    const int m_width;
    vector<vector<char>> m_orchard;
};

Orchard::Orchard(int height, int width) :
  m_height(height), m_width(width), m_orchard(height, vector<char>(width))
{
  for (auto& line : m_orchard)
  {
    for (auto& tree : line)
    {
      cin >> tree;
    }
  }
}

int Orchard::section_num()
{
  int result = 0;
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      if (m_orchard[i][j] == 'x') continue;
      ++result;
      Passed({ i, j }, m_orchard[i][j]);
    }
  }
  return result;
}

inline bool Orchard::CheckIndex(const Point& p) const
{
  return (0 <= p.i and p.i < m_height) and (0 <= p.j and p.j < m_width);
}

void Orchard::Passed(const Point& p, char tree)
{
  if (m_orchard[p.i][p.j] != tree) return;

  m_orchard[p.i][p.j] = 'x';

  vector<Point> buf_ps;
  buf_ps.push_back( { p.i, p.j + 1} );
  buf_ps.push_back( { p.i, p.j - 1} );
  buf_ps.push_back( { p.i + 1, p.j} );
  buf_ps.push_back( { p.i - 1, p.j} );
  for (auto buf_p : buf_ps)
  {
    if (CheckIndex(buf_p))
    {
      Passed(buf_p, tree);
    }
  }
}

int main(void)
{
  while (true)
  {
    int height, width;
    cin >> height >> width;
    if (height == 0 and width == 0) break;

    Orchard orchard(height, width);
    cout << orchard.section_num() << endl;
  }
  return 0;
}