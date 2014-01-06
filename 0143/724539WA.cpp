#include <iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

//-----------------------Line Class
class Line
{
public:
  Line(Point a, Point b);
  double GetSlope();
  double GetIntercept();
  Point GetPointA();
  Point GetPointB();
  bool CrossLine(Line line2);
private:
  Point m_pointA,m_pointB;
  bool m_x1_x2;         //x1=x2 ?
  double m_slope;       //傾き
  double m_intercept;   //y切片
};

Line::Line(Point a, Point b)
{
  m_pointA = a;
  m_pointB = b;

  if ( m_pointA.x == m_pointB.x )
  {
    m_x1_x2 = true;
  }
  else
  {
    m_x1_x2 = false;
    m_slope = ( m_pointB.y - m_pointA.y) / (double)( m_pointB.x - m_pointA.x );
    m_intercept = m_pointA.y - m_pointA.x * m_slope;
  }
}

double Line::GetSlope()
{
  return m_slope;
}

double Line::GetIntercept()
{
  return m_intercept;
}

Point Line::GetPointA()
{
  return m_pointA;
}

Point Line::GetPointB()
{
  return m_pointB;
}

bool Line::CrossLine(Line line2)
{
  if ( m_slope == line2.GetSlope() )    //傾きが同じならば
  {
    return false;
  }
  double cross_x = ( m_intercept - line2.GetIntercept() ) / ( m_slope - line2.GetSlope() );
  bool line1_in;
  bool line2_in;
  if ( m_pointA.x == m_pointB.x )   //self
  {
    line1_in = true;
  }
  else if ( (m_pointA.x < cross_x && cross_x < m_pointB.x) || 
            (m_pointB.x < cross_x && cross_x < m_pointA.x) )
  {
    line1_in = true;
  }
  else
  {
    line1_in = false;
  }

  if ( line2.GetPointA().x == line2.GetPointB().x )   //引数line2
  {
    line2_in = true;
  }
  else if ( (line2.GetPointA().x < cross_x && cross_x < line2.GetPointB().x) || 
            (line2.GetPointB().x < cross_x && cross_x < line2.GetPointA().x) )
  {
    line2_in = true;
  }
  else
  {
    line2_in = false;
  }

  return line1_in && line2_in;
}

//--------------------------Triangle Class
class Triangle
{
public:
  Triangle(Point point1, Point point2, Point point3);
  bool OnePointIn( Point point1, Point point2);
private:
  Point m_point1, m_point2, m_point3;
};

Triangle::Triangle(Point point1, Point point2, Point point3)
{
  m_point1 = point1;
  m_point2 = point2;
  m_point3 = point3;
}

bool Triangle::OnePointIn( Point point1, Point point2 )
{
  Line love(point1, point2);
  Line trg1(m_point1, m_point2);
  Line trg2(m_point1, m_point3);
  Line trg3(m_point2, m_point3);
  int cross_num = 0;
  if ( love.CrossLine(trg1) )
  {
    cross_num++;
  }
  if ( love.CrossLine(trg2) )
  {
    cross_num++;
  }
  if ( love.CrossLine(trg3) )
  {
    cross_num++;
  }
  if ( cross_num == 1 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

//----------------------------main関数
int main()
{
  int n;    //  データセットの個数
  cin >> n;
  for (int dataset=0; dataset<n; dataset++)
  {
    Point trg[3];
    for (int i=0; i<3; i++)
    {
      cin >> trg[i].x >> trg[i].y;
    }
    Triangle triangle( trg[0], trg[1], trg[2] );
    Point kengyu;
    Point shukujo;
    cin >> kengyu.x >> kengyu.y >> shukujo.x >> shukujo.y;
    if ( triangle.OnePointIn( kengyu, shukujo ) )
    {
      cout << "OK" << endl;
    }
    else
    {
      cout << "NG" << endl;
    }
  }
}
