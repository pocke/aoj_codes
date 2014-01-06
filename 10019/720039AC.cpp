#include <iostream>
#include <string>
using namespace std;

int main()
{
  string dataset;
  while (true)
  {
    getline(cin, dataset);
    if ( dataset == "0" ) return 0;
    int sum = 0;
    for (int i=0, size=dataset.size(); i<size; i++)
    {
      sum += dataset[i] - 48;
    }
    cout << sum << endl;
  }
}
