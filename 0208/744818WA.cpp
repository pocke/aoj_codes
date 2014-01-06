#include <iostream>
using namespace std;

unsigned long int dec_to_oct(unsigned long int num)
{
  int result = 0;
  for (int i = 1; num != 0; i *= 10)
  {
    result += (num % 8) * i;
    num = num / 8;
  }
  return result;
}

int main(void)
{
  unsigned long int room_num;
  unsigned long int buf;
  unsigned long int new_room_num;
  int num_table[8] = { 0, 1, 2, 3, 5, 7, 8, 9, };
  
  while (true)
  {
    cin >> room_num;
    if ( room_num == 0 ) break;
    buf = dec_to_oct(room_num);

    new_room_num = 0;
    for (int i = 1; buf != 0; i *= 10)
    {
      new_room_num += num_table[(buf % 10)] * i;
      buf /= 10;
    }

    cout << new_room_num << endl;
  }
  return 0;
}
