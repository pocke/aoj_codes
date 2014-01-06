#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  int a, b, C;
  cin >> a >> b >> C;
  double C_rad = C / 180.0 * M_PI;
  double h = b * sin(C_rad);
  double S = a * h / 2;
  double c = sqrt( a*a + b*b -2*a*b*cos(C_rad) );
  double L = a + b + c;

  printf("%.8lf\n%.8lf\n%.8lf\n", S, L, h);
}
