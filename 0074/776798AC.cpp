#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
  int ih, im, is;
  while (true)
  {
    cin >> ih >> im >> is;
    if (ih == -1 and im == -1 and is == -1) break;
    int time3, time;
    time3 = time = 120 * 60 - ih * 3600 - im * 60 - is;
    time3 *= 3;

    int oh = time / 3600;
    time %= 3600;
    int om = time / 60;
    time %= 60;
    int os = time;

    int o3h = time3 / 3600;
    time3 %= 3600;
    int o3m = time3 / 60;
    time3 %= 60;
    int o3s = time3;

    printf("%.2d:%.2d:%.2d\n", oh, om, os);
    printf("%.2d:%.2d:%.2d\n", o3h, o3m, o3s);
  }
  return 0;
}