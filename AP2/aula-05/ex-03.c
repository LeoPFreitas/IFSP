#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define flush while (getchar() != '\n');

int main(int argc, char const *argv[])
{
  // declare variables
  int numAlunos = 2;

  // matriz de caracteres alunos
  char alunos[numAlunos][50];

  // vetor de notas
  float n1[numAlunos];
  float n2[numAlunos];

  // media
  float total = 0;
  float maioMedia = -1;
  float menorMedia = 1000;

  // count reprovados
  int repo = 0;
  int exam = 0;
  int aprov = 0;

  // receber nomes e notas
  for (int i = 0; i < numAlunos; i++)
  {
    // l e o \n 0
    printf("Digite o nome do aluno: ");
    fgets(alunos[i], 50, stdin);
    alunos[i][strlen(alunos[i]) - 1] = 0;

    /*
      * cleear buffer in case string >= 48 (0 and \n not include)
      * use conditional to avoid double \n char flow
    */
    if (strlen(alunos[i]) >= 48)
    {
      flush;
    }
    

    printf("Digite a primeira nota: ");
    scanf("%f", &n1[i]);
    flush;

    printf("Digite a segunda nota: ");
    scanf("%f", &n2[i]);
    flush;
    
    printf("\n");

    // media
    total += (n1[i]+n2[i])/2;

    // maior - menor media
    if ((n1[i]+n2[i])/2 > maioMedia)
    {
      maioMedia = (n1[i]+n2[i])/2;
    }

    if ((n1[i]+n2[i])/2 < menorMedia)
    {
      menorMedia = (n1[i]+n2[i])/2;
    }

    // final cond
    if ((n1[i]+n2[i])/2 < 5.00)
    {
      repo += 1;
    } else if ((n1[i]+n2[i])/2 >= 5.00 && (n1[i]+n2[i])/2 < 6.00)
    {
      exam += 1;
    } else if ((n1[i]+n2[i])/2 > 6.00)
    {
      aprov += 1;
    }

  }

  printf("\n");

  // apresentar dados
  for (int i = 0; i < numAlunos; i++)
  {
    printf("NOME: %s - Media: %.2f \n", alunos[i], (n1[i]+n2[i])/2);
  }

  printf("\nA media da turma eh: %.2f", total/numAlunos);
  printf("\nA maior media eh: %.2f", maioMedia);
  printf("\nA menor media eh: %.2f\n", menorMedia);

  printf("\n%d alunos foram aprovados, %d estao em exame e %d foram reprovados.\n", repo, exam, repo);
  
  
  return 0;
}
