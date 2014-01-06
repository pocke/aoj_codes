#include <iostream>
using namespace std;

int match_num(int n, int sum, int i_ = 0)
{
  if (sum == 0 and n == 0) return 1;
  if (sum < 0 or n == 0) return 0;
  int result = 0;
  for (int i = i_; i < 9; ++i)
  {
    result += match_num(n - 1, sum - i, i + 1);
  }
  return result;
}

int main(void)
{
  int n, sum;
  while (true)
  {
    cin >> n >> sum;
    if (n == 0 and sum == 0) break;
    cout << match_num(n, sum) << endl;
  }
  return 0;
}
