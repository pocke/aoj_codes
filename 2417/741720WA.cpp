#include <iostream>
using namespace std;

int main(void)
{
  const char children[10] = { 'w','\0', 'k', 's', 't', 'n', 'h', 'm', 'y', 'r', };
  const char mums[5] = { 'a', 'i', 'u', 'e', 'o', };
  while (true)
  {
    char child, mum;
    cin >> child >> mum;
    int mum_num;
    switch (mum)
    {
    case 'T':
      mum_num = 0;
      break;
    case 'L':
      mum_num = 1;
      break;
    case 'U':
      mum_num = 2;
      break;
    case 'R':
      mum_num = 3;
      break;
    case 'D':
      mum_num = 4;
      break;
    }
    if ( cin.eof() ) break;

    if (child == '0' && mum == 'U')
    {
      cout << "nn";
    }
    else
    {
      cout << children[child - 48] << mums[mum_num];
    }
  }
  cout << endl;
  return 0;
}
