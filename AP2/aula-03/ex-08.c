#include <stdio.h>

int main(int argc, char const *argv[])
{
  int n = 0;
  int ze = 110;
  int chico = 150;

  while (chico >= ze)
  {
    chico += 2;
    ze += 3;
    n++;
  }

  printf("%d %d %d\n", chico, n, ze);
  
  return 0;
}
