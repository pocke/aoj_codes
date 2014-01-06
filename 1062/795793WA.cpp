#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Time
{
  public:
    Time(int hour, int min);
    Time(Time& prev, int min);

    int whatTimeZone() const;
    int operator-(const Time& right) const;

  private:
    bool isLunch() const;
    bool isDinner() const;
    bool isMidnight() const;

  private:
    int m_hour;
    int m_min;
};

inline Time::Time(int hour, int min) :
  m_hour(hour), m_min(min)
{
}

inline Time::Time(Time& prev, int min) :
  m_hour(prev.m_min < min ? prev.m_hour : prev.m_hour + 1), m_min(min)
{
}

int Time::whatTimeZone() const
{
  return isLunch() ? 1 : 
         isDinner() ? 2 : 
         isMidnight() ? 3 : 0;
}

int Time::operator-(const Time& right) const
{
  return m_hour == right.m_hour ? m_min - right.m_min : m_min + (m_hour - right.m_hour) * 60 - right.m_min;
}

inline bool Time::isLunch() const
{
  return 11 <= m_hour and m_hour <= 14;
}

inline bool Time::isDinner() const
{
  return 18 <= m_hour and m_hour <= 20;
}

inline bool Time::isMidnight() const
{
  return (21 <= m_hour and m_hour <= 23) or (0 <= m_hour and m_hour <= 1);
}

class Slip
{
  public:
    Slip(const Time& start_t, const Time& end_t);

    bool isOK() const;
    int whatTimeZone() const;

  private:
    Time m_start_t;
    Time m_end_t;
};

inline Slip::Slip(const Time& start_t, const Time& end_t) :
  m_start_t(start_t), m_end_t(end_t)
{
}

inline bool Slip::isOK() const
{
  return m_end_t - m_start_t <= 8;
}

inline int Slip::whatTimeZone() const
{
  return m_start_t.whatTimeZone();
}

void result(const vector<vector<int>>& time_zone, int i)
{
  static string time_zone_str[] = {"", "lunch", "dinner", "midnight"};
  cout << time_zone_str[i] << " ";
  if (time_zone[i][0] == 0)
  {
    cout << "no guest";
  }
  else
  {
    cout << time_zone[i][0] * 100 / time_zone[i][1];
  }
  cout << endl;
}

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<vector<int>> time_zone(4, vector<int>(2, 0) );

    for (int i = 0; i < n; ++i)
    {
      int h, m, m2;
      char buf_ch;
      cin >> h >> buf_ch >> m >> m2;
      Time start_t(h, m);
      Time end_t(start_t, m2);
      Slip slip(start_t, end_t);

      if (slip.isOK() )
      {
        ++time_zone[slip.whatTimeZone()][0];
      }
      ++time_zone[slip.whatTimeZone()][1];
    }

    for (int i = 1; i < 4; ++i)
    {
      result(time_zone, i);
    }
  }
  return 0;
}