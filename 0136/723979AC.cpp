#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int m[6] = { 0, 0, 0, 0, 0, 0, };

  for (int i=0; i<n; i++)
  {
    double height;
    cin >> height;
    if ( height < 165.0 )
    {
      m[0]++;
    }
    else if ( height < 170.0 )
    {
      m[1]++;
    }
    else if ( height < 175.0 )
    {
      m[2]++;
    }
    else if ( height < 180.0 )
    {
      m[3]++;
    }
    else if ( height < 185.0 )
    {
      m[4]++;
    }
    else
    {
      m[5]++;
    }
  }

  for (int i=0; i<6; i++)
  {
    cout << i+1 << ':' << flush;
    for (int j=0; j<m[i]; j++)
    {
      cout << '*' << flush;
    }
    cout << endl;
  }
}
