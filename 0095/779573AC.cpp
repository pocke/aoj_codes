#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Entrant
{
  int num;
  int wakasagi;

  bool operator<(const Entrant& right) const
  {
    return wakasagi == right.wakasagi ? num > right.num : wakasagi < right.wakasagi;
  }
};

int main(void)
{
  int n;
  cin >> n;
  vector<Entrant> entrants(n);
  for (auto& e : entrants)
  {
    cin >> e.num >> e.wakasagi;
  }
  sort(entrants.begin(), entrants.end());
  cout << entrants.back().num << " " << entrants.back().wakasagi << endl;
  return 0;
}