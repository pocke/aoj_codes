#include <iostream>
using namespace std;

int main()
{
  while(true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;

    int i;
    for (i=0; n!=1; i++)
    {
      if ( n%2 == 0 )
      {
        n /= 2;
      }
      else
      {
        n = n * 3 + 1;
      }
    }
    cout << i << endl;
  }
}
