
#include <stdio.h>

int isPrimo(int num){
  // verificar se é primo
  int i;
  for (i = 2; i < num; i++)
  {
    if (num % i == 0)
    { 
      return 0;
    } 
  }
  return 1;
}

int main(int argc, char const *argv[])
{
  // inicialize
  int count = 0;
  int num = 1;

  printf("Os 20 primeiro número primos são: \n");

  if (num == 1 || num == 2)
  {
    printf("%d\n", num);
    num++;
  }
  
  while (count < 18)
  {
    // verifica se é primo
    if(isPrimo(num) == 1){
      printf("%d\n", num);
      count++;
      num += 1;
    } else
    {
      num += 1;
    }
    
  }
  printf("\n");

  return 0;
}

