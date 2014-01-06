#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  bool flag = false;
  while (true)
  {
    vector<int> result;
    int a, b;
    cin >> a >> b;
    if (a==0 and b==0) break;
    if (flag) cout << endl;
    flag = true;
    for (int i = a; i <= b; ++i)
    {
      if ((i % 4 == 0 and i % 100 != 0) or i % 400 == 0)
      {
        result.push_back(i);
      }
    }
    if (result.empty())
    {
      cout << "NA" << endl;
    }
    else
    {
      for (int year : result)
      {
        cout << year << endl;
      }
    }
  }
  return 0;
}