#include <iostream>
using namespace std;

int main(void)
{
  int buf;
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    int m = n / 4;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
      cin >> buf;
      sum += buf;
    }
    cout << sum << endl;
  }
  return 0;
}
