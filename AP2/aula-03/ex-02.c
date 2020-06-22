#include <stdio.h>

int main(void)
{
  // declare number
  int num = 0;
  int fat = 1;

  // receber valor
  printf("Digite o numero: ");
  scanf("%d", &num);

  // fatorial
  for (int i = 1; i <= num ; i++)
  {
    fat = fat * i;
  }

  printf("%d\n", fat);
  
  return 0;
}
