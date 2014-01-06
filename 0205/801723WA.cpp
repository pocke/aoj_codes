#include<iostream>
#include<vector>
using namespace std;

bool isDraw(const vector<int>& hands)
{
  int h = hands[0];
  bool f1 = true;
  bool f2;
  vector<bool> hs(3, false);
  for (int i = 1, size = hands.size(); i < size; ++i)
  {
    if ( h != hands[i] ) f1 = false;
    h = hands[i];
    hs[h - 1] = true;
  }
  f2 = hs[0] and hs[1] and hs[2];
  return f1 or f2;
}

vector<int> setAns(const vector<int>& hands, int n)
{
  vector<int> result(5);
  for(int i = 0; i < 5; i++)
  {
    if(hands[i] == n)
    {
      result[i] = 1;
    }
    else
    {
      result[i] = 2;
    }
  }
  return result;
}

vector<int> winLose(const vector<int>& hands)
{
  vector<bool> hs(3, false);
  for (auto h : hands)
  {
    hs[h - 1] = true;
  }
  if (hs[0] and hs[1])
  {
    return setAns(hands, 1);
  }
  else if(hs[1] and hs[2])
  {
    return setAns(hands, 2);
  }
  else
  {
    return setAns(hands, 3);
  }
}

int main(void)
{
  while(true){
    vector<int> hands(5);
    for (auto& h : hands)
    {
      cin >> h;
    }
    if (cin.eof() ) break;
  
    if (isDraw(hands) )
    {
      for (int i = 0; i < 5; i++)
      {
        cout << 3 << endl;
      }
    }
    else
    {
      for (auto n : winLose(hands) )
      {
        cout << n << endl;
      }
    }
  }
}