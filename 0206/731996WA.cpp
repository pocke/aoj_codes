#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int expenses;
    cin >> expenses;
    if ( expenses == 0 ) break;
    int i;
    int sum = 0;
    for (i = 0; i < 12 && sum < expenses; i++)
    {
      int revenue, spending;
      cin >> revenue >> spending;
      sum += revenue - spending;
    }
    for (i = i; i < 12; i++)
    {
      int d,dm;
      cin >> d >> dm;
    }
    if (i == 12 && sum < expenses)
    {
      cout << "NA" << endl;
    }
    else
    {
      cout << i << endl;
    }
  }
  return 0;
}
