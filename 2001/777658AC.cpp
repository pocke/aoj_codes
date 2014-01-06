#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Bar
{
  int height;
  int p;
  int q;

  bool operator<( const Bar& right ) const
  {
    return height > right.height;
  }
};

class Amida
{
  public:
    Amida(int line_num, int bar_num, int start_line);

  public:
    int Go();

  private:
    int m_line_num;
    int m_bar_num;
    int m_start_line;
    vector<Bar> m_bars;
};

Amida::Amida(int line_num, int bar_num, int start_line)
{
  m_line_num = line_num;
  m_bar_num = bar_num;
  m_start_line = start_line;

  for (int i = 0; i < m_bar_num; ++i)
  {
    Bar buf_bar;
    cin >> buf_bar.height >> buf_bar.p >> buf_bar.q;
    m_bars.push_back(buf_bar);
  }
  sort(m_bars.begin(), m_bars.end() );
}

int Amida::Go()
{
  int now = m_start_line;

  for (Bar bar : m_bars)
  {
    if (bar.p == now)
    {
      now = bar.q;
    }
    else if (bar.q == now)
    {
      now = bar.p;
    }
  }

  return now;
}

int main(void)
{
  while (true)
  {
    int n, m, a;
    cin >> n >> m >> a;
    if (n == 0 and m == 0 and a == 0) break;
    Amida amida(n, m, a);
    cout << amida.Go() << endl;
  }
}