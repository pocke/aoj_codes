#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int goal;
    cin >> goal;
    if ( goal == 0 ) break;
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      int start, finish;
      cin >> start >> finish;
      sum += finish - start;
    }
    if (sum < goal)
    {
      cout << goal - sum << endl;
    }
    else
    {
      cout << "OK" << endl;
    }
  }
  return 0;
}
