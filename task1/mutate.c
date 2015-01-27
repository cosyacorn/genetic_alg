#include<stdlib.h>

int mutate(unsigned int x, double prob){

  double r;
  int s;
//unsigned int t;
  r=drand48();
  s=rand()%32;

  if(r<prob){
    //t=1<<s;
    //showbits(t);
    x^=(1<<s);
  }
  return x;
}
