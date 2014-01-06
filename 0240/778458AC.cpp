#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Bank
{
  public:
    Bank(int num, int type, int rate);

  public:
    static void SetYear(int year);
    bool operator<(const Bank& other) const;
    int num();

  private:
    static int m_year;
    double m_bank;
    int m_num;
};

Bank::Bank(int num, int type, int rate)
{
  m_num = num;
  if (type == 1)
  {
    //  $BC1Mx(B
    m_bank = 1 + m_year * rate / 100.0;
  }
  else
  {
    //  $BJ#Mx(B
    m_bank = pow(1 + rate / 100.0, m_year);
  }
}

inline void Bank::SetYear(int year)
{
  m_year = year;
}

bool Bank::operator<(const Bank& other) const
{
  return m_bank < other.m_bank;
}

int Bank::num()
{
  return m_num;
}

int Bank::m_year;

int main(void)
{
  int n;
  int year;
  while (cin >> n >> year)
  {
    Bank::SetYear(year);

    vector<Bank> banks;
    for (int i = 0; i < n; ++i)
    {
      int num, rate, type;
      cin >> num >> rate >> type;
      Bank buf_bank(num, type, rate);
      banks.push_back(buf_bank);
    }

    sort(banks.begin(), banks.end());
    cout << banks.back().num() << endl;
  }

  return 0;
}