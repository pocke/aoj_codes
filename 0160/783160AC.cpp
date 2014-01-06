#include <iostream>
using namespace std;

int Fee(int size, int weight)
{
  return (size <= 60 and weight <= 2) ? 600 :
         (size <= 80 and weight <= 5) ? 800 :
         (size <= 100 and weight <= 10) ? 1000 :
         (size <= 120 and weight <= 15) ? 1200 :
         (size <= 140 and weight <= 20) ? 1400 :
         (size <= 160 and weight <= 25) ? 1600 : 0;
}

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
      int x, y, h, weight;
      cin >> x >> y >> h >> weight;
      result += Fee(x + y + h, weight);
    }
    cout << result << endl;
  }
  return 0;
}