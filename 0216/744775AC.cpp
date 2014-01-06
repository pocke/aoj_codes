#include <iostream>
using namespace std;

int main(void)
{
  int water;
  int fee;
  while (true)
  {
    cin >> water;
    if ( water == -1 ) break;

    if (water <= 10)
    {
      fee = 1150;
    }
    else if (water <= 20)
    {
      fee = 1150 + (water - 10) * 125;
    }
    else if (water <= 30)
    {
      fee = 1150 + 10 * 125 + (water - 20) * 140;
    }
    else 
    {
      fee = 1150 + 10 * 125 + 10 * 140 + (water - 30) * 160;
    }

    cout << 4280 - fee << endl;
  }
  return 0;
}
