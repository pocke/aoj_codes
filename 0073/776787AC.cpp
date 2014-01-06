#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
  while (true)
  {
    double x, h;
    cin >> x >> h;
    if (x == 0 and h == 0) break;
    double t_h = hypot(x/2, h);
    double result = x * t_h * 2 + pow(x, 2);
    printf("%.6lf\n", result);
  }
  return 0;
}