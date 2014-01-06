#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isArithmeticProgression(const vector<int>& grasses)
{
  int diff = grasses[1] - grasses[0];
  for (int i = 1, size = grasses.size(); i < size - 1; ++i)
  {
    if (grasses[i+1] - grasses[i] != diff) return false;
  }
  return true;
}

int solve(const vector<int>& grasses)
{
  for (int i = 0, size = grasses.size(); i < size; ++i)
  {
    vector<int> grasses2 = grasses;
    grasses2.erase(grasses2.begin() + i);
    if (isArithmeticProgression(grasses2))
    {
      return grasses[i];
    }
  }
  return -1;
}

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<int> grasses(n+1);
    for (auto& g : grasses)
    {
      cin >> g;
    }

    cout << solve(grasses) << endl;
  }
  return 0;
}