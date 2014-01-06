#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main(void)
{
  int result = 1;
  int n;
  cin >> n;
  int* warriors = new int[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> warriors[i];
  }
  sort(warriors, warriors + n, greater<int>());
  for (int i = 0; i < n; ++i)
  {
    result += warriors[i] - i/4 > 0 ? warriors[i] - i/4 : 0;
  }
  cout << result << endl;
  return 0;
}