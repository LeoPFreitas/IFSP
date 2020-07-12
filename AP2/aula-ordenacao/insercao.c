#include "stdio.h"
#include "stdlib.h"

int ordenar_insercao(int vetor[], int n);
int deslocar_subvetor(int vetor[], int primeiro, int ultimo);
int posicao_elemento(int vetor[], int ultimo, int elemento);
void insertionSort(int arr[], int n);

int main(int argc, char const *argv[])
{

  int vetor[] = {10, 8, 9, 6, 1, 5, 3, 2, 4, 7};

  printf("Ordenando por insercao: \n");

  // ordenar_insercao(vetor, sizeof(vetor) / sizeof(int));

  insertionSort(vetor, 10);

  for (int i = 0; i < sizeof(vetor) / sizeof(int); i++)
  {
    printf("%d ", vetor[i]);
  }

  printf("\n");
  printf("=============================================\n");
  return 0;
}

// procura a posicao de insercao do elmento na lista verde
int posicao_elemento(int vetor[], int ultimo, int elemento)
{
  int i;
  for (i = 0; i <= ultimo && vetor[i] <= elemento; i++)
  {
  }

  return i;
}

//
int deslocar_subvetor(int vetor[], int primeiro, int ultimo)
{
  int i;
  for (i = ultimo; i >= primeiro; i--)
  {
    vetor[i + 1] = vetor[i];
  }
}

//
int ordenar_insercao(int vetor[], int n)
{
  int i, posicao;
  int elemento;

  for (i = 1; i < n; i++)
  {
    elemento = vetor[i];
    posicao = posicao_elemento(vetor, i - 1, elemento);
    deslocar_subvetor(vetor, posicao, i - 1);
    vetor[posicao] = elemento;
  }
}

void insertionSort(int arr[], int n)
{
  int i, key, j;
  int comp = 0;
  int atri = 0;

  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      comp += 1;
      atri += 1;
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
    atri += 1;
  }

  printf("atribuicao: %d comparacao: %d\n\n", atri, comp);
}