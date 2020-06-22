#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  // names
  int numNomes = 2;
  char names[numNomes][100];

  int firstSpace[numNomes];
  int lastSpace[numNomes];

  // get names
  for (int i = 0; i < numNomes; i++)
  {
    printf("Digite o primeiro nome: ");
    fgets(names[i], 100, stdin);

    //  get first space
    for (int j = 0; j < 100; j++)
    {
      if (names[i][j] == ' ')
      {
        firstSpace[i] = j;
        break;
      } 
    }

    //  get last space
    lastSpace[i] = firstSpace[i];
    for (int j = 0; j < 100; j++)
    {
      if (names[i][j] == ' ')
      {
        lastSpace[i] = j;
      } 
    }
  }
  
  // print
  for (int i = 0; i < numNomes; i++)
  {
    // print last name 
    for (int j = lastSpace[i]; j < strlen(names[i]); j++)
    {
      printf("%c", names[i][j]);
    }

    printf(", ");

    // print first name 
    for (int j = 0; j < firstSpace[i]; j++)
    {
      printf("%c", names[i][j]);
    }
    
  }
  return 0;
}
