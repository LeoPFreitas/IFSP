#include <stdio.h>
#include <string.h>

// prototype
int getType(void);
int getInt();

int main(int argc, char const *argv[])
{
  int type = getType();
  
  if (type == 1)
  {
    int l;
    printf("\nBoa, voce escolheu quadrado");
    printf("\nDigite o valor lado: ");
    l = getInt();
    printf("Area igual a %d \n", l*l);
  } else if (type == 2)
  {
    int l1;
    int l2;
    printf("\nBoa, voce escolheu retangulo");
    printf("\nDigite o valor lado 1: ");
    l1 = getInt();
    printf("\nDigite o valor lado 2: ");
    l2 = getInt();
    printf("Area igual a %d \n", l1*l2);
  } else if (type == 3)
  {
    int cat1;
    int cat2;
    printf("\nBoa, voce escolheu triangulo retangulo");
    printf("\nDigite o valor do cateto 1: ");
    cat1 = getInt();
    printf("\nDigite o valor cateto 2: ");
    cat2 = getInt();
    printf("Area igual a %d \n", (cat1*cat2)/2);
  } else
  {
    printf("Opcao não aceita, tente outra vez \n");
  }

  return 0;
}

int getType(void){

  int choice;

  printf("Digite o numero da figura desejada");
  printf("\n1 - Quadrado");
  printf("\n2 - Retangulo");
  printf("\n3 - Triangulo Retangulo\n");

  scanf("%d", &choice);
  printf("%d", choice);

  return choice;
}

int getInt(){
  int stop = -1;
  int i;
  do
  {
    scanf("%d", &i);
    if (i > 0)
    {
      stop = 1;
    } else
    {
      printf("\nNumero invalido, tente outra vez: ");
    }
    
  } while (stop == -1);

  return i;  
}
