#include <iostream>
using namespace std;

struct Player
{
  int num;
  double time;
};

void PlayerSwap( Player* player1, Player* player2 )
{
  Player tmp;
  tmp = *player1;
  *player1 = *player2;
  *player2 = tmp;
}

void PlayerSort( Player* players, int length)
{
  for (int i=1; i<length; i++)
  {
    for (int j=i; j !=0 && players[j].time < players[j-1].time; j--)
    {
      PlayerSwap(&players[j], &players[j-1]);
    }
  }
}

int main()
{
  const int player_length = 24;
  Player players[player_length];
  Player final_players[8];
  for (int i=0; i<player_length; i++)
  {
    cin >> players[i].num >> players[i].time;
  }

  for (int i=0; i<3; i++)
  {
    Player* plr[8];
    for (int j=0; j<8; j++)
    {
      plr[j] = &players[i*8+j];
    }
    PlayerSort( *plr, 8 );
    for (int j=0; j<2; j++)
    {
      final_players[i*2+j] = players[i*8+j];
      players[i*8+j].time = 1000;
    }
  }

  PlayerSort( players, player_length );
  final_players[6] = players[0];
  final_players[7] = players[1];

  for (int i=0; i<8; i++)
  {
    cout << final_players[i].num << ' ' << final_players[i].time << endl;
  }
}
