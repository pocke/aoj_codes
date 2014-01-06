#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int dataset=0; dataset<n; dataset++)
  {
    int triangle[3];
    cin >> triangle[0] >> triangle[1] >> triangle[2];
    for (int i=0; i<3; i++)   //sort
    {
      int tmp;
      for (int j=i; j != 0 && triangle[j] > triangle[j-1]; j--)
      {
        tmp = triangle[j];
        triangle[j] = triangle[j-1];
        triangle[j-1] = tmp;
      }
    }

    if ( triangle[0]*triangle[0] == triangle[1]*triangle[1] + triangle[2]*triangle[2] )
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }  
}
