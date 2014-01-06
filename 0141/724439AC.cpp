#include <iostream>
using namespace std;

class Guruguru
{
public:
  Guruguru(int n);
  ~Guruguru();

  void Show();

private:
  char** m_guruguru;
  int m_n;
  int m_now_i;
  int m_now_j;
  int m_direction;    //  0:上 1:右 2:下 3:左

  void make_guruguru();
  void put_point();
  void move_point();
  void change_direction();
  bool check_point();
};

Guruguru::Guruguru(int n)
{
  m_n = n;
  m_guruguru = new char*[m_n];
  for (int i=0; i<m_n; i++)
  {
    m_guruguru[i] = new char[m_n];
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      m_guruguru[i][j] = ' ';
    }
  }

  m_now_i = m_n-1;
  m_now_j = 0;
  m_direction = 0;
  make_guruguru();
}

Guruguru::~Guruguru()
{
  for (int i=0; i<m_n; i++)
  {
    delete[] m_guruguru[i];
  }
  delete[] m_guruguru;
}

void Guruguru::make_guruguru()
{
  int num = 0;
  while(true)
  {
    put_point();
    if (! check_point() )
    {
      if ( num == m_n-1 ) return;
      change_direction();
      num++;
    }
    move_point();
  }
}

void Guruguru::put_point()
{
  m_guruguru[m_now_i][m_now_j] = '#';
}

void Guruguru::move_point()
{
  switch(m_direction)
  {
  case 0:
    m_now_i--;
    break;
  case 1:
    m_now_j++;
    break;
  case 2:
    m_now_i++;
    break;
  case 3:
    m_now_j--;
    break;
  }
}

void Guruguru::change_direction()
{
  switch(m_direction)
  {
  case 3:
    m_direction = 0;
    break;
  default:
    m_direction++;
    break;
  }
}

bool Guruguru::check_point()
{
  int next_i = m_now_i;
  int next_j = m_now_j;
  int next_next_i = next_i;
  int next_next_j = next_j;
  switch(m_direction)
  {
  case 0:
    next_i--;
    next_next_i-=2;
    break;
  case 1:
    next_j++;
    next_next_j+=2;
    break;
  case 2:
    next_i++;
    next_next_i+=2;
    break;
  case 3:
    next_j--;
    next_next_j-=2;
    break;
  }
  if ( next_i < 0 || m_n <= next_i || next_j < 0 || m_n <= next_j )
  {
    return false;
  }
  else if ( next_next_i < 0 || m_n <= next_next_i || next_next_j < 0 || m_n <= next_next_j )
  {
    return true;
  }
  else
  {
    if ( '#' == m_guruguru[next_next_i][next_next_j] )
    {
      return false;
    }
    return true;
  }
}

void Guruguru::Show()
{
  for (int i=0; i<m_n; i++)
  {
    for (int j=0; j<m_n; j++)
    {
      cout << m_guruguru[i][j] << flush;
    }
    cout << endl;
  }
}

int main()
{
  int d;  //  データセットの個数
  cin >> d;
  for (int dataset=0; dataset<d; dataset++)
  {
    int n;  //  辺の長さ
    cin >> n;
    Guruguru guruguru(n);

    guruguru.Show();
    if (! (dataset == d-1))
    {
      cout << endl;
    }
  }
}
