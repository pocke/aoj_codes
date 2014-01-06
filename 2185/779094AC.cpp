#include <iostream>
#include <vector>
using namespace std;

struct Point
{
  int x;
  int y;
};

class Campus
{
  public:
    Campus(int x, int y, int width, int height);
    bool inCampus(Point p);

  private:
    int m_x, m_y, m_width, m_height;
};

Campus::Campus(int x, int y, int width, int height)
{
  m_x = x -1;
  m_y = y -1;
  m_width = width;
  m_height = height;
}

bool Campus::inCampus(Point p)
{
  return (m_x <= p.x and p.x <= m_x + m_width + 1) and
         (m_y <= p.y and p.y <= m_y + m_height + 1);
}

int main(void)
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int x, y, width, height;
    cin >> x >> y >> width >> height;
    Campus campus(x, y, width, height);

    int result = 0;
    int cat_num;
    cin >> cat_num;
    for (int j = 0; j < cat_num; ++j)
    {
      Point cat;
      cin >> cat.x >> cat.y;
      if (campus.inCampus(cat) )
      {
        ++result;
      }
    }
    cout << result << endl;
  }
  return 0;
}