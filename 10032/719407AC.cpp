#include <iostream>
#include <string>
using namespace std;

int main()
{
  string command;
  char stack[1000];
  int size = 0;
  char color;
  while( cin >> command )
  {
    if ( command == "push" )
    {
      cin >> color;
      stack[size] = color;
      size++;
    }
    else if ( command == "pop" )
    {
      cout << stack[size-1] << endl;
      size--;
    }
    else if ( command == "quit" )
    {
      return 0;
    }
  }
  return 0;
}
