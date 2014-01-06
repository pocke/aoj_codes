#include <iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

class Room
{
  public:
    Room(int n);
    ~Room();

  public:
    int LoopNum();
    bool isLoop(Point& p, bool** this_loop_passed);

  private:
    bool** MakeAlreadyPass();
    void KillAlreadyPass(bool** ptrptr);

  private:
    int m_size;
    Point** m_room;
    bool** m_already_pass; 
};

Room::Room(int n)
{
  m_size = n;
  m_room = new Point*[m_size];
  for (int i = 0; i < m_size; ++i)
  {
    m_room[i] = new Point[m_size];
  }

  for (int i = 0; i < m_size; ++i)
  {
    for (int j = 0; j < m_size; ++j)
    {
      cin >> m_room[i][j].x >> m_room[i][j].y;
    }
  }
  m_already_pass = MakeAlreadyPass();
}

Room::~Room()
{
  for (int i = 0; i < m_size; ++i)
  {
    delete[] m_room[i];
  }
  delete[] m_room;

  KillAlreadyPass(m_already_pass);
}

int Room::LoopNum()
{
  int result = 0;
  for (int i = 0; i < m_size; ++i)
  {
    for (int j = 0; j < m_size; ++j)
    {
      bool** this_loop_passed = MakeAlreadyPass();
      Point p = { i, j };
      if (isLoop(p, this_loop_passed) )
      {
        ++result;
      }
      KillAlreadyPass(this_loop_passed);
    }
  }
  return result;
}

bool Room::isLoop(Point& p, bool** this_loop_passed)
{
  if (this_loop_passed[p.x][p.y])
  {
    return true;
  }
  if (m_already_pass[p.x][p.y])
  {
    return false;
  }
  m_already_pass[p.x][p.y] = this_loop_passed[p.x][p.y] = true;
  return isLoop(m_room[p.y][p.x], this_loop_passed);
}

bool** Room::MakeAlreadyPass()
{
  bool** buf = new bool*[m_size];
  for (int i = 0; i < m_size; ++i)
  {
    buf[i] = new bool[m_size];
  }
  //fill_n(buf[0], m_size * m_size, false);
  for (int i = 0; i < m_size; ++i)
  {
    for (int j = 0; j < m_size; ++j)
    {
      buf[i][j] = false;
    }
  }
  return buf;
}

void Room::KillAlreadyPass(bool** ptrptr)
{
  for (int i = 0; i < m_size; ++i)
  {
    delete[] ptrptr[i];
  }
  delete[] ptrptr;
}

int main(void)
{
  int n;
  while (true)
  {
    cin >> n;
    if (n == 0) break;

    Room room(n);
    cout << room.LoopNum() << endl;
  }
  return 0;
}
