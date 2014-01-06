#include <iostream>
using namespace std;

struct Point
{
  int i;
  int j;
};

static Point minus_point = { -1, -1 };

class Map
{
  public:
    Map(int height, int width);
    ~Map();

  public:
    int Can_go_num(Point p = minus_point);

  private:
    bool CheckIndex(const Point& p);
    bool isBlack(const Point& p);
    bool CanMove(const Point& p);

  private:
    char** m_map;   //  '.' = black, '#' = red, '@' = start, 'x' = already
    int m_height;
    int m_width;
    Point m_start;
};

Map::Map(int height, int width)
{
  m_height = height;
  m_width = width;

  m_map = new char*[m_height];
  for (int i = 0; i < m_height; ++i)
  {
    m_map[i] = new char[m_width];
  }

  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      cin >> m_map[i][j];
      if (m_map[i][j] == '@')
      {
        m_start.i = i;
        m_start.j = j;
      }
    }
  }
}

Map::~Map()
{
  for (int i = 0; i < m_height; ++i)
  {
    delete[] m_map[i];
  }
  delete[] m_map;
}

int Map::Can_go_num(Point p)
{
  int result = 1;
  if (p.i == -1)
  {
    p = m_start;
  }
  m_map[p.i][p.j] = 'x';
  Point buf_ps[4] = {
    { p.i, p.j-1 },
    { p.i, p.j+1 },
    { p.i-1, p.j },
    { p.i+1, p.j },
  };
  for (Point buf_p : buf_ps)
  {
    if (CanMove(buf_p) )
    {
      result += Can_go_num(buf_p);
    }
  }

  return result;
}

inline bool Map::CheckIndex(const Point& p)
{
  return (0 <= p.i and p.i < m_height) and (0 <= p.j and p.j < m_width);
}

inline bool Map::isBlack(const Point& p)
{
  return m_map[p.i][p.j] == '.';
}

inline bool Map::CanMove(const Point& p)
{
  return CheckIndex(p) && isBlack(p);
}

int main(void)
{
  int height, width;
  while (true)
  {
    cin >> width >> height;
    if (height == 0 && width == 0) break;
    Map map(height, width);
    cout << map.Can_go_num() << endl;
  }
  return 0;
}