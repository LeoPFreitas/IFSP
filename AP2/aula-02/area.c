#include <stdio.h>
#include <math.h>

int main(void){

  // declara variáveis
  int R;
  float Perm, Area, PI;

  PI = 3,141559;

  // Recebe o raio
  printf("Entre com o valor do raio: ");
  scanf("%d", &R);

  // Calcula
  Perm = 2 * PI * R;
  Area = PI * pow(R, 2);
  
  // Dispa
  printf("Perimetro: %.2f\n", Perm);
  printf("Area: %.2f\n", Area);
}