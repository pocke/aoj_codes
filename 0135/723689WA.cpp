#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int dataset=0; dataset<n; dataset++)
  {
    char dummy;
    double hour,minutes;
    cin >> hour >> dummy >> minutes;

    double hour_angle = hour * 30;
    double minutes_angle = minutes * 6;
    double angle_diff = hour_angle - minutes_angle;
    if ( angle_diff < 0 ) angle_diff = -angle_diff;

    if ( 0 <= angle_diff && angle_diff <= 30 )
    {
      cout << "alert" << endl;
    }
    else if ( 90 <= angle_diff && angle_diff <= 180 )
    {
      cout << "safe" << endl;
    }
    else
    {
      cout << "warning" << endl;
    }
  }
}
