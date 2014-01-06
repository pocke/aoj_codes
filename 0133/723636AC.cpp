#include <iostream>
using namespace std;

int main()
{
  char pattern[8][8];
  for (int i=0; i<8; i++)
  {
    for (int j=0; j<8; j++)
    {
      cin >> pattern[i][j];
    }
  }

  char pattern2[8][8];
  for (int n=1; n<=3; n++)
  {
    for (int i=0; i<8; i++)   //回転
    {
      for (int j=0; j<8; j++)
      {
        pattern2[j][7-i] = pattern[i][j];
      }
    }


    cout << n*90 << endl;
    for (int i=0; i<8; i++)   //表示 
    {
      for (int j=0; j<8; j++)
      {
        cout << pattern2[i][j] << flush;
      }
      cout << endl;
    }
    for (int i=0; i<8; i++)   //代入
    {
      for (int j=0; j<8; j++)
      {
        pattern[i][j] = pattern2[i][j];
      }
    }

  }
}
