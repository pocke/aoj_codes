#include <iostream>
using namespace std;

class Town
{
  public:
    Town(int height, int width);
    ~Town();
    void tank_up();
    void tank_down();
    void tank_left();
    void tank_right();
    void shoot();
    void show();
    
  private:
    char** m_map;
    int m_height;
    int m_width;
    int m_tank_i;
    int m_tank_j;
    bool can_move(int height, int width);
    bool inside_map(int height, int width);
    bool is_flat(int height, int width);
};

Town::Town(int height, int width)
{
  m_height = height;
  m_width = width;
  m_map = new char*[m_height];
  for (int i = 0; i < m_height; i++)
  {
    m_map[i] = new char[m_width];
  }
  for (int i = 0; i < m_height; i++)
  {
    for (int j = 0; j < m_width; j++)
    {
      cin >> m_map[i][j];
      switch (m_map[i][j])
      {
        case '<':
        case '>':
        case '^':
        case 'v':
          m_tank_i = i;
          m_tank_j = j;
          break;
      }
    }
  }
}

Town::~Town()
{
  for (int i = 0; i < m_height; i++)
  {
    delete[] m_map[i];
  }
  delete[] m_map;
}

bool Town::can_move(int height, int width)
{
  return inside_map(height, width) && is_flat(height, width);
}

bool Town::is_flat(int height, int width)
{
  return m_map[height][width] == '.';
}

bool Town::inside_map(int height, int width)
{
  return ( 0 <= height && height < m_height ) && ( 0 <= width && width < m_width );
}

void Town::tank_up()
{
  if ( can_move(m_tank_i-1, m_tank_j) )
  {
    m_map[m_tank_i][m_tank_j] = '.';
    m_tank_i--;
  }
  m_map[m_tank_i][m_tank_j] = '^';
}

void Town::tank_down()
{
  if ( can_move(m_tank_i+1, m_tank_j) )
  {
    m_map[m_tank_i][m_tank_j] = '.';
    m_tank_i++;
  }
  m_map[m_tank_i][m_tank_j] = 'v';
}

void Town::tank_left()
{
  if ( can_move(m_tank_i, m_tank_j-1) )
  {
    m_map[m_tank_i][m_tank_j] = '.';
    m_tank_j--;
  }
  m_map[m_tank_i][m_tank_j] = '<';
}

void Town::tank_right()
{
  if ( can_move(m_tank_i, m_tank_j+1) )
  {
    m_map[m_tank_i][m_tank_j] = '.';
    m_tank_j++;
  }
  m_map[m_tank_i][m_tank_j] = '>';
}

void Town::shoot()
{
  int plus = 1;
  switch (m_map[m_tank_i][m_tank_j])
  {
    case '^':
      plus = -1;
    case 'v':
      for (int i = m_tank_i+ plus ; inside_map(i, m_tank_j); i += plus)
      {
        if ( m_map[i][m_tank_j] == '#' )
        {
          break;
        }
        else if ( m_map[i][m_tank_j] == '*' )
        {
          m_map[i][m_tank_j] = '.';
          break;
        }
      }
      break;
    case '<':
      plus = -1;
    case '>':
      for (int j = m_tank_j+ plus ; inside_map(m_tank_i, j); j += plus)
      {
        if ( m_map[m_tank_i][j] == '#' )
        {
          break;
        }
        else if ( m_map[m_tank_i][j] == '*' )
        {
          m_map[m_tank_i][j] = '.';
          break;
        }
      }
      break;
  }
}

void Town::show()
{
  for (int i = 0; i < m_height; i++)
  {
    for (int j = 0; j < m_width; j++)
    {
      cout << m_map[i][j];
    }
    cout << endl;
  }
}

int main(void)
{
  int t;
  cin >> t;
  for (int dataset = 0; dataset < t; dataset++)
  {
    int height, width;
    cin >> height >> width;
    Town town(height, width);

    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
      char command;
      cin >> command;
      switch (command)
      {
        case 'U':
          town.tank_up();
          break;
        case 'D':
          town.tank_down();
          break;
        case 'L':
          town.tank_left();
          break;
        case 'R':
          town.tank_right();
          break;
        case 'S':
          town.shoot();
          break;
      }
    }
    town.show();
    if ( dataset != t - 1 ) cout << endl;
  }
  return 0;
}
