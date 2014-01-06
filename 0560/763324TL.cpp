#include <iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

class Map
{
  public:
    Map(int height, int width);
    ~Map();

  public:
    void Survey(Point p1, Point p2, int* result);

  private:
    char** m_map;
    int m_height, m_width;
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

void Map::Survey(Point p1, Point p2, int* result)
{
  for (int i = p1.x; i <= p2.x; ++i)
  {
    for (int j = p1.y; j <= p2.y; ++j)
    {
      switch(m_map[i][j])
      {
        case 'J':
          ++result[0];
          break;
        case 'O':
          ++result[1];
          break;
        case 'I':
          ++result[2];
          break;
      }
    }
  }
}

int main(void)
{
  int height, width;
  cin >> height >> width;
  int k;
  cin >> k;
  Map map(height, width);

  Point point1;
  Point point2;
  int result[3];
  for (int i = 0; i < k; ++i)
  {
    result[0] = result[1] = result[2] = 0;
    cin >> point1.x >> point1.y;
    cin >> point2.x >> point2.y;
    --point1.x; --point1.y;    //  0 Origin
    --point2.x; --point2.y;

    map.Survey(point1, point2, result);
    cout << result[0] << ' '<< result[1] << ' '<< result[2] << endl;
  }
  return 0;
}
