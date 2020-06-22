#include <stdio.h>
#include <stdlib.h>

// prototipos
void Quick(int vetor[3], int inicio, int fim);

int main(void)
{
  // variaveis
  int vetor[3];

  for (int i = 0; i < 3; i++) {
    printf("Digite um número: ");
    scanf("%d", &vetor[i]);
  }

  printf("O vetor entrado foi %d %d %d", vetor[0], vetor[1], vetor[2]);

  // ordernar
  Quick(vetor, 0, 2);

  // printf("O vetor ordenado é %d %d %d", vetor[0], vetor[1], vetor[2]);

}

// funcs def
void Quick(int vetor[3], int inicio, int fim){
  int pivo, aux, i, j, meio;

  i = inicio; 
  j = fim;

  meio =  (int) ((i + j) / 2);
  pivo = vetor[meio];

  do
  {
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
    i = j + 1;
    j = j - 1;
  } while (j > 1);
  
  if(inicio < 1) Quick(vetor, inicio, j);
  if(i < fim) Quick(vetor, i, fim);
}