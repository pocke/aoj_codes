#include <iostream>
#include <bitset>
using namespace std;
#define NONE  0b0000000
#define ZERO  0b0111111
#define ONE   0b0000110
#define TWO   0b1011011
#define THREE 0b1001111
#define FOUR  0b1100110
#define FIVE  0b1101101
#define SIX   0b1111101
#define SEVEN 0b0100111
#define EIGHT 0b1111111
#define NINE  0b1101111

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == -1 ) break;
    int display = NONE;
    for (int i = 0; i < n; ++i)
    {
      int num;
      cin >> num;
      int buf;
      switch(num)
      {
        case 0:
          buf = ZERO;
          break;
        case 1:
          buf = ONE;
          break;
        case 2:
          buf = TWO;
          break;
        case 3:
          buf = THREE;
          break;
        case 4:
          buf = FOUR;
          break;
        case 5:
          buf = FIVE;
          break;
        case 6:
          buf = SIX;
          break;
        case 7:
          buf = SEVEN;
          break;
        case 8:
          buf = EIGHT;
          break;
        case 9:
          buf = NINE;
          break;
      }
    cout << bitset<7>(buf xor display) << endl;
    display = buf;
    }
  }
  return 0;
}
