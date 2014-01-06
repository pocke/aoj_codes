#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  while(true)
  {
    int candy;
    cin >> candy;
    if ( cin.eof() ) break;
    int student_num = ( candy%39 == 0 )? 39 : candy%39;
    printf("3C%02d\n", student_num);
  }
}
