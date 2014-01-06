#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
  double x;
  double y;
};

//              --class Line
class Line
{
  public:
    Line(Point p1, Point p2);

  public:
    bool parallel(Line other); // $BJ?9T$+(B

  private:
    Point m_p1;
    Point m_p2;
    double m_slope;     //  $B79$-(B
};

Line::Line(Point p1, Point p2)
{
  m_p1 = p1;
  m_p2 = p2;
  m_slope = ( p2.y - p1.y ) / ( p2.x - p1.x );
}

bool Line::parallel(Line other)
{
  return abs(m_slope - other.m_slope) < 0.0001;
}

int main(void)
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    Line line1(p1, p2);
    Line line2(p3, p4);
    cout << (line1.parallel(line2) ? "YES" : "NO") << endl;
  }
  return 0;
}