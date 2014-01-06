#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string line;
  getline(cin, line);

  for (int i = 0, size = line.size(); i < size; i++)
  {
    if ('A' <= line[i] && line[i] <= 'C')
    {
      cout << (char)(line[i] + 23);
    }
    else
    {
      cout << (char)(line[i] - 3);
    }
  }
  cout << endl;
  return 0;
}
