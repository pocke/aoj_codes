#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string word;
  cin >> word;
  transform(word.begin(), word.end(), word.begin(), ::toupper);
  int count = 0;

  while (true)
  {
    string sentence;
    cin >> sentence;
    if ( sentence == "END_OF_TEXT" ) break;

    transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);
    if ( word == sentence )
    {
      count++;
    }
  }
  cout << count << endl;
}
