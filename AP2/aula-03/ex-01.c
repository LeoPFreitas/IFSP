#include <stdio.h>
#include <math.h>

int main(void)
{
  // variable
  float num = 0;

  // recebe int num

  /*
    * Observação:
    * O scanf pega tudo que está no buffer e que corresponde a mascara dele.
  */
  printf("Digite o valor. Entre com 0 para finalizar: ");
  scanf("%f", &num);

  while (num != 0)
  {
    
    // opera
    printf("\nO número entrado é %f, seu quadrado é %f, seu cubo é %f e sua raiz quadrada é %f\n", num, pow(num, 2), pow(num, 3), sqrt(num));
    printf("Digite o próximo número: ");
    scanf("%f", &num);
  }
  
  return 0;
}
