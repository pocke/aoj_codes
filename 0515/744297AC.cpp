#include <iostream>
using namespace std;

class Map
{
  public:
    Map(int i, int j);
    ~Map();
    int get_count();
    void block(int i, int j);
    void go_school(int i = 0, int j = 0);
  private:
    bool** m_map;
    int m_a;
    int m_b;
    int m_count;
};

Map::Map(int a, int b)
{
  m_a = a;
  m_b = b;
  m_map = new bool*[m_a];
  for (int i = 0; i < m_a; i++)
  {
    m_map[i] = new bool[m_b];
  }
  for (int i = 0; i < m_a; i++)
  {
    for (int j = 0; j < m_b; j++)
    {
      m_map[i][j] = true;
    }
  }

  m_count = 0;
}

Map::~Map()
{
  for (int i = 0; i < m_a; i++)
  {
    delete[] m_map[i];
  }
  delete[] m_map;
}

int Map::get_count()
{
  return m_count;
}

void Map::block(int i, int j)
{
  m_map[i-1][j-1] = false;
}

void Map::go_school(int i, int j)
{
  if (i == m_a-1 && j == m_b-1)
  {
    m_count++;
  }
  else if (m_map[i][j])
  {
    if ( i+1 < m_a ) go_school(i+1, j);
    if ( j+1 < m_b ) go_school(i, j+1);
  }
}

int main(void)
{
  int a, b;
  int n;
  int buf[2];
  while (true)
  {
    cin >> a >> b;
    if ( a == 0 && b == 0 ) break;
    Map map(a, b);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> buf[0] >> buf[1];
      map.block(buf[0], buf[1]);
    }
    map.go_school();
    cout << map.get_count() << endl;
  }

  return 0;
}
