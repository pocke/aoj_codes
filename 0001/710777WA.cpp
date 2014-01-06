#include <iostream>
using namespace std;

int main()
{
  int m[10];
  int max = 0;
  for (int i=0; i<10; i++)
  {
    cin >> m[10];
  }
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<9; j++)
    {
      if ( m[i] < m[i+1] ) max = i+1;
    }
    cout << m[max] << endl;
    m[max] = -1;
  }
}
