#include<stdlib.h>

int mutate(unsigned int x, double rate);
int showbits(unsigned int x);

int crossover(unsigned int x, unsigned int y){

  unsigned int z, x1, x2, y1, y2;
  int r;

  r=1+rand()%30;

  x1 = x >> r;
  x2 = x1 << r;

  y1 = y << (32-r);
  y2 = y1 >> (32-r);

  z = x2|y2;
  z=mutate(z,0.1);
  return z;


}
