#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int d = a/b;
  int r = a%b;
  double f = a/(double)b;
  printf("%d %d %.5lf\n", d, r, f);
}
