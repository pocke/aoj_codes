#include <iostream>
using namespace std;

int main()
{
  cin >> noskipws;
  while (true)
  {
    int sum = 0;
    while (true)
    {
      char ch;
      cin >> ch;
      if ( ch == 10 ) break;
      sum += ch-48;
    }
    if ( sum == 0 ) break;
    cout << sum << endl;
  }
}