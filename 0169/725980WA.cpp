#include <iostream>
using namespace std;

int main()
{
  cin >> noskipws;
  while(true)
  {
    int cards[21];
    int card_num;
    int ace_num = 0;   //  エースがあるかどうか
    for (card_num = 0; card_num<21; card_num++)
    {
      cin >> cards[card_num];
      if ( cards[card_num] == 0 ) return 0;
      if ( cards[card_num] == 1 ) ace_num++;
      char ws;
      cin >> ws;
      if ( ws != ' ' )
      {
        card_num++;
        break;
      }
    }

    int point = 0;
    for (int i=0; i<card_num; i++)
    {
      if ( cards[i] < 10 )
      {
        point += cards[i];
      }
      else
      {
        point += 10;
      }
    }
    if ( point > 21 )
    {
      point = 0;
    }

    while ( ace_num > 0 && point <= 11 )
    {
      point += 10;
      ace_num--;
    }

    cout << point << endl;

  }
}
