#include <iostream>
using namespace std;

class Color
{
  public:
    Color();
  public:
    void ChangeColor(int i);
    void PlusColor(int c);
    int isColor();

  private:
    int m_color;
};

Color::Color()
{
  m_color = 1;
}

inline void Color::PlusColor(int i)
{
  m_color = (m_color + i - 1) % 3 + 1;
}

inline void Color::ChangeColor(int c)
{
  m_color = c;
}

inline int Color::isColor()
{
  return m_color;
}

int main(void)
{
  int wh;
  int k;
  int x, y;
  cin >> wh;
  int centre = wh / 2;
  cin >> k;
  for (int i = 0; i < k; ++i)
  {
    cin >> x >> y;
    if (centre < x) x = wh - x + 1;
    if (centre < y) y = wh - y + 1;

    Color color;
    if (y >= x)
    {
      color.ChangeColor( x % 3 == 0 ? 3 : x % 3);
    }
    else
    {
      color.PlusColor(y - 1);
    }

    cout << color.isColor() << endl;
  }
  return 0;
}
