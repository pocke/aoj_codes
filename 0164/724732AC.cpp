#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int ohajiki = 32;
    int length;
    cin >> length;
    if ( length == 0 ) break;
    int* num_sequence = new int[length];
    for (int i=0; i<length; i++)
    {
      cin >> num_sequence[i];
    }

    for (int i=0,j=0; ohajiki != 0; i++)
    {
      if ( i % 2 == 0 )     //  兄
      {
        ohajiki -= ( ohajiki - 1 ) % 5;
      }
      else                  //  弟
      {
        int minus_num = num_sequence[j%length];
        ohajiki -= ( ohajiki <= minus_num ? ohajiki : minus_num );
        j++;
      }
      cout << ohajiki << endl;
    }

    delete[] num_sequence;
  }
}
