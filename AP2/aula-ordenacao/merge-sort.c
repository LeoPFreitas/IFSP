#include "stdio.h"

#define MAX 100

int intercalar(int vetor[], int ini, int meio, int fim);
void ordenar_intercalacao(int vetor[], int ini, int fim);

int main(int argc, char const *argv[])
{

  int i;
  int vetor[] = {4, 5, 1, 0, 7, 6, 3, 2};

  ordenar_intercalacao(vetor, 0, 7);

  for (i = 0; i < 8; i++)
    printf("%d\n", vetor[i]);
}

int intercalar(int vetor[], int ini, int meio, int fim)
{
  int auxiliar[MAX];
  int i = ini, j = meio + 1, k = 0;

  // intercalar
  while (i <= meio && j <= fim)
  {
    if (vetor[i] <= vetor[j])
    {
      auxiliar[k++] = vetor[i++];
    }
    else
    {
      auxiliar[k++] = vetor[j++];
    }
  }

  // copia resto de cada subvetor
  while (i <= meio)
    auxiliar[k++] = vetor[i++];
  while (j <= fim)
    auxiliar[k++] = vetor[j++];

  // copia de auxiliar para vetor
  for (i = ini, k = 0; i <= fim; i++, k++)
  {
    vetor[i] = auxiliar[k];
  }
}

void ordenar_intercalacao(int vetor[], int ini, int fim)
{
  int meio;
  if (ini < fim)
  {
    meio = (ini + fim) / 2;
    ordenar_intercalacao(vetor, ini, meio);
    ordenar_intercalacao(vetor, meio + 1, fim);
    intercalar(vetor, ini, meio, fim);
  }
}
