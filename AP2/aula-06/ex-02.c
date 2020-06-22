#include <stdio.h>

int calSeconds(int h, int m, int s);
int calHour(int total);

int main(int argc, char const *argv[])
{
  // params
  int h, m, s;

  //get hour
  do
  {
    printf("Digite o valor da hora: ");
    scanf("%d", &h);
  } while (h < 0 || h > 23);

  //get min
  do
  {
    printf("Digite o valor dos minutos: ");
    scanf("%d", &m);
  } while (m < 0 || m > 59);

  //get seconds
  do
  {
    printf("Digite o valor dos minutos: ");
    scanf("%d", &s);
  } while (s < 0 || s > 59);

  printf("O horario entrado possui %d segundos\n", calSeconds(h, m, s));


  calHour(calSeconds(h, m, s));
  return 0;
}

int calSeconds(int h, int m, int s){
  return s + (m * 60) + (h * 60 * 60);
}

int calHour(int total) {
  int vetor[3];

  vetor[0] = total / 3600;
  total -= 3600 * vetor[0] ;

  vetor[1] = total / 60;
  total -= 60 * vetor[1];

  vetor[2] = total;

  printf("%d segundos equivalem a %dH:%dM:%dS\n",total, vetor[0], vetor[1], vetor[2]);
  return 0;
}