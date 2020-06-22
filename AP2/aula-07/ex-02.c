#include <stdio.h>
#include <string.h>

void isSubString(int count, char *pal1, char *pal2);

int main(int argc, char const *argv[])
{
  // params
  char pal1[50];
  char pal2[50];

  printf("Digite a primeira palavra: ");
  fgets(pal1, 50, stdin);
  pal1[strlen(pal1)-1] = 0;

  printf("Digite a segunda palavra: ");
  fgets(pal2, 50, stdin);
  pal2[strlen(pal2)-1] = 0;


  // is iqual?
  if (strlen(pal1) == strlen(pal2))
  { 
    // same size
    if (strcmp(pal1, pal2) > 0)
    {
      printf("A palavra %s tem maior comprimento que %s\n", pal1, pal2);
    } else if (strcmp(pal1, pal2) < 0)
    {
      printf("A palavra %s tem maior comprimento que %s\n", pal2, pal1);
    } else
    {
      printf("A palavra %s e %s são iguais.\n", pal2, pal1);
    }

    int count = 0;
    for (int i = 0; i < strlen(pal1); i++)
    {
      if (pal1[i] != pal2[i])
      {
        break;
      }
      count++;      
    }

    // printf("%d\n", count);
    isSubString(count, pal1, pal2);
    
    
  } else
  {
    if (strcmp(pal1, pal2) > 0)
    {
      printf("A palavra %s tem maior comprimento que %s\n", pal1, pal2);
    } else
    {
      printf("A palavra %s tem maior comprimento que %s\n", pal2, pal1);
    }

    int count = 0;
    for (int i = 0; i < strlen(pal1); i++)
    {
      if (pal1[i] != pal2[i])
      {
        break;
      }
      count++;      
    }

    // printf("%d\n", count);
    isSubString(count, pal1, pal2);

  }

  return 0;
}

void isSubString(int count, char *pal1, char *pal2){
  if (count == strlen(pal2))
  {
    printf("A palavra %s é substring de %s\n", pal2, pal1);
  }
  return;  
}