#include <stdio.h>
#include <stdlib.h>

int main(void){
  // declarar variáveis
  int num = 0;

  // receber número
  printf("Digite um número inteiro: ");
  scanf("%d", &num);

  // ver se é >= 0
  if (num <= 0)
  {
    printf("O número é inválido");
    return 0;
  }
  
  // disposição dos normais
  // if ((num % 2) == 1)
  // {
  //   printf("O número %d é par.", num);
  // } else {
  //   printf("O número %d é impar.", num);
  // }

  // disposição ternária - pipi grande
  num % 2 == 1 ? printf("O número %d é impar.", num) : printf("O número %d é par.", num);

  return 0;
}