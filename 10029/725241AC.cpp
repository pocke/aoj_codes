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

int main()
{
  int length;
  cin >> length;
  int* arr = new int[length];
  for (int i=0; i<length; i++)
  {
    cin >> arr[i];
  }
  MergeSort(arr, length);
  for (int i=0; i<length-1; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << arr[length-1] << endl;
  delete[] arr;
}
