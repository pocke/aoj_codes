#include <iostream>
using namespace std;

int main(void)
{
  int n, k;
  int max;
  int sum;
  int* num_sequence;
  while (true)
  {
    cin >> n >> k;
    if ( n == 0 && k == 0 ) break;

    //int* num_sequence = new int[n];
    num_sequence = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> num_sequence[i];
    }

    max = -999999;
    for (int j = 0; j < n-k+1; j++)
    {
      sum = 0;
      for (int i = 0; i < k; i++)
      {
        sum += num_sequence[i+j];
      }
      if ( sum > max ) max = sum;
    }

    cout << max << endl;

    delete[] num_sequence;
  }
  return 0;
}
