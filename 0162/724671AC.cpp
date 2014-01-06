#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int m, n;
    cin >> m;
    if ( m == 0 ) break;
    cin >> n;
    
    int count = 0;
    for (int i=m; i<=n; i++)
    {
      int num = i;
      while ( num % 2 == 0 )
      {
        num /= 2;
      }
      while ( num % 3 == 0 )
      {
        num /= 3;
      }
      while ( num % 5 == 0 )
      {
        num /= 5;
      }
      if ( num == 1 )
      {
        count++;
      }
    }
    cout << count << endl;
  }
}
