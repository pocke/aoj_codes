#include <iostream>
using namespace std;

int main(void)
{
  int buf;
  bool students[30];
  for (int i = 0; i < 30; i++)
  {
    students[i] = true;
  }

  for (int i = 0; i < 28; i++)
  {
    cin >> buf;
    students[buf] = false;
  }

  for (int i = 0; i < 30; i++)
  {
    if ( students[i] ) cout << i << endl;
  }
  return 0;
}
