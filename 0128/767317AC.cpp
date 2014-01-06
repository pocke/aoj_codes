#include <iostream>
#include <cmath>
using namespace std;

class Soroban_col
{
  public:
    Soroban_col();
    ~Soroban_col();

  public:
    void Show(int i);
    void Set(int n);

  private:
    char* m_soroban_col;
};

Soroban_col::Soroban_col()
{
  m_soroban_col = new char[8];
}

Soroban_col::~Soroban_col()
{
  delete[] m_soroban_col;
}

void Soroban_col::Show(int i)
{
  cout << m_soroban_col[i];
}

void Soroban_col::Set(int n)
{
  if (n < 5)
  {
    m_soroban_col[0] = '*';
    m_soroban_col[1] = ' ';
  }
  else
  {
    m_soroban_col[0] = ' ';
    m_soroban_col[1] = '*';
  }

  m_soroban_col[2] = '=';

  for (int i = 3; i < 3 + n % 5; ++i)
  {
    m_soroban_col[i] = '*';
  }
  m_soroban_col[3+n%5] = ' ';
  for (int i = 4 + n % 5; i < 8; ++i)
  {
    m_soroban_col[i] = '*';
  }
}

class Soroban
{
  public:
    Soroban(int n);
    ~Soroban();

  public:
    void Show();

  private:
    Soroban_col* m_soroban;
};

Soroban::Soroban(int n)
{
  m_soroban = new Soroban_col[5];
  for (int i = 5; i > 0; --i)
  {
    int buf = (n % (int)pow(10, i) ) / (int)pow(10, i-1);
    m_soroban[5-i].Set(buf);
  }
}

Soroban::~Soroban()
{
  delete[] m_soroban;
}

void Soroban::Show()
{
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      m_soroban[j].Show(i);
    }
    cout << endl;
  }
}

int main(void)
{
  int n;
  cin >> n;
  while (true)
  {
    Soroban soroban(n);
    soroban.Show();
    cin >> n;
    if (cin.eof()) break;
    cout << endl;
  }
  return 0;
}