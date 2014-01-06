#include <iostream>
using namespace std;

class Seats
{
  public:
    Seats(int height, int width);
    ~Seats();

  public:
    void Order(int col_row, int ij, int order);
    int Stand_num();

  private:
    void Row_order(int i, int order);
    void Col_order(int j, int order);
    void Sit(int i, int j);
    void Stand(int i, int j);

  private:
    bool** m_seats;
    int m_height;
    int m_width;
};

Seats::Seats(int height, int width)
{
  m_height = height;
  m_width = width;
  m_seats = new bool*[height];
  for (int i = 0; i < height; ++i)
  {
    m_seats[i] = new bool[width];
  }

  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      m_seats[i][j] = false;
    }
  }
}

Seats::~Seats()
{
  for (int i = 0; i < m_height; ++i)
  {
    delete[] m_seats[i];
  }
  delete[] m_seats;
}

inline void Seats::Order(int col_row, int ij, int order)
{
  if (col_row == 0)
  {
    Row_order(ij, order);
  }
  else
  {
    Col_order(ij, order);
  }
}

void Seats::Row_order(int i, int order)
{
  for (int j = 0; j < m_width; ++j)
  {
    order == 0 ? Sit(i, j) : Stand(i, j);
  }
}

void Seats::Col_order(int j, int order)
{
  for (int i = 0; i < m_height; ++i)
  {
    order == 0 ? Sit(i, j) : Stand(i, j);
  }
}

inline void Seats::Sit(int i, int j)
{
  m_seats[i][j] = false;
}

inline void Seats::Stand(int i, int j)
{
  m_seats[i][j] = true;
}

int Seats::Stand_num()
{
  int result = 0;
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      result += m_seats[i][j] ? 1 : 0;
    }
  }
  return result;
}

int main(void)
{
  int height, width, order_num;
  while (true)
  {
    cin >> height >> width >> order_num;
    if (height == 0 && width == 0) break;
    Seats seats(height, width);
    int i, j, order;
    for (int num = 0; num < order_num; ++num)
    {
      cin >> i >> j >> order;
      seats.Order(i, j, order);
    }
    cout << seats.Stand_num() << endl;
  }
  return 0;
}