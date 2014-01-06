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
    for (card_num = 0; ; card_num++)
    {
      if ( card_num == 21 )
      {
        int dummy;
        char ws;
        bool b = true;
        while (b)
        {
          cin >> dummy >> ws;
          if ( ws != ' ' )
          {
            b = false;
          }
        }
        break;
      }
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

    while ( ace_num > 0 && point <= 11 )
    {
      point += 10;
      ace_num--;
    }
    if ( point > 21 )
    {
      point = 0;
    }

    cout << point << endl;

  }
}
