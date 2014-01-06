#include <iostream>
using namespace std;

int main(void)
{
  bool cups[] = { true, false, false };
  char buf_commma;
  char from, to;
  while (true)
  {
    cin >> from >> buf_commma >> to;
    if (cin.eof() ) break;
    if (cups[from - 65] ^ cups[to - 65])
    {
      cups[from - 65] = !cups[from - 65];
      cups[to - 65] = !cups[to - 65];
    }
  }
  cout << (cups[0] ? 'A' : cups[1] ? 'B' : 'C') << endl;
  return 0;
}
