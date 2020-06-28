// escreva um programa em c que solicita ao usuário um número n e entao
// le um vetor de n notas e calcula amédia aritmética

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
  int n = 0;

  // get n
  printf("Digite o número n: ");
  scanf("%d", &n);

  // alocar vetor
  float *vet;
  vet = calloc(n, sizeof(float));

  // check allocation
  if (vet == NULL)
  {
    printf("Memoria insuficiente\n");
    exit(1);
  }

  // get grades
  for (int i = 0; i < n; i++)
  {
    printf("Digite a nota %d: ", i + 1);
    scanf("%f", &vet[i]);
  }

  // calc med
  float soma = 0;
  for (int i = 0; i < n; i++)
  {
    soma += vet[i];
  }

  // free vetor
  free(vet);

  printf("A media da turma é %.2f", soma / n);

  return 0;
}