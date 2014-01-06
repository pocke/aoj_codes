#include <iostream>
using namespace std;

int main()
{
  bool cards[4][13];
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<13; j++)
    {
      cards[i][j] = false;
    }
  }

  int n;
  cin >> n;
  for (int trmp=0; trmp<n; trmp++)
  {
    char suit;
    cin >> suit;
    int suit_i = suit == 'S' ? 0 :
                 suit == 'H' ? 1 :
                 suit == 'C' ? 2 :
                        /*D*/  3 ;
    int num;
    cin >> num;
    cards[suit_i][num-1] = true;
  }

  for (int i=0; i<4; i++)
  {
    char suit = i == 0 ? 'S' :
                i == 1 ? 'H' :
                i == 2 ? 'C' :
                   /*3*/ 'D' ;
    for (int j=0; j<13; j++)
    {
      if (! cards[i][j] )
      {
        cout << suit << ' ' << j+1 << endl;
      }
    }
  }
}
