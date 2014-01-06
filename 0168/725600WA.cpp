#include <iostream>
using namespace std;

long int factorial ( int x )
{
  if ( x == 0 ) return 1;
  return x * factorial( x-1 );
}

int main()
{
  while (true)
  {
    int n;      //  段数
    cin >> n;
    if ( n == 0 ) break;

    long int pattern = 0;

    for (int a=0; a <= n/3; a++)
    {
      for (int b=0; b <= n/2; b++)
      {
        for (int c=0; c <=n; c++)
        {
          if ( 3*a + 2*b + c == n )
          {
            pattern += factorial( a+b+c ) / 
              ( factorial(a) * factorial(b) * factorial(c) );
          }
        }
      }
    }

    long int day = pattern / 10 + ( pattern%10 == 0 ? 0 : 1 );
    long int year = day / 365 + ( day%365 == 0 ? 0 : 1 );
    cout << year << endl;
  }
}
