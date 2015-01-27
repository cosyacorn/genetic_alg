#include<stdlib.h>
<<<<<<< HEAD
#include<time.h>
#include<math.h>

void mutate(unsigned int x, double prob){

  double r;
  int s;
  unsigned int t, xleft, xright, y;

  srand48(time(NULL));
  srand(time(NULL));
  r=drand48();
  s=rand()%33;

  if(r<prob){
    t=(unsigned int)pow(2,s);
    showbits(t);
    showbits(x);
    //printf("%d\n", s);
    y=~x;
    xright=x<<(32-s);
    xright=xright>>(32-s);
    xleft=x>>s;
    xleft=xleft<<s;
    y=y>>(s);
    //showbits(y);
    y=y<<31;
    //showbits(y);
    y=y>>(31-s);
    //showbits(y);
    y=y+xleft+xright;
    showbits(y);
  }
=======

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
>>>>>>> 40066235a951046e931344574bac33c18f736725
}
