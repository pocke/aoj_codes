#include <iostream>
using namespace std;

int abs(int i)
{
  return ( i < 0 ? -i : i );
}
int km_to_yen(int km)
{
  switch(km)
  {
  case 5:
    return 250;
  case 6:
    return 300;
  case 7:
    return 350;
  case 10:
    return 400;
  case 12:
    return 450;
  case 13:
  case 15:
    return 500;
  case 17:
  case 18:
  case 20:
    return 600;
  case 23:
    return 700;
  case 25:
    return 850;
  case 30:
    return 1000;
  case 35:
  case 37:
    return 1150;
  case 40:
    return 1300;
  case 43:
  case 45:
    return 1350;
  case 52:
    return 1500;
  case 58:
    return 1650;
  }
}

int main()
{
  int ic_km[8] = { 0, 0, 6, 13, 18, 23, 43, 58, };
  while (true)
  {
    int from_num;
    int from_hour, from_min;
    cin >> from_num;
    if ( from_num == 0 ) break;
    cin >> from_hour >> from_min;
    int from_time = from_hour*100 + from_min;

    int to_num;
    int to_hour, to_min;
    cin >> to_num;
    cin >> to_hour >> to_min;
    int to_time = to_hour*100 + to_min;

    int km_diff = abs(ic_km[to_num] - ic_km[from_num]);
    int fare = km_to_yen(km_diff);
    if ( ( ( 1730 <= from_time && from_time <= 1930 ) ||
           ( 1730 <= to_time   && to_time   <= 1930 ) ) &&
         ( km_diff <= 40 ) )
    {
      fare /= 2;
      if ( fare % 50 != 0 )
      {
        fare = ( fare / 50 + 1 ) * 50;
      }
    }
    cout << fare << endl;
  }
}
