#include <iostream>
using namespace std;

int main()
{
  int a,b;
  int c;
  int i;
  while(true)
  {
    cin >> a >> b;
    if ( cin.eof() ) break;
    c = a + b;
    for (i=1; c>=10; i++)
    {
      c /= 10;
    }
    cout << i << endl;
  }
  return 0;
}
