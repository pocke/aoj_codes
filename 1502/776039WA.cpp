#include <iostream>
using namespace std;

int main(void)
{
  int result = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int hp;
    cin >> hp;
    result += hp - i/4 > 0 ? hp - i/4 : 0;
  }
  cout << result << endl;
  return 0;
}