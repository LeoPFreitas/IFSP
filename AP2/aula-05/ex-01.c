#include <stdio.h>

int main(int argc, char const *argv[])
{

  // declare variables
  int mat[50][50];
  int trans[50][50];
  int i, j;

  // inputs
  printf("Digite o número de linhas: ");
  scanf("%d", &i);
  printf("Digite o número de colunas: ");
  scanf("%d", &j);

  if (i > 50 || j > 50)
  {
    printf("O limite é de 50 linhas ou 50 colunas!\n");
    return 0;
  }
  

  // populate matrix
  for (int linha = 0; linha < i; linha++)
  {
    // coluna
    for (int coluna = 0; coluna < j; coluna++)
    {
      printf("Digite os valores da linha %d coluna %d: ", linha, coluna);
      scanf("%d", &mat[linha][coluna]);
      trans[coluna][linha] = mat[linha][coluna];
    }     
  }

  printf("\n\n");

  // print
  printf("Matriz entrada:\n");
  for (int linha = 0; linha < i; linha++)
  {
    for (int coluna = 0; coluna < j; coluna++)
    {
      printf("%d ", mat[linha][coluna]);
    }
    printf("\n");
  }

  printf("\n\n");
  printf("Transposta:\n");
  for (int linha = 0; linha < j; linha++)
  {
    for (int coluna = 0; coluna < i; coluna++)
    {
      printf("%d", trans[linha][coluna]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}

/*
1 2 3       1 4 7
4 5 6       2 5 8
7 8 9       3 6 9
*/