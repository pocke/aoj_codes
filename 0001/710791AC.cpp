#include <iostream>
using namespace std;

int main()
{
  int m[10];
  for (int i=0; i<10; i++)
  {
    cin >> m[i];
  }

  for(int i=0; i<3; i++)
  {
    int max = 0;
    for(int j=0; j<9; j++)
    {
      if ( m[max] < m[j+1] ) max = j+1;
    }
    cout << m[max] << endl;
    m[max] = -1;
  }
}