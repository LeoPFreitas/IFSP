#include <stdio.h>

int main(int argc, char const *argv[])
{
  // inicialize
  int num = 0;

  // enter number
  printf("Digite um número: ");
  scanf("%d", &num);

  // verification
  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      return printf("O número %d não é primo.\n", num);
    }
  }

  printf("O número %d é primo.\n", num);

  return 0;
}
