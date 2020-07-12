#include "stdio.h"
#include "stdlib.h"

#define VEC_SIZE 10

// HELPERS
void *vector(int n);
void printVec(int *vec);
void *copyVector(int *vecOriginal);

// INSERCAO
int ordenar_insercao(int *vetor, int n);
int deslocar_subvetor(int *vetor, int primeiro, int ultimo);
int posicao_elemento(int *vetor, int ultimo, int elemento);

// SELECAO
void trocar(int *a, int *b);
int menor_elemento(int *vetor, int n, int primeiro);
int order_selecao(int *vetor, int n);

// MERGE-SORT
int intercalar(int *vetor, int ini, int meio, int fim);
void ordenar_intercalacao(int *vetor, int ini, int fim);

int main(int argc, char const *argv[])
{
  // variables
  int compara_insercao = 0;
  int compara_selecao = 0;
  int compara_merge_sort = 0;

  //
  int atribuicao_insercao = 0;
  int atribuicao_selecao = 0;
  int atribuicao_merge_sort = 0;

  // generate an random vector
  printf("Numeros aleatórios gerados: \n");
  // int *vec = vector(VEC_SIZE);
  // printVec(vec);
  // printf("\n");

  int vec[VEC_SIZE] = {10, 8, 9, 6, 1, 5, 3, 2, 4, 7};
  printVec(vec);
  printf("\n");

  // INSERCAO
  printf("Algoritmo de insercao: \n");
  int *vec1 = copyVector(vec);
  ordenar_insercao(vec1, VEC_SIZE);
  printVec(vec1);
  free(vec1);
  vec1 = NULL;
  printf("\n");

  /* ********************************* */

  // SELECAO
  printf("Algoritmo de selecao: \n");
  int *vec2 = copyVector(vec);
  order_selecao(vec2, VEC_SIZE);
  printVec(vec2);
  free(vec2);
  vec2 = NULL;
  printf("\n");

  /* ********************************* */

  // MERGE-SORT
  printf("Algoritmo de merge-sort: \n");
  int *vec3 = copyVector(vec);
  ordenar_intercalacao(vec3, 0, VEC_SIZE - 1);
  printVec(vec3);
  free(vec3);
  vec3 = NULL;
  printf("\n");
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

// INSERCAO
int posicao_elemento(int *vetor, int ultimo, int elemento)
{
  int i;
  for (i = 0; i <= ultimo && vetor[i] <= elemento; i++)
  {
  }

  return i;
}

int deslocar_subvetor(int *vetor, int primeiro, int ultimo)
{
  int i;
  for (i = ultimo; i >= primeiro; i--)
  {
    vetor[i + 1] = vetor[i];
  }
}

int ordenar_insercao(int *vetor, int n)
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

// SELECAO
void trocar(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int menor_elemento(int *vetor, int n, int primeiro)
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

int order_selecao(int *vetor, int n)
{
  int i, menor;
  for (i = 0; i < n; i++)
  {
    menor = menor_elemento(vetor, n, i);
    trocar(&vetor[i], &vetor[menor]);
  }
}

// MERGE-SORT
int intercalar(int *vetor, int ini, int meio, int fim)
{
  int auxiliar[VEC_SIZE];
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

void ordenar_intercalacao(int *vetor, int ini, int fim)
{
  int meio;
  if (ini < fim)
  {
    meio = (ini + fim) / 2;
    /// 1 parte
    ordenar_intercalacao(vetor, ini, meio);
    ordenar_intercalacao(vetor, meio + 1, fim);

    intercalar(vetor, ini, meio, fim);
  }
}
