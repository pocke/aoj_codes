#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  unsigned int st = 0;
  for (int i = 0; i < n; i++)
  {
    char parentheses;
    int p_num;
    cin >> parentheses >> p_num;
    if (parentheses == '(')
    {
      st += p_num;
    }
    else
    {
      if (st < p_num)
      {
        cout << "NO" << endl;
      }
      else
      {
        st -= p_num;
      }
    }
  }
  if (st == 0)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
