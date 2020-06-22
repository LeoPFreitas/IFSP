#include <stdio.h>

int main(int argc, char const *argv[])
{
  // declare variables
  float notas[22];
  float sum = 0;

  // recebe notas
  for (int i = 0; i < 22; i++)
  {
    printf("Digite uma nota: ");
    scanf("%f", &notas[i]);
    printf("\n");

    // soma
    sum += notas[i];
  }

  printf("A média da turma é: %.2f\n", (sum / 22));
  
  return 0;
}
