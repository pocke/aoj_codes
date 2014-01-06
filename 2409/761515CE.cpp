#include <iostream>
#include <algorithm>
using namespace std;

struct Prof
{
  int start;
  int end;
};

class Profs
{
  public:
    Profs(int size);
    ~Profs();
    void Sort();
    Prof& operator[](int i);
    int strong_prof(int a, int b);

  private:
    int m_size;
    Prof* m_profs;
};

Profs::Profs(int size)
{
  m_size = size;
  m_profs = new Prof[m_size];

  for (int i = 0; i < m_size; ++i)
  {
    cin >> m_profs[i].start >> m_profs[i].end;
  }
}

Profs::~Profs()
{
  delete[] m_profs;
}

void Profs::Sort()
{
  stable_sort(m_profs, m_profs + m_size,
      [](const Prof& x, const Prof& y){ return x.start < y.start; } );
  //stable_sort(m_profs, m_profs + m_size,
  //    [](const Prof& x, const Prof& y){ return x.end < y.end; } );
}

inline Prof& Profs::operator[](int i)
{
  return m_profs[i];
}

int Profs::strong_prof(int a, int b)
{
  int start;
  for (start = 0; m_profs[start].start <= a; ++start)
  {
    //  空
  }
  int max = 0;
  int max_i = -1;
  for (int i = start; a < m_profs[i].start and m_profs[i].start <= b; ++i)
  {
    if (m_profs[i].end > max and m_profs[i].end > b)
    {
      max = m_profs[i].end;
      max_i = i;
    }
  }
  return max_i;
}

int main(void)
{
  int room_num, prof_num;
  cin >> room_num >> prof_num;
  Profs profs(prof_num);
  profs.Sort();

  int a = 0;
  int b = 1;
  int prof_sub;
  for (int i = 1;; ++i)
  {
    prof_sub = profs.strong_prof(a, b);
    if ( prof_sub == -1 )
    {
      cout << "Impossible" << endl;
      break;
    }
    else if (profs[prof_sub].end == room_num)
    {
      cout << i << endl;
      break;
    }

    a = profs[prof_sub].start;
    b = profs[prof_sub].end;
  }
  return 0;
}
