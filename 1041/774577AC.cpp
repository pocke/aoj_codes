#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;

    n /= 4;
    int result = 0;
    for (int i = 0,buf = 0; i < n; ++i)
    {
      cin >> buf;
      result += buf;
    }
    cout << result << endl;
  }
  return 0;
}