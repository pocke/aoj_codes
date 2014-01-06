#include <iostream>
using namespace std;

int main(void)
{
  int l, a, b, c, d;
  cin >> l >> a >> b >> c >> d;
  int ja = a/c + (a%c == 0 ? 0 : 1);
  int ma = b/d + (b%d == 0 ? 0 : 1);
  int result = l - (ja<ma ? ma : ja);
  cout << result << endl;
  return 0;
}