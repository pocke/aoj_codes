#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  int buf;
  int n;
  cin >> n;
  vector<int> s;
  for (int i = 0; i < n; ++i)
  {
    cin >> buf;
    s.push_back(buf);
  }

  int q;
  cin >> q;
  vector<int> t;
  for (int i = 0; i < q; ++i)
  {
    cin >> buf;
    t.push_back(buf);
  }

  sort(s.begin(), s.end());

  int result = 0;
  for (auto i : t)
  {
    if ( binary_search(s.begin(), s.end(), i) )
    {
      ++result;
    }
  }

  cout << result << endl;

  return 0;
}