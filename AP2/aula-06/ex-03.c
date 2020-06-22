#include <stdio.h>

int main(int argc, char const *argv[])
{
  // params
  int quantAlunos = 2;

  float notas1[quantAlunos];
  float notas2[quantAlunos];
  float t1, t2;

  int cimaMedia = 0;


  // get notas
  for (int i = 0; i < quantAlunos; i++)
  {
    printf("Digite a primeira nota do aluno %d: ", i);
    scanf("%f", &notas1[i]);
    printf("Digite a segunda nota do aluno %d: ", i);
    scanf("%f", &notas2[i]);

    t1 += notas1[i];
    t1 += notas2[i];    
  }

  printf("\nA media da primeira prova foi %.2f e da segunda %.2f\n", t1/quantAlunos, t2/quantAlunos);
  
  for (int i = 0; i < quantAlunos; i++)
  {
    if (notas1[i] > t1/quantAlunos && notas2[i] > t1/quantAlunos)
    {
      cimaMedia++; 
    }
    
  }

  printf("%d alunos foram melhor que a media em ambas as provas\n", cimaMedia);
  

  return 0;
}