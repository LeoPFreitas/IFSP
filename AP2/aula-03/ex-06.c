#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  // declara variable
  int num1, num2 = 0;

  printf("Digite o primeiro inteiro: ");
  scanf("%d", &num1);
  printf("Digite o segundo interio: ");
  scanf("%d", &num2);

  while (num1 != 0 || num2 != 0)
  {
    printf("A media é: %.2f\n", (float)(num1+num2)/2);    

    printf("Digite o primeiro inteiro: ");
    scanf("%d", &num1);
    printf("Digite o segundo interio: ");
    scanf("%d", &num2);
  }

  printf("Encerrando..\n");
  return 0;
}
