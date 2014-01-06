#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Patient
{
  int number;
  int length;

  bool operator<( const Patient& right ) const
  {
    return length < right.length;
  }
};

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<Patient> patients;
    for (int i = 0; i < n; ++i)
    {
      int buf_num, buf_l1, buf_l2;
      cin >> buf_num >> buf_l1 >> buf_l2;
      Patient buf_patient = {buf_num, buf_l1 + buf_l2};
      patients.push_back(buf_patient);
    }

    sort(patients.begin(), patients.end() );
    cout << patients.back().number << " " << patients.back().length << endl;

  }
  return 0;
}