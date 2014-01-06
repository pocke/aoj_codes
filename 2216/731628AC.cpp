#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int price, pay;
    cin >> price >> pay;
    if ( price == 0 && pay == 0 ) break;
    int change = pay - price;

    int sen_yen = change / 1000;
    change -= sen_yen * 1000;
    int gohyaku_yen = change / 500;
    change -= gohyaku_yen * 500;
    int hyaku_yen = change / 100;

    cout << hyaku_yen << ' ' << gohyaku_yen << ' ' << sen_yen << endl;
  }
  return 0;
}
