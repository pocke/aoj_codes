#include <iostream>
using namespace std;

int main()
{
  int t;    //データセットの個数
  cin >> t;
  for (int i=0; i<t; i++)   //データセット
  {
    int n;    //ブロックの個数
    cin >> n;
    int up_diff = 0;
    int down_diff = 0;
    int* block = new int[n];
    for (int j=0; j<n; j++)
    {
      cin >> block[j];
    }

    for (int j=0; j<n-1; j++)     //ブロック
    {
      int diff;
      diff = block[j+1] - block[j];
      if ( diff < 0 )         //down
      {
        if ( down_diff < -diff )
        {
          down_diff = -diff;
        }
      }
      else if ( 0 < diff )    //up
      {
        if ( up_diff < diff )
        {
          up_diff = diff;
        }
      }
    }
    cout << up_diff << ' ' << down_diff << endl;
    delete[] block;
  }
}
