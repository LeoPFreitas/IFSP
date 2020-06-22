#include <stdio.h>
#include <math.h>

int main(void)
{
  // variables
  int num = 0;

  // input
  printf("Digite um número inteiro: ");
  scanf("%d", &num);

  // compare
  if (num > 0)
  {
    printf("O número %d é maior que zero. \n", num);
  } else if (num == 0)
  {
    printf("O número %d é igual a zero. \n", num);
  } else
  {
    printf("O número %d é menor que zero. \n", num);
  }
  
  return 0;
}
