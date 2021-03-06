#include<stdlib.h>

int mutate(unsigned int x, double mutate_rate);

int crossover(unsigned int x, unsigned int y, double cross_rate, double mutate_rate){

  unsigned int z, x1, x2, y1, y2;
  int r;
  double s;

  s=drand48();

  if(s>cross_rate){
    return x;
  }
  else{

    r=1+rand()%30;

    x1 = x >> r;
    x2 = x1 << r;
    
    y1 = y << (32-r);
    y2 = y1 >> (32-r);

    z = x2|y2;
    z=mutate(z,mutate_rate);
    return z;
  }
}
