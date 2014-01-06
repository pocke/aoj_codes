#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Color
{
public:
  Color(int r, int g, int b);
  int get_R();
  int get_G();
  int get_B();
  string near_color();

private:
  int m_R;
  int m_G;
  int m_B;
  double diff( Color col );

  static Color black;
  static Color blue;
  static Color lime;
  static Color aqua;
  static Color red;
  static Color fuchsia;
  static Color yellow;
  static Color white;
};

Color Color::black(   0x00, 0x00, 0x00 );
Color Color::blue(    0x00, 0x00, 0xff );
Color Color::lime(    0x00, 0xff, 0x00 );
Color Color::aqua(    0x00, 0xff, 0xff );
Color Color::red(     0xff, 0x00, 0x00 );
Color Color::fuchsia( 0xff, 0x00, 0xff );
Color Color::yellow(  0xff, 0xff, 0x00 );
Color Color::white(   0xff, 0xff, 0xff );

Color::Color(int r, int g, int b)
{
  m_R = r;
  m_G = g;
  m_B = b;
}

int Color::get_R()
{
  return m_R;
}

int Color::get_G()
{
  return m_G;
}

int Color::get_B()
{
  return m_B;
}

double Color::diff( Color col )
{
  return sqrt( pow(m_R - col.get_R(), 2) + pow(m_G - col.get_G(), 2) + pow(m_B - col.get_B(), 2) );
}

string Color::near_color()
{
  struct Color_name
  {
    string name;
    Color color;
  };
  Color_name colors[8] = {
    "black", black,
    "blue", blue,
    "lime", lime,
    "aqua", aqua,
    "red", red,
    "fuchsia", fuchsia,
    "yellow", yellow,
    "white", white,
  };
  Color_name min = colors[0];
  for (int i=1; i<8; i++)
  {
    if ( diff(colors[i].color) < diff(min.color) )
    {
      min = colors[i];
    }
  }
  return min.name;
}

int main()
{
  while(true)
  {
    string color;
    getline(cin, color);
    if ( color == "0" ) return 0;

    int r = stoi( color.substr(1, 2), 0, 16 );
    int g = stoi( color.substr(3, 2), 0, 16 );
    int b = stoi( color.substr(5, 2), 0, 16 );
    Color c(r, g, b);
    cout << c.near_color() << endl;
  }
}
