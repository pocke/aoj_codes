#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int dataset=0; dataset<n; dataset++)
  {
    int rand;
    cin >> rand;
    cout << "Case " << dataset << ':' << endl;
    for (int i=0; i<10; i++)
    {
      rand = rand*rand;
      rand = rand/100 - (rand/1000000)*10000;
      cout << rand << endl;
    }
  }
}
