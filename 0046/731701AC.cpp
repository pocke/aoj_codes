#include <iostream>
using namespace std;

int main(void)
{
  double max = 0;
  double min = 10000000000000;
  
  while (true)
  {
    double height;
    cin >> height;
    if ( cin.eof() ) break;

    if (max < height)
    {
      max = height;
    }
    if (min > height)
    {
      min = height;
    }
  }
  cout << max - min << endl;
}
