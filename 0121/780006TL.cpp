#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Point
{
  int i;
  int j;
};

class Puzzle
{
  public:
    Puzzle();
    Puzzle(bool dummy);
    Puzzle(vector<vector<int>> puzzle, int g);
    bool operator==(const Puzzle& right) const;
    unsigned long MakeHash();
    bool isRight();
    vector<Puzzle> ChangePuzzle();
    int Generation();

  private:
    bool CheckIndex(Point p);

  private:
    vector<vector<int>> m_puzzle;
    int m_generation;

  private:
    const static int m_height = 2;
    const static int m_width = 4;
    static Puzzle right_ans;
};

Puzzle Puzzle::right_ans(true);

Puzzle::Puzzle() :
  m_puzzle(m_height, vector<int>(m_width)), m_generation(0)
{
  for (auto& line : m_puzzle)
  {
    for (auto& card : line)
    {
      cin >> card;
    }
  }
  if (cin.eof() )
  {
    exit(0);
  }
}

inline Puzzle::Puzzle(bool dummy) :
  m_puzzle(m_height, vector<int>(m_width)), m_generation(0)
{
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      m_puzzle[i][j] = j + i * 4;
    }
  }
}

inline Puzzle::Puzzle(vector<vector<int>> puzzle, int g) :
  m_generation(g)
{
  m_puzzle = puzzle;
}

bool Puzzle::operator==(const Puzzle& right) const
{
  return m_puzzle == right.m_puzzle;
}

unsigned long Puzzle::MakeHash()
{
  unsigned long result;
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      result |= ((unsigned long)(m_puzzle[i][j])) << ((j + 4 * i) * 4);
    }
  }
  return result;
}

bool Puzzle::isRight()
{
  return *this == right_ans;
}

vector<Puzzle> Puzzle::ChangePuzzle()
{
  Point zero_point;
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      if (m_puzzle[i][j] == 0)
      {
        zero_point.i = i;
        zero_point.j = j;
      }
    }
  }
  vector<Point> change_points;
  change_points.push_back( {zero_point.i + 1, zero_point.j} );
  change_points.push_back( {zero_point.i - 1, zero_point.j} );
  change_points.push_back( {zero_point.i, zero_point.j + 1} );
  change_points.push_back( {zero_point.i, zero_point.j - 1} );

  vector<Puzzle> result;
  for (Point p : change_points)
  {
    if (CheckIndex(p) )
    {
      auto new_puzzle = m_puzzle;
      new_puzzle[zero_point.i][zero_point.j] = new_puzzle[p.i][p.j];
      new_puzzle[p.i][p.j] = 0;
      Puzzle buf_puzzle(new_puzzle, m_generation + 1);
      result.push_back(buf_puzzle);
    }
  }
  return result;
}

inline int Puzzle::Generation()
{
  return m_generation;
}

bool Puzzle::CheckIndex(Point p)
{
  return ( 0 <= p.i and p.i < m_height ) and ( 0 <= p.j and p.j < m_width );
}

class Game
{
  public:
    Game();
    int DoGame();

  private:
    void Add_Hash(unsigned long hash);
    bool IncludeHash(unsigned long hash);

  private:
    set<unsigned long> m_hash;
    queue<Puzzle> m_puzzle_que;
};

Game::Game()
{
  Puzzle first;
  m_puzzle_que.push(first);
}

inline void Game::Add_Hash(unsigned long hash)
{
  m_hash.insert(hash);
}

inline bool Game::IncludeHash(unsigned long hash)
{
  return m_hash.end() != m_hash.find(hash);
}

int Game::DoGame()
{
  if (m_puzzle_que.front().isRight() )
  {
    return 0;
  }
  while (true)
  {
    Puzzle puzzle = m_puzzle_que.front();
    m_puzzle_que.pop();
    auto puzzles = puzzle.ChangePuzzle();
    for (auto p : puzzles)
    {
      if (p.isRight() )
      {
        return p.Generation();
      }
      auto h = p.MakeHash();
      if (IncludeHash(h))
      {
        continue;
      }
      Add_Hash(h);
      m_puzzle_que.push(p);
    }
  }
}

int main(void)
{
  while (true)
  {
    Game game;
    cout << game.DoGame() << endl;
  }
  return 0;
}