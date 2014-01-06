#include <iostream>
#include <string>
using namespace std;

int main()
{
  while(true)
  {
    int h,w;
    cin >> h >> w;
    if ( h == 0 && w == 0 ) break;
    char **room = new char*[h];
    for (int i=0; i<h; i++)
    {
      room[i] = new char[w];
    }

    for (int i=0; i<h; i++)
    {
      for (int j=0; j<w; j++)
      {
        cin >> room[i][j];
      }
    }

    int x = 0;
    int y = 0;
    bool flag = true;
    while(flag)
    {
      switch (room[y][x])
      {
      case '>':
        room[y][x] = 'x';
        x++;
        break;
      case '<':
        room[y][x] = 'x';
        x--;
        break;
      case '^':
        room[y][x] = 'x';
        y--;
        break;
      case 'v':
        room[y][x] = 'x';
        y++;
        break;
      case '.':
        cout << x << ' ' << y << endl;
        flag = false;
        break;
      case 'x':
        cout << "LOOP" << endl;
        flag = false;
        break;
      }
    } //おへや

    for (int i=0; i<h; i++)
    {
      delete[] room[i];
    }
    delete[] room;
  } //  データセット
}
