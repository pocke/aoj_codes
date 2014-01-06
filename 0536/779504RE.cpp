#include <iostream>
#include <vector>
using namespace std;

class Cards
{
  public:
    Cards(int n);

  public:
    void Shuffle(int x, int y);
    int Ans(int p, int q, int r);

  private:
    int m_n;
    vector<int> m_cards;
};

Cards::Cards(int n) :
  m_n(n), m_cards(n)
{
  for (int i = 0; i < n; ++i)
  {
    m_cards[i] = i + 1;
  }
}

void Cards::Shuffle(int x, int y)
{
  vector<int> new_cards;
  for (int i = y; i < m_n; ++i)
  {
    new_cards.push_back(m_cards[i]);
  }

  for (int i = x; i < y; ++i)
  {
    new_cards.push_back(m_cards[i]);
  }

  for (int i = 0; i < x; ++i)
  {
    new_cards.push_back(m_cards[i]);
  }
  m_cards.swap(new_cards);
}

int Cards::Ans(int p, int q, int r)
{
  int result = 0;
  for (int i = p - 1; i < q; ++i)
  {
    if (m_cards[i] <= r)
    {
      result++;
    }
  }
  return result;
}

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;
    Cards cards(n);

    int m;
    cin >> m;
    int p, q, r;
    cin >> p >> q >> r;

    for (int i = 0; i < m; ++i)
    {
      int x, y;
      cin >> x >> y;
      cards.Shuffle(x, y);
    }
    cout << cards.Ans(p, q, r) << endl;
  }
  return 0;
}