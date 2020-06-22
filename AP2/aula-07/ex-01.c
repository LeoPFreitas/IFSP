#include <stdio.h>
#include <string.h>

#define clearBuffer while (getchar() != '\n');

int getTime(void);
int timebetween(int t1, int t2);
void sec2time(int t);

int main(int argc, char const *argv[])
{
  // params
  int time1 = getTime();
  int time2 = getTime(); 
  
  int t = timebetween(time1, time2);

  sec2time(t);

  return 0;
}

//  functions
int getTime(void){
  int h, m, s;

  printf("Digite a quantidade de horas: ");
  do
  {
    scanf("%d", &h);
  } while (h < 0 || h > 23);

  printf("Digite a quantidade de minutos: ");
  do
  {
    scanf("%d", &m);
  } while (m < 0 || m > 59);

  printf("Digite a quantidade de segundos: ");
  do
  {
    scanf("%d", &s);
  } while (s < 0 || s > 59);

  int time = 3600*h + 60*m + s;
  return time;
}

int timebetween(int t1, int t2){
  if (t1 >= t2)
  {
    t1 = t1 - t2;
    return t1;
  } else
  {
    t2 = t2 - t1;
    return t2;
  }
  
}

void sec2time(int t){
  int h, m, s;

  h = t / 3600;
  t -= h*3600;

  m = t / 60;
  t -= m*60;

  s = t;

  printf("Passaram-se %d:%d:%d\n", h, m, s);
  return;
}