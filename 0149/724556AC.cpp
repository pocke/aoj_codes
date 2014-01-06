#include <iostream>
using namespace std;

int main()
{
  int left[4]  = { 0, 0, 0, 0, };
  int right[4] = { 0, 0, 0, 0, };   //人数

  while (true)
  {
    double l_eye, r_eye;
    cin >> l_eye >> r_eye;
    if ( cin.eof() ) break;
    if ( 1.1 <= l_eye )       // left
    {
      left[0]++;
    }
    else if ( 0.6 <= l_eye )
    {
      left[1]++;
    }
    else if ( 0.2 <= l_eye )
    {
      left[2]++;
    }
    else
    {
      left[3]++;
    }

    if ( 1.1 <= r_eye )       // right
    {
      right[0]++;
    }
    else if ( 0.6 <= r_eye )
    {
      right[1]++;
    }
    else if ( 0.2 <= r_eye )
    {
      right[2]++;
    }
    else
    {
      right[3]++;
    }
  }
  for (int i=0; i<4; i++)
  {
    cout << left[i] << ' ' << right[i] << endl;
  }
}
