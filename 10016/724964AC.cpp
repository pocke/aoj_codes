#include <iostream>
using namespace std;

int main()
{
  while( true )
  {
    int m, f, r;
    cin >> m >> f >> r;
    if ( m == -1 && f == -1 && r == -1 ) break;

    if ( m == -1 || f == -1 || m + f < 30 )
    {
      cout << 'F' << endl;
    }
    else if ( 80 <= m + f )
    {
      cout << 'A' << endl;
    }
    else if ( 65 <= m + f )
    {
      cout << 'B' << endl;
    }
    else if ( 50 <= m + f || ( 30 <= m + f && 50 <= r) )
    {
      cout << 'C' << endl;
    }
    else
    {
      cout << 'D' << endl;
    }
  }
}
