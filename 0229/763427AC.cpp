#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int medal = 100;
    int seven, bar, grape, cherry, star, total;
    cin >> seven>> bar>> grape>> cherry>> star>> total;
    if ( total == 0 ) break;
    int nomal_game;
    int bonus_game;
    bonus_game = seven * 5 + bar * 3;
    nomal_game = total - bonus_game;
    //  Normal Game
    medal += seven * 15;
    medal += bar * 15;
    medal += grape * 7;
    medal += cherry * 2;
    //  Bonus Game
    medal += bonus_game * 15;
    //  Pay
    medal -= bonus_game * 2;
    medal -= (nomal_game - star) * 3;
    cout << medal << endl;
  }
  return 0;
}
