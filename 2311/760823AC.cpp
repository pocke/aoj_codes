#include <iostream>
#include <algorithm>
using namespace std;

struct Point    //  x, y
{
  int x;
  int y;
};

//  --------------------------------class Points
class Points
{
  public:
    Points(int n = 64);
    ~Points();
    Point Get(int i);
    void Set(int x, int y, int i);
    int Size();
    void Add_last(int x, int y);
    void Add_last(Points& other);
    void operator=(const Points& other);

  private:
    Point* m_points;
    int m_size;
};

Points::Points(int n)
{
  m_points = new Point[n];
  m_size = 0;
}

Points::~Points()
{
  delete[] m_points;
}

inline Point Points::Get(int i)
{
  return m_points[i];
}

inline void Points::Set(int x, int y, int i)
{
  m_points[i].x = x;
  m_points[i].y = y;
  ++m_size;
}

inline int Points::Size()
{
  return m_size;
}

void Points::Add_last(int x, int y)
{
  Set(x, y, m_size);
}

void Points::Add_last(Points& other)
{
  Point buf;
  for (int i = 0, size = other.Size(); i < size; ++i)
  {
    buf = other.Get(i);
    Add_last(buf.x, buf.y);
  }
}

void Points::operator=(const Points& other)
{
  Point* new_points = new Point[64];

  delete[] m_points;
  m_points = new_points;
  m_size = other.m_size;

  copy(other.m_points, other.m_points + m_size, m_points);
}

//  --------------------------------class TableCloth
class TableCloth
{
  public:
    TableCloth();
    ~TableCloth();

  public:
    bool Turn();
    void Show() const;

  private:
    bool put_coockie(Points& reverse_list);
    void reverse_cookie(int x, int y);
    void Find_place(Point& start, int x_dir, int y_dir, char cookie, Points& p);
    bool CheckIndex(int i, int j);

  private:
    char** m_table_cloth;
    bool m_turn_player;   //  true => マミ, false => CHARLOTTE
};

TableCloth::TableCloth()
{
  m_turn_player = true;
  m_table_cloth = new char*[8];
  for (int i = 0; i < 8; ++i)
  {
    m_table_cloth[i] = new char[8];
  }

  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      cin >> m_table_cloth[i][j];
    }
  }
}

TableCloth::~TableCloth()
{
  for (int i = 0; i < 8; ++i)
  {
    delete[] m_table_cloth[i];
  }
  delete[] m_table_cloth;
}

bool TableCloth::Turn()
{
  Points reverse_list;
  if (! put_coockie(reverse_list) )
  {
    m_turn_player = !m_turn_player;
    return false;
  }

  for (int i = 0, size = reverse_list.Size(); i < size; ++i)
  {
    reverse_cookie(reverse_list.Get(i).x, reverse_list.Get(i).y);
  }

  m_turn_player = !m_turn_player;
  return true;
}

void TableCloth::Show() const
{
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      cout << m_table_cloth[i][j];
    }
    cout << endl;
  }
}

bool TableCloth::put_coockie(Points& reverse_list)
{
  char cookie = m_turn_player ? 'o' : 'x';
  Point put_point = { -1, -1, };

  int start_i_j  = ( m_turn_player ? 0 : 7 );
  int end_i_j    = ( m_turn_player ? 8 : -1);
  int change_num = ( m_turn_player ? 1 : -1);
  for (int i = start_i_j; i != end_i_j; i += change_num)
  {
    for (int j = start_i_j; j != end_i_j; j += change_num)
    {
      if ( m_table_cloth[i][j] != '.' ) continue;
      Point start = { i, j, };
      Points buf_list;
      for (int x = -1; x <= 1; ++x)
      {
        for (int y = -1; y <= 1; ++y)
        {
          if ( x == 0 and y == 0 ) continue;
          Find_place(start, x, y, cookie, buf_list);
        }
      }
      if (reverse_list.Size() < buf_list.Size() )
      {
        reverse_list = buf_list;
        put_point.x = i;
        put_point.y = j;
      }
    }
  }

  if ( put_point.x == -1 and put_point.y == -1 ) return false;
  m_table_cloth[put_point.x][put_point.y] = cookie;
  return true;
}

inline void TableCloth::reverse_cookie(int x, int y)
{
  m_table_cloth[x][y] = m_table_cloth[x][y] == 'o' ? 'x' : 'o';
}

void TableCloth::Find_place(Point& start, int x_dir, int y_dir, char cookie, Points& list)
{
  Points buf_points(8);
  for (int i = start.x + x_dir, j = start.y + y_dir; ; i += x_dir, j += y_dir)
  {
    if (! CheckIndex(i, j) ) return;
    if ( m_table_cloth[i][j] == '.') return;
    if ( m_table_cloth[i][j] == cookie)
    {
      list.Add_last(buf_points);
      return;
    }
    buf_points.Add_last(i, j);
  }
}

inline bool TableCloth::CheckIndex(int i, int j)
{
  return (0 <= i and i < 8) and (0 <= j and j < 8);
}

int main(void)
{
  TableCloth table_cloth;
  while (true)
  {
    bool mami = table_cloth.Turn();
    bool charlotte = table_cloth.Turn();
    if (! (mami or charlotte) ) break;
  }

  table_cloth.Show();
}
