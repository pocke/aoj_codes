#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  double r;
  cin >> r;
  double s = r*r*M_PI;
  double l = 2*r*M_PI;
  printf("%.6lf %.6lf\n", s, l);
}
