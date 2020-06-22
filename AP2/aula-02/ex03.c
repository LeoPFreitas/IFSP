#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // declarar variaveis
  int dia = 0;
  char dias [7] [20] = {"domingo", "segunda-feira", "terça-feira", "quarta-feira", "quinta-feira", "sexta-feira", "sabado"};

  // recebendo dia
  printf("Digite o dia da semana: ");
  scanf("%d", &dia);

  dia = dia - 1;

  if (dia == 0 || dia == 6) {
    printf("O dia %s não é dia útil\n", dias[dia]);
  } else {
    printf("O dia %s é dia útil\n", dias[dia]);
  }

  return 0;
}
