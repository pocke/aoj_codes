#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string dummy;
  getline(cin, dummy);
  string first_string = "zzzzzzzzzzzzzzzzzzzzz";
  for (int i=0; i<n; i++)
  {
    string word;
    getline(cin, word);
    if ( word < first_string )
    {
      first_string = word;
    }
  }
  cout << first_string << endl;
}
