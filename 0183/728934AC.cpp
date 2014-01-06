#include <iostream>
using namespace std;

bool win_check(char c, char d, char e)
{
  if ( c == 'b' && d == 'b' && e == 'b' )
  {
    cout << 'b' << endl;
    return true;
  }
  else if ( c == 'w' && d == 'w' && e == 'w' )
  {
    cout << 'w' << endl;
    return true;
  }
  return false;
}

int main()
{
  while (true)
  {
    char board[3][3];
    for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
      {
        cin >> board[i][j];
        if (board[i][j] == '0') return 0;
      }
    }

    bool flag = false;

    for (int i=0; i<3; i++)
    {
      flag = win_check(board[i][0], board[i][1], board[i][2]);
      if ( flag ) break;
    }
    if ( flag ) continue;
    
    for (int j=0; j<3; j++)
    {
      flag = win_check(board[0][j], board[1][j], board[2][j]);
      if ( flag ) break;
    }
    if ( flag ) continue;

    flag = win_check(board[0][0], board[1][1], board[2][2]);
    if ( flag ) continue;
    flag = win_check(board[0][2], board[1][1], board[2][0]);
    if ( flag ) continue;

    cout << "NA" << endl;
  }
}
