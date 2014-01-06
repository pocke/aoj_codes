#include <iostream>
#include <algorithm>
using namespace std;

class Hanafuda
{
  public:
    Hanafuda(int size);
    ~Hanafuda();
    void Shuffle(int p, int c);
    int Top();

  private:
    int* m_hanafuda;
    int m_size;
};

Hanafuda::Hanafuda(int size)
{
  m_size = size;
  m_hanafuda = new int[m_size];
  for (int i = 0; i < m_size; ++i)
  {
    m_hanafuda[i] = m_size - i;
  }
}

Hanafuda::~Hanafuda()
{
  delete[] m_hanafuda;
}

void Hanafuda::Shuffle(int p, int c)
{
  int* buf_p = new int[p-1];
  int* buf_c = new int[c];

  copy(m_hanafuda, m_hanafuda + p  - 1, buf_p);
  copy(m_hanafuda + p - 1, m_hanafuda + p - 1 + c, buf_c);
  
  copy(buf_c, buf_c + c, m_hanafuda);
  copy(buf_p, buf_p + p - 1, m_hanafuda + c);
}

inline int Hanafuda::Top()
{
  return m_hanafuda[0];
}

int main(void)
{
  while (true)
  {
    int n, r;
    cin >> n >> r;
    if ( n == 0 and r == 0 ) break;

    Hanafuda hanafuda(n);

    int p, c;
    for (int i = 0; i < r; ++i)
    {
      cin >> p >> c;
      hanafuda.Shuffle(p, c);
    }

    cout << hanafuda.Top() << endl;
  }
  return 0;
}
