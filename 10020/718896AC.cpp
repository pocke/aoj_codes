#include <iostream>
using namespace std;

int main()
{
  char ch;
  int count[26];
  for (int i=0; i<26; i++)
  {
    count[i] = 0;
  }
  while(cin >> ch)
  {
    if ( 'A' <= ch && ch <= 'Z' )
    {
      count[ch-65]++;
    }
    else if( 'a' <= ch && ch <= 'z' )
    {
      count[ch-97]++;
    }
    else
    {
      continue;
    }
  }
  for (int i=0; i<26; i++)
  {
    cout << (char)(97 + i) << " : " << count[i] << endl;
  }
  return 0;
}
