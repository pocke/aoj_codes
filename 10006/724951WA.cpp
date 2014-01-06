#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int i = 1;
    int x;
    cin >> x;
    if ( x == 0 ) break;
    cout << "Case " << i << ": " << x << endl;
    i++;
  }
}
