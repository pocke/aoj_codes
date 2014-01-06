#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, q;
  cin >> n >> q;
  vector<int> cards(n);
  for (auto& c : cards)
  {
    cin >> c;
  }

  for (int i = 0; i < q; ++i)
  {
    int max_mod = 0;
    int query;
    cin >> query;
    for (auto c : cards)
    {
      max_mod = max(max_mod, c % query);
    }
    cout << max_mod << endl;
  }
  return 0;
}