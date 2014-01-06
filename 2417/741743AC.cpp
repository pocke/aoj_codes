#include <iostream>
using namespace std;

int main(void)
{
  char child, mum;
  while (cin >> child >> mum)
  {
    if (child == '0' && mum == 'U')
    {
      cout << "nn";
    }
    else
    {
      switch (child)
      {
        case '1':
          break;
        case '2':
          cout << 'k';
          break;
        case '3':
          cout << 's';
          break;
        case '4':
          cout << 't';
          break;
        case '5':
          cout << 'n';
          break;
        case '6':
          cout << 'h';
          break;
        case '7':
          cout << 'm';
          break;
        case '8':
          cout << 'y';
          break;
        case '9':
          cout << 'r';
          break;
        case '0':
          cout << 'w';
          break;
      }
      switch (mum)
      {
        case 'T':
          cout << 'a';
          break;
        case 'L':
          cout << 'i';
          break;
        case 'U':
          cout << 'u';
          break;
        case 'R':
          cout << 'e';
          break;
        case 'D':
          cout << 'o';
          break;
      }
    }
  }
  cout << endl;
  return 0;
}
