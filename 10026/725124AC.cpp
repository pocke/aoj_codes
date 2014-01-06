#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  while(true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    int* s = new int[n];
    for (int i=0; i<n; i++)
    {
      cin >> s[i];
    }

    double avg = 0;
    for (int i=0; i<n; i++)     //平均
    {
      avg += s[i];
    }
    avg /= n;

    double alpha = 0;
    for (int i=0; i<n; i++)
    {
      alpha += (s[i] - avg)*(s[i] - avg);
    }
    alpha /= n;

    alpha = sqrt(alpha);

    printf("%.8lf\n", alpha);
    delete[] s;
  }
}