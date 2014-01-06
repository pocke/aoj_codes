#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int a, b, n;
  while (cin >> a >> b >> n)
  {
    long double buf = a / (long double)b;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
      sum += (int)(buf * pow(10, i)) % 10;
    }
    cout << sum << endl;
  }
  return 0;
}
