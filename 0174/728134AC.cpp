#include <iostream>
#include <string>
using namespace std;

int main()
{
  while(true)
  {
    for (int i=0; i<3; i++)   //  dataset
    {
      string serves;
      getline(cin, serves);
      if ( serves[0] == '0' ) return 0;
      const char* str = serves.c_str();

      int score[2] = { 0, 0, };

      for (int i=1; str[i]; i++)    //  得点入力
      {
        switch(serves[i])
        {
          case 'A':
            score[0]++;
            break;
          case 'B':
            score[1]++;
            break;
        }
      }
      //  最後の一点
      if ( 10 <= score[0] && 10 <= score[1] )
      {
        if ( score[0] < score[1] )
        {
          score[1]++;
        }
        else
        {
          score[0]++;
        }
      }
      else if ( score[0] == 10 )
      {
        score[0]++;
      }
      else if ( score[1] == 10 )
      {
        score[1]++;
      }
      cout << score[0] << ' ' << score[1] << endl;
    }
  }
}
