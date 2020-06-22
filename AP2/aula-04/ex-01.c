#include <stdio.h>
// #include <string.h>

int main(void)
{

  // [pessoa][nome, sobrenome][tamanho]
  char primeiroNome[50];
  char segundoNome[50];
  char nomes[10][2][150];
  

  // recebe os nomes
  for (int cont = 0; cont < 10; cont++)
  {
    printf("Digite primeiro nome: ");
    scanf("%[^\n]s", nomes[cont][0]);

    // clear bufer
    // int c;
    // while ((c = getchar()) != '\n' && c != EOF) { }  

    // clear bufer
    setbuf(stdin, NULL);

    printf("Digite segundo nome: ");
    scanf("%[^\n]", nomes[cont][1]);
    
    setbuf(stdin, NULL);
    
    printf("\n");
  }

  // printar
  printf("A lista de nomes formatada é: ");
  for (int cont = 0; cont < 10; cont++)
  {
    printf("%s, %s\n", nomes[cont][0], nomes[cont][1]);
  }
  return 0;
}
