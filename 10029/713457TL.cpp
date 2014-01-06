#include <iostream>
using namespace std;

int main()
{
  //    代入
  int n;
  cin >> n;
  int* array = new int[n];
  for (int i=0; i<n; i++)
  {
    cin >> array[i];
  }

  int tmp;

  //    ソート
  for (int i=0; i<n; i++)
  {
    if (i == n-1) break;
    if ( array[i] > array[i+1] ) 
    {
      tmp = array[i];
      array[i] = array[i+1];
      array[i+1] = tmp;
      if ( i != 0 ) i-=2;
    }
  }
  
  //    表示
  for (int i=0; i<n; i++)
  {
    if (i == n-1)
    {
      cout << array[i] << endl;
    }else
    {
      cout << array[i] << ' ' << flush;
    }
  }

  delete[] array;
}
