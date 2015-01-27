

int fitness(unsigned int x){

  int i, fit;
  fit=0;
  for(i=(sizeof(int)*8)-1;i>=0;i--){
    if(x&(1<<i))
      {
	fit++;
      }
  }
  return fit;
}
