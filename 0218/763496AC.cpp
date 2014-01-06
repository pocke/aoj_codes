#include <iostream>
using namespace std;

int main(void)
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;

    for (int i = 0; i < n; ++i)
    {
      int math, englith, japanese;
      cin >> math >> englith >> japanese;

      if (math == 100 or englith == 100 or japanese == 100
          or 180 <= math + englith
          or 240 <= math + englith + japanese)
      {
        cout << 'A' << endl;
      }
      else if (210 <= math + englith + japanese
               or (150 <= math + englith + japanese 
                   and ( 80 <= math or 80 <= englith )
                  )
              )
      {
        cout << 'B' << endl;
      }
      else
      {
        cout << 'C' << endl;
      }
    }
  }
  return 0;
}
