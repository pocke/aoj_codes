#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int height, width;
    cin >> height >> width;
    if ( height == 0 && width == 0 ) break;

    for (int i=0; i<height; i++)
    {
      for (int j=0; j<width; j++)
      {
        char ch;
        if ( i == 0 || i == height-1 || j == 0 || j == width-1 )
        {
          ch = '#';
        }
        else
        {
          ch = '.';
        }
        cout << ch;
      }
      cout << endl;
    }
    cout << endl;
  }
}
