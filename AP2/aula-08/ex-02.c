#include <stdio.h>
#include <stdlib.h>

float **matAloc();
float **desalocarMatriz(float **v);

int main(int argc, char const *argv[])
{
  // nomeia matriz a ser alocada
  float **mat;
  float **soma;
  
  mat = matAloc();
  soma = matAloc();

  // seed
  for (int linha = 0; linha < 4; linha++)
  {
    for (int coluna = 0; coluna < 3; coluna++)
    {
      printf("Digite o valor da linha %d coluna %d: ", linha, coluna);
      scanf("%f", &mat[linha][coluna]);
    }
  }

  // printar
  for (int linha = 0; linha < 4; linha++)
  {
    for (int coluna = 0; coluna < 3; coluna++)
    {
      printf("%.2f ", mat[linha][coluna]);
    }
    printf("\n");
  }
  
  desalocarMatriz(mat);
  

  return 0;
}

float **matAloc(){
  
  // ponteiro para a matriz
  float **v; 
  
  // aloca linha
  v = (float**)malloc(4*sizeof(float*));

  // aloca coluna
  for (int i = 0; i < 4; i++)
  {
    v[i] = (float*)malloc(3*sizeof(float));
  }

  return (v); 

}

float **desalocarMatriz(float **v){
  int i;

  if (v == NULL)
  {
    return NULL;
  }

  for (i = 0; i < 4; i++)
  {
    // libera as linhas da matriz
    free(v[i]);
  }

  // libera as colunas
  free(v); 
  
}