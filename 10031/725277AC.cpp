#include <iostream>
using namespace std;

void MergeSort( int* lst, int length )
{
  //**************************配列を分ける
  int half = length/2;
  int* lst2 = lst + half;
  if ( length != 1 )
  {
    MergeSort( lst, half );
    MergeSort( lst2, length - half);
  }
  else
  {
    return;
  }

  //**************************まーじ
  int* tmp_lst = new int[length];
  for (int i=0,j=0,k=0; i<length; i++)
  {
    if ( j < half && k < length-half )
    {
      if ( lst[j] < lst2[k] )   //ちっちゃい方をtmp_lstに追加
      {
        tmp_lst[i] = lst[j];
        j++;
      }
      else
      {
        tmp_lst[i] = lst2[k];
        k++;
      }
    }
    else if ( j >= half )
    {
      tmp_lst[i] = lst2[k];
      k++;
    }
    else
    {
      tmp_lst[i] = lst[j];
      j++;
    }
  }
  for (int i=0; i<length; i++)    //tmp_lstをlstにコピー
  {
    lst[i] = tmp_lst[i];
  }
  delete[] tmp_lst;
}

bool search( const int* lst, int length, int num )
{
  while ( 0 < length )
  {
    int centre = length/2;
    if ( lst[centre] == num )
    {
      return true;
    }
    else if ( lst[centre] < num )
    {
      lst += centre + 1;
      length = length - centre -1;
    }
    else
    {
      length = centre;
    }
  }
  return false;
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
  MergeSort(s, n);

  int count = 0;
  int q;
  cin >> q;
  for (int i=0; i<q; i++)
  {
    int num;
    cin >> num;
    if ( search(s, n, num) )
    {
      count++;
    }
  }

  cout << count << endl;

  delete[] s;
}
