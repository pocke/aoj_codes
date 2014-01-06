#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  int ice_creams[10];
  int ice_index;
  while (true)
  {
    cin >> n;
    if (n == 0) break;
    fill_n(ice_creams, 10, 0);
    for (int i = 0; i < n; ++i)
    {
      cin >> ice_index;
      ++ice_creams[ice_index];
    }

    for (int i = 0; i < 10; ++i)
    {
      if (ice_creams[i] == 0)
      {
        cout << '-' << endl;
      }
      else
      {
        for (int j = 0; j < ice_creams[i]; ++j)
        {
          cout << '*';
        }
        cout << endl;
      }
    }
  }
  return 0;
}
