#include <iostream>
using namespace std;

bool search( int* lst, int length, int num )
{
  int le = length-1;
  if ( lst[le] == num ) return true;
  int sentinel = lst[le];   //  番兵
  lst[le] = num;

  int i;
  for (i=0; lst[i] != num; i++)
  {
    //  空
  }
  lst[le] = sentinel;
  if ( i < le )
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
