#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
  srand((unsigned int)time(NULL));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 1000; ++i)
  {
    printf("%d\n", rand() % n + 1);
  }
  return 0;
}
