#include <iostream>
using namespace std;

double abs( double n )
{
  return ( n < 0 ? -n : n );
}

int main()
{
  while(true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;

    double min_diff = 10000000;
    int min_num;
    for (int i=0; i<n; i++)
    {
      int num;
      double height, weight;
      cin >> num >> height >> weight;
      double bmi = weight / ( height*height*0.0001);
      double bmi_diff = abs(22.0 - bmi);
      if ( bmi_diff < min_diff )
      {
        min_diff = bmi_diff;
        min_num = num;
      }
      else if ( bmi_diff == min_diff )
      {
        if ( num < min_num )
        {
          min_diff = bmi_diff;
        }
      }
    }
    cout << min_num << endl;
  }
}
