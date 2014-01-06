#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    char **ch = new char*[n];
    for (int i=0; i<n; i++)
    {
      ch[i] = new char[2];
    }

    for (int i=0; i<n; i++)
    {
      cin >> ch[i][0] >> ch[i][1];
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++)
    {
      char str;
      cin >> str;
      for (int j=0; j<n; j++)
      {
        if ( str == ch[j][0] )
        {
          str = ch[j][1];
          break;
        }
      }
      cout << str;
    }
    cout << endl;

    for (int i=0; i<n; i++)
    {
      delete[] ch[i];
    }
    delete[] ch;
  }
}
