#include <iostream>
using namespace std;

int main()
{
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];

  for (int i=1; i<3; i++)
  {
    int tmp;
    for (int j=i; j != 0 && arr[j] < arr[j-1]; j--)
    {
      tmp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = tmp;
    }
  }
  cout << arr[0] << arr[1] << arr[2] << endl;
}
