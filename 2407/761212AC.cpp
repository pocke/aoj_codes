#include <iostream>
using namespace std;

int main(void)
{
  char start, end;
  cin >> start;
  end = start;
  while (cin >> end)
  {
  }
  if (start != end or start == 'o')
  {
    cout << 'o' << endl;
  }
  else
  {
    cout << 'x' << endl;
  }
  return 0;
}
