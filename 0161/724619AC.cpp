#include <iostream>
#include <climits>
using namespace std;

struct Team
{
  int num;
  int time;   //sec
};

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;

    Team victory = { 0, INT_MAX, };
    Team second  = { 0, INT_MAX, };
    Team booby   = { 0, 0,       };
    Team lowest  = { 0, 0,       };
    for (int data=0; data<n; data++)
    {
      Team tmp_team;
      cin >> tmp_team.num;
      tmp_team.time = 0;
      for (int i=0; i<4; i++)
      {
        int min,sec;
        cin >> min >> sec;
        tmp_team.time += min*60 + sec;
      }

      if ( tmp_team.time < victory.time )
      {
        second = victory;
        victory = tmp_team;
      }
      else if ( tmp_team.time < second.time )
      {
        second = tmp_team;
      }

      if ( lowest.time < tmp_team.time )
      {
        booby = lowest;
        lowest = tmp_team;
      }
      else if ( booby.time < tmp_team.time )
      {
        booby = tmp_team;
      }
    }
    cout << victory.num << endl
         << second.num  << endl
         << booby.num   << endl;
  }
}
