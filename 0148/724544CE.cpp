#include <iostream>
using namespace std;

int main()
{
  while(true)
  {
    int candy;
    cin >> candy;
    if ( cin.eof() ) break;
    cout << "3C" << candy&39 << endl;
  }
}
