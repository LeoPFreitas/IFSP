// Calcula e escreve o produto dos números primos entre 92 - 1478

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// prototipos
int isPrimo(int num);

int main(int argc, char const *argv[])
{
  // declare variables
  long double sum = 1;
  int num = 92;

  do
  {
    // verifica se é primo
    if (isPrimo(num) == 1)
    {
      // calcula quadrado e dispa com cast
      printf("O quadrado de %d é %d\n", num, (int)pow(num, 2));

      // multiplica
      sum *= num;
      num++;
    } else
    {
      num++;
    }

  } while (num <= 1478);

  printf("A multiplicação é %Lf\n", sum);
  
  return 0;
}

// function definition
int isPrimo(int num){
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}
