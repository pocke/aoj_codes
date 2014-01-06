#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i=0; i<n; i++)
  {
    int score = 0;
    int base = 0;
    int out_count = 0;
    while (true)
    {
      string event;
      getline(cin, event);
      if ( event == "HIT" )
      {
        if ( base == 3 )
        {
          score++;
        }
        else
        {
          base++;
        }
      }
      else if ( event == "HOMERUN" )
      {
        score += 1 + base;
        base = 0;
      }
      else if ( event == "OUT" )
      {
        out_count++;
        if ( out_count == 3 ) break;
      }
    } //  while(true)
    cout << score << endl;
  } //  for
}
