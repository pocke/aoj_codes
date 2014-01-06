#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Hand
{
  public:
    Hand(vector<int> cards);

  public:
    string what_hand();

  private:
    bool is_one_pair();
    bool is_two_pair();
    bool is_three_card();
    bool is_straight();
    bool is_full_house();
    bool is_four_card();

  private:
    vector<int> m_hand;
};

Hand::Hand(vector<int> cards) :
  m_hand(5)
{
  for (int i = 0; i < 5; ++i)
  {
    m_hand[i] = cards[i];
  }
  sort(m_hand.begin(), m_hand.end());
}

string Hand::what_hand()
{
  if (is_four_card())
  {
    return "four card";
  }
  else if (is_full_house())
  {
    return "full house";
  }
  else if (is_straight())
  {
    return "straight";
  }
  else if (is_three_card())
  {
    return "three card";
  }
  else if (is_two_pair())
  {
    return "two pair";
  }
  else if (is_one_pair())
  {
    return "one pair";
  }
  else
  {
    return "null";
  }
}

bool Hand::is_one_pair()
{
  int prev = -1;
  for (int card : m_hand)
  {
    if (prev == -1)
    {
      prev = card;
      continue;
    }
    if (prev == card) return true;
    prev = card;
  }
  return false;
}

bool Hand::is_two_pair()
{
  if ((m_hand[0] == m_hand[1] and m_hand[2] == m_hand[3]) or
      (m_hand[0] == m_hand[1] and m_hand[3] == m_hand[4]) or
      (m_hand[1] == m_hand[2] and m_hand[3] == m_hand[4]) )
  {
    return true;
  }
  else
  {
  return false;
  }
}

bool Hand::is_three_card()
{
  for (int i = 0; i < 3; ++i)
  {
    if (m_hand[i] == m_hand[i+1] and m_hand[i] == m_hand[i+2])
    {
      return true;
    }
  }
  return false;
}

bool Hand::is_straight()
{
  if (m_hand[0] == 1 and m_hand[1] == 10 and m_hand[2] == 11 and 
      m_hand[3] == 12 and m_hand[4] == 13)
  {
    return true;
  }

  int prev = -1;
  for (int card : m_hand)
  {
    if (prev == -1)
    {
      prev = card;
      continue;
    }
    if (prev + 1 != card)
    {
      return false;
    }
    prev = card;
  }
  return true;
}

bool Hand::is_full_house()
{
  if ((m_hand[0] == m_hand[1] and m_hand[0] == m_hand[2] and
       m_hand[3] == m_hand[4]) or
      (m_hand[2] == m_hand[3] and m_hand[2] == m_hand[4] and
       m_hand[0] == m_hand[1]) )
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Hand::is_four_card()
{
  if ((m_hand[0] == m_hand[1] and m_hand[0] == m_hand[2] and m_hand[0] == m_hand[3]) or
      (m_hand[1] == m_hand[2] and m_hand[1] == m_hand[3] and m_hand[1] == m_hand[4]) )
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main(void)
{
  cin >> noskipws;
  while (true)
  {
    vector<int> cards(5);
    char buf_ch;
    for (int& card : cards)
    {
      cin >> card;
      cin >> buf_ch;
    }
    if (cin.eof() ) break;

    Hand hand(cards);
    cout << hand.what_hand() << endl;
  }
  return 0;
}