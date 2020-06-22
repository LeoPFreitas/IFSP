#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

  int i;
  printf("Digite o número de notas: ");
  scanf("%d", &i);

  // aloca vetor de i posicoes
  float *vet = (float *)malloc(i * sizeof(float));
  if (vet == NULL)
  {
    printf("Memoria insuficiente\n");
    exit(1);
  }

  float soma = 0;
  for (int count = 0; count < i; count++)
  {
    printf("Digite a nota: ");
    scanf("%f", &vet[count]);

    soma += vet[count];
  }

  printf("%.2f", soma / i);
  printf("\n");

  return 0;
}
