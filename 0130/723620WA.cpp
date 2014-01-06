#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  char cars[53];
  for (int dataset =0; dataset<n; dataset++)
  {
    int now_car = 26;
    int first_car = 26;
    int end_car = 26;
    bool flag = true;
    char op;
    while(flag)
    {
      char car;
      cin >> car;
      if ( car == '-' || car == '<' )
      {
        op = car;
      }
      else 
      {
        cars[now_car] = car;
        cin >> op;
      }
      if ( cin.eof() )
      {
        break;
      }
      switch (op)
      {
      case '<':     //  前方への移動
        now_car--;
        if ( now_car < first_car )
        {
          first_car = now_car;
        }
        cin >> op;    //  矢印をひとつ捨てる
        break;
      case '-':
        now_car++;
        if ( end_car < now_car )
        {
          end_car = now_car;
        }
        cin >> op;    //  矢印をひとつ捨てる
        break;
      default:
        flag = false;
        break;
      } //switch(op)
    } //while(flag)

    for (int i=first_car; i<=end_car; i++)
    {
      cout << cars[i] << flush;
    }
    cout << endl;
    cars[26] = op;
  } //for
}
