void showbits(unsigned int x);

int mutate(unsigned int x, double prob){

  double r;
  int s;
//unsigned int t;
  s=rand()%32;
  r=drand48();

  if(r<prob){
    //t=1<<s;
    //showbits(t);
    x^=(1<<s);
  }
  return x;
}
