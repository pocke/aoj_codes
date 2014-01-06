#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int height, width;
    cin >> height >> width;
    if ( height == 0 && width == 0 ) break;

    char ch;
    for (int i=0; i<height; i++)
    {
      for (int j=0; j<width; j++)
      {
        ch = ( (i+j)%2 == 0 ? '#' : '.' );
        cout << ch;
      }
      cout << endl;
    }
    cout << endl;
  }
}
