#include <iostream>
using namespace std;

int main()
{
  int kupc_num[4] = { 0, 0, 0, 0, };

  while(true)
  {
    char ch;
    cin >> ch;
    if ( cin.eof() ) break;

    switch(ch)
    {
    case 'K':
      kupc_num[0]++;
      break;
    case 'U':
      kupc_num[1]++;
      break;
    case 'P':
      kupc_num[2]++;
      break;
    case 'C':
      kupc_num[3]++;
      break;
    }
  }
  int min = 300;
  for (int i=0; i<4; i++)
  {
    if ( min > kupc_num[i] )
    {
      min = kupc_num[i];
    }
  }

  cout << min << endl;
}
