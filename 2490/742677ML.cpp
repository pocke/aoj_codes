#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  stack<bool> st;
  for (int i = 0; i < n; i++)
  {
    char parentheses;
    int p_num;
    cin >> parentheses >> p_num;
    if (parentheses == '(')
    {
      for (int i = 0; i < p_num; i++)
      {
        st.push(true);
      }
    }
    else
    {
      for (int i = 0; i < p_num; i++)
      {
        if (st.empty() )
        {
          cout << "NO" << endl;
          return 0;
        }
        else
        {
          st.pop();
        }
      }
    }
  }
  if (st.empty() )
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
