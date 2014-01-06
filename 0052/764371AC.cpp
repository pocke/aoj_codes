#include <iostream>
#include <cmath>
using namespace std;

int five_num(int num, int i = 1)
{
  int buf_i = (int)pow(5, i);
  if (num / buf_i == 0) return 0;
  return num / (int)pow(5, i) + five_num(num, i + 1);
}

int main(void)
{
  int n;
  while (true)
  {
    cin >> n;
    if (n == 0) break;
    cout << five_num(n) << endl;
  }
  return 0;
}
