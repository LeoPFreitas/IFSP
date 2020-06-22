#include <stdio.h>

int main(int argc, char const *argv[])
{
  int m = 0;
  int aux = 1;

  // get values
  printf("Digite um número: ");
  scanf("%d", &m);

  // controle de linhas
  while (aux <= m)
  {
    //print
    int i = 0;
    while (i < aux)
    {
      printf("*");
      i++;
    }
    printf("\n");
    aux++;
  }

  return 0;
}
