#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  double time1, time2;
  string result;
  while (cin >> time1 >> time2)
  {
    if (time1 < 35.50 and time2 < 71.00)
    {
      result = "AAA";
    }
    else if (time1 < 37.50 and time2 < 77.00)
    {
      result = "AA";
    }
    else if (time1 < 40.00 and time2 < 83.00)
    {
      result = "A";
    }
    else if (time1 < 43.00 and time2 < 89.00)
    {
      result = "B";
    }
    else if (time1 < 50.00 and time2 < 105.00)
    {
      result = "C";
    }
    else if (time1 < 55.00 and time2 < 116.00)
    {
      result = "D";
    }
    else if (time1 < 70.00 and time2 < 148.00)
    {
      result = "E";
    }
    else
    {
      result = "NA";
    }
    cout << result << endl;
  }
  return 0;
}