#include <iostream>
using namespace std;

int main()
{
  cin >> noskipws;
  while( true )
  {
    char ch;
    cin >> ch;
    if ( cin.eof() ) break;
    if ( 65 <= ch && ch <= 90 )
    {
      ch += 32;
    }
    else if ( 97 <= ch && ch <= 122 )
    {
      ch -= 32;
    }
    cout << ch;
  }
}
