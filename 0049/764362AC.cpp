#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  char comma;
  int num;
  string blood;
  int groups[4] = { 0, 0, 0, 0, };
  while (true)
  {
    cin >> num >> comma >> blood;
    if (cin.eof() ) break;
    if (blood == "A")
    {
      ++groups[0];
    }
    else if (blood == "B")
    {
      ++groups[1];
    }
    else if (blood == "AB")
    {
      ++groups[2];
    }
    else
    {
      ++groups[3];
    }
  }
  for (int i = 0; i < 4; ++i)
  {
    cout << groups[i] << endl;
  }
  return 0;
}
