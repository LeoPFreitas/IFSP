#include <stdio.h>

int main(void)
{
  // variaveis
  int a, b, c =0;

  printf("Digite um lado do triangulo: ");
  scanf("%d", &a);
  printf("Digite outro lado do triangulo: ");
  scanf("%d", &b);
  printf("Digite outro lado do triangulo: ");
  scanf("%d", &c);

  if (a == b && b == c) {
    printf("O triangulo é equilátero\n");
  } else if (a == b || b == c || a == c)
  {
    printf("O triangulo é isósceles\n");
  } else if (a != b && b != c && a != c)
  {
    printf("O triangulo é escaleno\n");
  }

  return 0;
}