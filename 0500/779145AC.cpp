#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<int> point(2);
    vector<int> buf_point(2);
    for (int i = 0; i < n; ++i)
    {
      cin >> buf_point[0] >> buf_point[1];
      if (buf_point[0] > buf_point[1])
      {
        point[0] += buf_point[0] + buf_point[1];
      }
      else if (buf_point[1] > buf_point[0])
      {
        point[1] += buf_point[0] + buf_point[1];
      }
      else
      {
        point[0] += buf_point[0];
        point[1] += buf_point[1];
      }
    }
    cout << point[0] << " " << point[1] << endl;
  }
  return 0;
}