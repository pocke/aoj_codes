#include <iostream>
using namespace std;

int main()
{
  const int bus_stop[] = { 0, 1, 2, 3, 4, 5,
                           6, 7, 8, 9 ,
                           5, 4, 3, 2, 1,
                         };
  int n;
  cin >> n;
  for (int dataset = 0; dataset<n; dataset++)
  {
    int from,to;
    cin >> from >> to;
    if ( 1 <= from && from <= 5 && to < from )
    {
      for (int i=from; i > to; i--)
      {
        cout << i << ' ' << flush;
      }
      cout << to << endl;
    }
    else
    {
      for (int i=from; bus_stop[i] != to; ( i == 14)? i=0 : i++)
      {
        cout << bus_stop[i] << ' ';
      }
      cout << to << endl;
    }
  }
}
