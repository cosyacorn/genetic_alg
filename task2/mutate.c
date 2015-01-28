#include<stdlib.h>

int mutate(unsigned int x, double prob){

  double r;
  int s;

  r=drand48();
  s=rand()%32;

  if(r<prob){

    x^=(1<<s);
  }
  return x;
}
