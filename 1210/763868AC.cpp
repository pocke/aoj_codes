#include <iostream>
#include <string>
using namespace std;

class Die
{
  public:
    Die();

  public:
    void North();
    void East();
    void South();
    void West();
    int Up_return();

  private:
    int m_up;
    int m_north;
    int m_west;
};

Die::Die()
{
  m_up = 1;
  m_north = 2;
  m_west = 3;
}

void Die::North()
{
  int buf_up = m_up;
  m_up = 7 - m_north;
  m_north = buf_up;
}

void Die::East()
{
  int buf_up = m_up;
  m_up = m_west;
  m_west = 7 - buf_up;
}

void Die::South()
{
  int buf_up = m_up;
  m_up = m_north;
  m_north = 7 - buf_up;
}

void Die::West()
{
  int buf_up = m_up;
  m_up = 7 - m_west;
  m_west = buf_up;
}

inline int Die::Up_return()
{
  return m_up;
}

int main(void)
{
  int n;
  string command;
  while (true)
  {
    cin >> n;
    if (n == 0) break;
    Die die;

    for (int i = 0; i < n; ++i)
    {
      cin >> command;
      if (command == "north")
      {
        die.North();
      }
      else if (command == "east")
      {
        die.East();
      }
      else if (command == "south")
      {
        die.South();
      }
      else if (command == "west")
      {
        die.West();
      }
    }
    cout << die.Up_return() << endl;
  }
  return 0;
}
