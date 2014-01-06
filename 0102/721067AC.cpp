#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    int **array = new int*[n+1];
    for (int i=0; i<n+1; i++)
    {
      array[i] = new int[n+1];
    }

    for (int i=0; i<n+1; i++)
    {
      for (int j=0; j<n+1; j++)
      {
        array[i][j] = 0;
      }
    }

    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
      {
        cin >> array[i][j];
      }
    }

    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
      {
        array[n][j] += array[i][j];
        array[i][n] += array[i][j];
        array[n][n] += array[i][j];
      }
    }

    for (int i=0; i<=n; i++)
    {
      for (int j=0; j<=n; j++)
      {
        printf("%5d", array[i][j]);
      }
      cout << endl;
    }

    for (int i=0; i<n+1; i++)
    {
      delete[] array[i];
    }
    delete[] array;
  }
}
