#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    int max = 0;
    int min = 500;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = 0; j < 5; j++)
      {
        int score;
        cin >> score;
        sum += score;
      }
      if ( min > sum )
      {
        min = sum;
      }
      if ( max < sum )
      {
        max = sum;
      }
    }
    cout << max << ' ' << min << endl;
  }
  return 0;
}
