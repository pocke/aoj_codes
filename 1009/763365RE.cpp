#include <iostream>
using namespace std;

int gcm(int a, int b)
{
  if (a > b)
  {
    int tmp = a;
    a = b;
    b = tmp;
    cerr << 'a' << endl;
  }

  for (int i = 1; ; ++i)
  {
    if (a % i == 0 and b % (a / i) == 0 )
    {
      return a / i;
    }
  }
}

int main(void)
{
  int a, b;
  while (cin >> a >> b)
  {
    cout << gcm(a, b) << endl;
  }

  return 0;
}
