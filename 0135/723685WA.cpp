#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int dataset=0; dataset<n; dataset++)
  {
    char dummy;
    int hour,minutes;
    cin >> hour >> dummy >> minutes;

    int hour_angle = hour * 60 + minutes;
    int minutes_angle = minutes * 12;
    int angle_diff = hour_angle - minutes_angle;
    if ( angle_diff < 0 ) angle_diff = -angle_diff;

    if ( 0 <= angle_diff && angle_diff < 60 )
    {
      cout << "alert" << endl;
    }
    else if ( 180 <= angle_diff && angle_diff <= 360 )
    {
      cout << "safe" << endl;
    }
    else
    {
      cout << "warning" << endl;
    }
  }
}
