#include "stdlib.h"
#include "stdio.h"

void trocar(int *a, int *b);
int menor_elemento(int vetor[], int n, int primeiro);
int order_selecao(int vetor[], int n);

int main(int argc, char const *argv[])
{

  int vetor[] = {5, 6, 54, 19, 74, 90, 46, 23, 54, 32, 64};

  printf("Ordenando por selecao: \n");

  order_selecao(vetor, sizeof(vetor) / sizeof(int));

  for (int i = 0; i < sizeof(vetor) / sizeof(int); i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  printf("=============================================\n");
  return 0;
}

// trocar elementos de posicao
void trocar(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

// menor elemento da lista negra
int menor_elemento(int vetor[], int n, int primeiro)
{
  int i, menor = primeiro;

  for (i = primeiro + 1; i < n; i++)
  {
    if (vetor[i] < vetor[menor])
    {
      menor = i;
    }
  }
  return menor;
}

// ordena por selecao
int order_selecao(int vetor[], int n)
{
  int i, menor;
  for (i = 0; i < n; i++)
  {
    menor = menor_elemento(vetor, n, i);
    trocar(&vetor[i], &vetor[menor]);
  }
}

//