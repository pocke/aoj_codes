#include <iostream>
using namespace std;

int main(void)
{
  bool a, b, c;
  cin >> a >> b >> c;
  if ( (a and b) or c)
  {
    cout << "Open" << endl;
  }
  else
  {
    cout << "Close" << endl;
  }
  return 0;
}
