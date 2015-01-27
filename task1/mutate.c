#include<stdlib.h>
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
}
