#include <iostream>
using namespace std;

class Time
{
  public:
    Time(int hour, int min, int sec);
    Time(int time);
    void Show();
    int Get_time();
    int Diff_time(Time other);

  private:
    int m_time;
};

Time::Time(int hour, int min, int sec)
{
  m_time = hour * 3600 + min * 60 + sec;
}

Time::Time(int time)
{
  m_time = time;
}

void Time::Show()
{
  int buf_time = m_time;
  int hour = buf_time / 3600;
  buf_time -= hour * 3600;
  int min = buf_time / 60;
  buf_time -= min * 60;
  int sec = buf_time;

  cout << hour << ' ' << min << ' ' << sec << endl;
}

int Time::Get_time()
{
  return m_time;
}

int Time::Diff_time(Time other)
{
  return m_time - other.Get_time();
}

int main(void)
{
  int h1, m1, s1, h2, m2, s2;
  for (int i = 0; i < 3; ++i)
  {
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    Time time1(h1, m1, s1);
    Time time2(h2, m2, s2);
    int diff = time2.Diff_time(time1);
    Time job_time(diff);

    job_time.Show();
  }
  return 0;
}
