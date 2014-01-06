#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    int* sequence = new int[n];
    for (int i=0; i<n; i++)
    {
      cin >> sequence[i];
    }
    int* result_sequence = new int[n];
    int result_num = 0;

    while (true)
    {
      for (int i=0; i<n; i++)
      {
        result_sequence[i] = 0;
      }
      for (int i=0; i<n; i++)   //  出現頻度操作
      {
        for (int j=0; j<n; j++)
        {
          if ( sequence[i] == sequence[j] )
          {
            result_sequence[i]++;
          }
        }
      }
      result_num++;

      bool flag = true;
      for (int i=0; i<n && flag; i++)
      {
        if ( sequence[i] != result_sequence[i] )
        {
          flag = false;
        }
      }
      if ( flag )   //不動点になっていれば
      {
        break;
      }
      else
      {
        for (int i=0; i<n; i++)
        {
          sequence[i] = result_sequence[i];
        }
      }
    }

    cout << result_num-1 << endl;
    for (int i=0; i<n; i++)
    {
      cout << result_sequence[i] << flush;
      if ( i == n-1 )
      {
        cout << endl;
      }
      else
      {
        cout << ' ' << flush;
      }
    }

    delete[] result_sequence;
    delete[] sequence;
  } //  データセット毎
}
