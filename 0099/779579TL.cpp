#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, q;
  cin >> n >> q;
  vector<int> entrants(n);
  for (int i = 0, index, score; i < q; ++i)
  {
    cin >> index >> score;
    entrants[index - 1] += score;
    int max = 0;
    int max_index = 0;
    for (int j = 0; j < n; ++j)
    {
      if (max < entrants[j])
      {
        max = entrants[j];
        max_index = j;
      }
    }
    cout << max_index + 1 << " " << max<< endl;
  }
}