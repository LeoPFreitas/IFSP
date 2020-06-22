#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  // Declare variables
  float a, b, c;
  float x1, x2;
  float delta;

  // inputs
  printf("Digite o coeficiente a de x^2: ");
  scanf("%f", &a);
  
  printf("Digite o coeficiente b de x: ");
  scanf("%f", &b);

  printf("Digite o coeficiente c: ");
  scanf("%f", &c);

  // math operations delta = b² - 4ac
  delta = (pow(b, 2) - 4*a*c);
  x1 = (-b + sqrt(delta)) / (2*a);
  x2 = (-b - sqrt(delta)) / (2*a);
  
  // condicoes

  if (delta > 0)
  {
    // 2 resposta
    printf("As raizes da equação são: %f %f", x1, x2);
  } else if (delta == 0)
  {
    printf("As raizes da equação são: %f %f", x1, x2);
  } else {
    printf("As raizes da equação não são reais.");
  }

  return 0;
}