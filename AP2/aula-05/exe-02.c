#include <stdio.h>

int main(int argc, char const *argv[])
{
  int num = 2;
  // declare mat
  int matM[num][num];
  int matN[num][num];
  int mult[num][num];

  // get matM
  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j < num; j++)
    {
      printf("Digite o valor da linha %d coluna %d: ", i+1, j+1);
      scanf("%d", &matM[i][j]);
    }
    
  }

  printf("\nSua matriz foi guardada!\nBora pra próxima\n\n");

  // get matN
  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j < num; j++)
    {
      printf("Digite o valor da linha %d coluna %d: ", i+1, j+1);
      scanf("%d", &matN[i][j]);
    }
    
  }

  printf("\nA matriz multiplicação é: \n\n");

  // cal mut
  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j < num; j++)
    {
    int soma = 0;
    for (int k = 0; k < num; k++)
    {
      soma += matM[i][k] * matN[k][j];
    }
    mult[i][j] = soma;
    printf("%d\t", soma);
    }
    printf("\n");
  }
  
  return 0;
}
