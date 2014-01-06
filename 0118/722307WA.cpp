#include <iostream>
using namespace std;

class Orchard
{
public:
  Orchard(int height, int width);
  ~Orchard();
  char CheckFruit(int h_now, int w_now);
  void rmFruit(char fruit, int h_now, int w_now);
private:
  char **m_orchard;
  int m_height;
  int m_width;
};

Orchard::Orchard(int height, int width)
{
  m_height = height;
  m_width = width;
  m_orchard = new char*[m_height];
  for (int i=0; i<m_height; i++)
  {
    m_orchard[i] = new char[m_width];
  }
  for (int i=0; i<m_height; i++)
  {
    for (int j=0; j<m_width; j++)
    {
      cin >> m_orchard[i][j];
    }
  }
}

Orchard::~Orchard()
{
  for (int i=0; i<m_height; i++)
  {
    delete[] m_orchard[i];
  }
  delete[] m_orchard;
}

char Orchard::CheckFruit(int h_now, int w_now)
{
  return m_orchard[h_now][w_now];
}

void Orchard::rmFruit( char fruit, int h_now, int w_now)
{
  if (! ((0 <= h_now && h_now < m_height) && (0 <= w_now && w_now < m_width)) )
  {
    return;
  }
  if ( fruit == CheckFruit(h_now, w_now) )
  {
    m_orchard[h_now][w_now] = 'x';
    rmFruit( fruit, h_now-1, w_now);
    rmFruit( fruit, h_now+1, w_now);
    rmFruit( fruit, h_now, w_now-1);
    rmFruit( fruit, h_now, w_now+1);
  }
}

int main()
{
  while (true)
  {
    int height,width;
    cin >> height >> width;
    if ( height == 0 && width == 0 ) break;
    Orchard orc(height, width);

    int count;
    for (int i=0; i<height; i++)    //メイン処理
    {
      for (int j=0; j<width; j++)
      {
        char fruit = orc.CheckFruit(i, j);
        if ( fruit == 'x' ) continue;
        count++;
        orc.rmFruit( fruit, i, j);
      }
    }
    cout << count << endl;

  }
}
