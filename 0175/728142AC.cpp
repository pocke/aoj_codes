#include <iostream>
using namespace std;

long int pow(int x, int y)
{
  long int result = 1;
  for (int i=0; i<y; i++)
  {
    result *= x;
  }
  return result;
}

long int dec_to_4(int x)
{
  long int result = 0;
  for (int i=0; x != 0 ;i++)
  {
    result += (x % 4) * pow(10, i);
    x /= 4;
  }
  return result;
}

int main()
{
  while(true)
  {
    int num;
    cin >> num;
    if ( num == -1 ) break;

    cout << dec_to_4(num) << endl;
  }
}
