#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Place
{
  int index;
  int sum;

  bool operator<( const Place& right ) const
  {
    return sum == right.sum ? index < right.index : sum > right.sum;
  }
};

int main(void)
{
  while (true)
  {
    int n, m;
    cin >> n >> m;
    if (n == 0 and m == 0 ) break;
    vector<Place> result(m);
    for (int i = 0; i < m; ++i)
    {
      result[i].index = i + 1;
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        int buf;
        cin >> buf;
        result[j].sum += buf;
      }
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < m; ++i)
    {
      cout << result[i].index;
      if (i == m - 1)
      {
        cout << endl;
      }
      else
      {
        cout << ' ';
      }
    }
  }
  return 0;
}