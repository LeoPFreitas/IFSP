#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{

  float **mat;
  float n, m;

  printf("Digite o numéro de linhas: ");
  scanf("%f", &m);

  printf("Digite o numéro de colunas: ");
  scanf("%f", &n);

  // verificar parametro
  if (n < 0 || m < 0)
  {
    printf("Dimensão inválida");
  }

  // alocar linha e verificar
  mat = calloc(m, sizeof(float *));
  if (mat == NULL)
  {
    printf("Memória insuficiente");
    exit(1);
  }

  // alocar coluna
  for (int i = 0; i < m; i++)
  {
    mat[i] = (float *)calloc(n, sizeof(float));
    if (mat[i] == NULL)
    {
      printf("Memória insuficiente");
      exit(1);
    }
  }

  // valores
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Insira o valor da linha %d coluna %d: ", i, j);
      scanf("%f", &mat[i][j]);
    }
  }

  // printar matriz
  printf("\n\n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%.2f ", mat[i][j]);
    }
    printf("\n");
  }

  // desalocar
  int aux;
  for (int i = 0; i < m; i++)
  {
    free(mat[i]);
  }

  free(mat);

  return 0;
}
