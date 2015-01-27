#include<stdlib.h>

void showbits(unsigned int x);

int mutate(unsigned int x, double prob){

  double r;
  int s;

  s=rand()%32;
  r=drand48();

  if(r<prob){
    x^=(1<<s);
  }
  return x;
}
