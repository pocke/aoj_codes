#include <iostream>
using namespace std;

int main(void)
{
  int price_sum = 0;
  double num_sum = 0;
  int i;
  for (i=0; ;i++)
  {
    int price;
    int num;
    char dummy;
    cin >> price >> dummy >> num;
    if ( cin.eof() ) break;
    price_sum += price * num;
    num_sum += num;
  }

  int avg = (int)( (num_sum / i) + 0.5 );
  cout << price_sum << endl
       << avg << endl;
}
