#include <iostream>
using namespace std;

int main(void)
{
  double weight;
  while (cin >> weight)
  {
    if (weight <= 48)
    {
      cout << "light fly";
    }
    else if (weight <= 51)
    {
      cout << "fly";
    }
    else if (weight <= 54)
    {
      cout << "bantam";
    }
    else if (weight <= 57)
    {
      cout << "feather";
    }
    else if (weight <= 60)
    {
      cout << "light";
    }
    else if (weight <= 64)
    {
      cout << "light welter";
    }
    else if (weight <= 69)
    {
      cout << "welter";
    }
    else if (weight <= 75)
    {
      cout << "light middle";
    }
    else if (weight <= 81)
    {
      cout << "middle";
    }
    else if (weight <= 91)
    {
      cout << "light heavy";
    }
    else
    {
      cout << "heavy";
    }
    cout << endl;
  }
  return 0;
}
