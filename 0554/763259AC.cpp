#include <iostream>
using namespace std;

int main(void)
{
  int n;
  int sum = 0;
  while (cin >> n)
  {
    sum += n;
  }
  cout << sum / 60 << endl
       << sum % 60 << endl;
  return 0;
}
