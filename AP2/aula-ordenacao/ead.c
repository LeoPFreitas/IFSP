#include "stdio.h"
#include "stdlib.h"

#define VEC_SIZE 10

// HELPERS
void *vector(int n);
void printVec(int *vec);
void *copyVector(int *vecOriginal);

// ALGO
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge_sort(int i, int j, int vec[], int aux[], int *c, int *a);
void mergeSort(int arr[]);

int main(int argc, char const *argv[])
{
  // criar vetor
  int vetor[] = {5, 6, 54, 19, 74, 90, 46, 23, 54, 32};

  printf("Iniciando ordenacao por selecao\n\n");
  printf("Vetor inicial: \n");
  printVec(vetor);
  printf("\n");

  // selecao
  selectionSort(vetor, VEC_SIZE);

  // INSERCAO
  insertionSort(vetor, VEC_SIZE);

  // MERGE SORT
  mergeSort(vetor);

  return 0;
}

// HELPERS

void *vector(int n)
{
  int *vector;
  vector = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
  {
    vector[i] = rand() % 100;
  }

  return vector;
}

void printVec(int *vec)
{
  for (int i = 0; i < VEC_SIZE; i++)
  {
    printf("%d ", vec[i]);
  }
  printf("\n");
}

void *copyVector(int *vecOriginal)
{
  int *vecNew = calloc(VEC_SIZE, sizeof(int));

  for (int i = 0; i < VEC_SIZE; i++)
  {
    vecNew[i] = vecOriginal[i];
  }

  return vecNew;
}

// SELECAO
void selectionSort(int arr[], int n)
{
  int compara = 0;
  int atribui = 0;

  // copia vetor
  int *vec = copyVector(arr);

  int i, j, min_idx, temp;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++)
  {
    compara++;
    atribui++;
    // Find the minimum element in unsorted array
    min_idx = i;

    for (j = i + 1; j < n; j++)
    {
      compara++;
      if (vec[j] < vec[min_idx])
      {
        compara++;
        atribui++;
        min_idx = j;
      }
    }

    // Swap the found minimum element with the first element
    temp = vec[min_idx];
    vec[min_idx] = vec[i];
    vec[i] = temp;
    atribui += 3;
  }

  printf("Vetor ordenado por selecao: \n");
  printVec(vec);
  printf("Numero de comparacoes: %d, numero de atribuicao: %d\n", compara, atribui);

  return;
}

// INSERCAO
void insertionSort(int arr[], int n)
{
  int compara = 0;
  int atribui = 0;

  // copia vetor
  int *vec = copyVector(arr);

  int i, key, j;
  for (i = 1; i < n; i++)
  {
    compara++;
    atribui += 2;

    key = vec[i];
    j = i - 1;

    while (j >= 0 && vec[j] > key)
    {
      compara += 2;
      atribui += 2;

      vec[j + 1] = vec[j];
      j = j - 1;
    }
    atribui++;
    vec[j + 1] = key;
  }

  printf("\nVetor ordenado por insercao: \n");
  printVec(vec);
  printf("Numero de comparacoes: %d, numero de atribuicao: %d\n", compara, atribui);
}

// MERGE SORT
void merge_sort(int i, int j, int vec[], int aux[], int *c, int *a)
{
  if (j <= i)
  {
    return;
  }
  int mid = (i + j) / 2;

  merge_sort(i, mid, vec, aux, c, a);
  merge_sort(mid + 1, j, vec, aux, c, a);

  int pointer_left = i;
  int pointer_right = mid + 1;
  int k;

  for (k = i; k <= j; k++)
  {
    (*c)++;
    if (pointer_left == mid + 1)
    {
      (*a)++;
      aux[k] = vec[pointer_right];
      pointer_right++;
    }
    else if (pointer_right == j + 1)
    {
      (*a)++;
      aux[k] = vec[pointer_left];
      pointer_left++;
    }
    else if (vec[pointer_left] < vec[pointer_right])
    {
      (*a)++;
      aux[k] = vec[pointer_left];
      pointer_left++;
    }
    else
    {
      (*a)++;
      aux[k] = vec[pointer_right];
      pointer_right++;
    }
  }

  for (k = i; k <= j; k++)
  {
    (*a)++;
    vec[k] = aux[k];
  }
}

void mergeSort(int arr[])
{
  int compara = 0;
  int *c = &compara;

  int atribui = 1;
  int *a = &atribui;

  int *vec = copyVector(arr);
  int *aux = calloc(VEC_SIZE, sizeof(int));

  merge_sort(0, VEC_SIZE - 1, vec, aux, c, a);

  printf("\nVetor ordenado por merge sort: \n");
  printVec(vec);
  printf("Numero de comparacoes: %d, numero de atribuicao: %d\n", compara, atribui);
}