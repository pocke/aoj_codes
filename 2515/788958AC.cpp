#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time
{
  public:
    Time(int hour, int min);

  public:
    //  return min
    int operator-(const Time& right) const;

  private:
    int m_hour;
    int m_min;
};

inline Time::Time(int hour, int min) :
  m_hour(hour), m_min(min)
{
}

int Time::operator-(const Time& right) const
{
  int hour_diff = this->m_hour - right.m_hour;
  int min_diff = this->m_min - right.m_min;
  return hour_diff * 60 + min_diff;
}

struct Station
{
  Time time;
  string name;
};

struct Result
{
  int time;
  string name;
};

int main(void)
{
  int station_num, stay_min;
  cin >> station_num >> stay_min;

  Station arrival_sta = { Time(0, 0) , "" };
  Station leave_sta = { Time(0, 0) , "" };

  vector<Result> result;

  int h, m;
  char buf_ch;
  string buf_str;
  cin >> h >> buf_ch >> m >> buf_str;
  while (true)
  {
    cin >> h >> buf_ch >> m >> arrival_sta.name;
    arrival_sta.time = Time(h, m);
    cin >> h >> buf_ch >> m >> leave_sta.name;
    if (cin.eof() ) break;
    leave_sta.time = Time(h, m);

    int t;
    if ( (t = leave_sta.time - arrival_sta.time) >= stay_min)
    {
      result.push_back( {t, leave_sta.name} );
    }
  }

  cout << result.size() << endl;
  for (auto r : result)
  {
    cout << r.name << " " << r.time << endl;
  }
  return 0;
}