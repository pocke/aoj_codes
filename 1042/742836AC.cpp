#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string line;
  while (true)
  {
    getline(cin, line);
    if ( line == "END OF INPUT" ) break;

    int count = 0;
    for (int i = 0, size = line.size(); i < size; i++)
    {
      if (line[i] != ' ')
      {
        count++;
      }
      else
      {
        cout << count;
        count = 0;
      }
    }
    cout << count << endl;
  }
}
