#include <iostream>
#include <string>
using namespace std;

int main()
{
  while (true)
  {
    string class_name;
    int am_num, pm_num;
    cin >> class_name >> am_num >> pm_num;
    if ( cin.eof() ) break;
    cout << class_name << ' '<< am_num+pm_num  << ' ' << 200*am_num + 300*pm_num << endl;
  }
}
