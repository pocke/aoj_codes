#include <iostream>
#include <algorithm>
using namespace std;

int prime_num(int n)
{
  ++n;
  bool* array = new bool[n];
  fill_n(array, n, true);
  array[0] = array[1] = false;

  for (int i = 2; i < n; ++i)
  {
    if (!array[i]) continue;
    for (int j = i * 2; j < n; j += i)
    {
      array[j] = false;
    }
  }

  int result = 0;
  for (int i = 0; i < n; ++i)
  {
    if (array[i]) ++result;
  }

  delete[] array;
  return result;
}

int main(void)
{
  int n;
  while (cin >> n)
  {
    cout << prime_num(n) << endl;
  }
  return 0;
}