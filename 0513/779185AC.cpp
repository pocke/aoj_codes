#include <iostream>
#include <vector>
using namespace std;

class Cards
{
  public:
    Cards(int n);
    void Shuffle(int k);
    void Show();

  private:
    void Cat(int k);
    void RiffleShuffle();
    
  private:
    vector<int> m_cards;
    int m_n;
};

Cards::Cards(int n) :
  m_cards(2 * n), m_n(n)
{
  for (int i = 0; i < 2 * n; ++i)
  {
    m_cards[i] = i + 1;
  }
}

void Cards::Shuffle(int k)
{
  if (k == 0)
  {
    RiffleShuffle();
  }
  else
  {
    Cat(k);
  }
}

void Cards::Cat(int k)
{
  vector<int> new_cards;
  
  for (int i = k; i < 2 * m_n; ++i)
  {
    new_cards.push_back(m_cards[i]);
  }
  for (int i = 0; i < k; ++i)
  {
    new_cards.push_back(m_cards[i]);
  }
  m_cards.swap(new_cards);
}

void Cards::RiffleShuffle()
{
  vector<int> even_cards;
  vector<int> odd_cards;
  for (int i = 0; i < m_n; ++i)
  {
    even_cards.push_back(m_cards[i]);
  }
  for (int i = m_n; i < 2 * m_n; ++i)
  {
    odd_cards.push_back(m_cards[i]);
  }

  vector<int> new_cards;
  for (int i = 0; i < m_n; ++i)
  {
    new_cards.push_back(even_cards[i]);
    new_cards.push_back(odd_cards[i]);
  }
  m_cards.swap(new_cards);
}

void Cards::Show()
{
  for (int card : m_cards)
  {
    cout << card << endl;
  }
}

int main(void)
{
  int n;
  cin >> n;
  Cards cards(n);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i)
  {
    int k;
    cin >> k;
    cards.Shuffle(k);
  }
  cards.Show();
  return 0;
}