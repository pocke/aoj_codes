#include <iostream>
using namespace std;

bool search( int* lst, int length, int num )
{
  if ( lst[length-1] == num ) return true;
  int sentinel = lst[length-1];   //  番兵
  lst[length-1] = num;

  int i;
  for (i=0; lst[i] != num; i++)
  {
    //  空
  }
  lst[length-1] = sentinel;
  if ( i < length-1 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int n;
  cin >> n;
  int* s = new int[n];
  for (int i=0; i<n; i++)
  {
    cin >> s[i];
  }

  int count = 0;
  int q;
  cin >> q;
  for (int i=0; i<q; i++)
  {
    int num;
    cin >> num;
    if ( search( s, n, num ) )
    {
      count++;
    }
  }

  cout << count << endl;

  delete[] s;
}
