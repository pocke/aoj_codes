#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int alphabet[26];
  for (int i=0; i<26; i++)
  {
    alphabet[i] = 0;
  }

  while (true)
  {
    char ch;
    cin >> ch;
    if ( cin.eof() ) break;

    if ( 65 <= ch && ch <= 90 )
    {
      alphabet[ch-65]++;
    }
    else if ( 97 <= ch && ch <=122 )
    {
      alphabet[ch-97]++;
    }
  }

  for (int i=0; i<26; i++)
  {
    printf("%c : %d\n", i+97, alphabet[i]);
  }
}
