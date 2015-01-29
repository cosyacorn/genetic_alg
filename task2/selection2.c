#include<stdlib.h>
#include<stdio.h>

//This function returns the two fittest (via roulette selection) members of the pop and also the total fittness of the population

int *selection2(int *fit, int size){

  int i, *fittest;
  long unsigned int total;
  double *prob, rand;

  prob=malloc(size*sizeof(double));
  fittest=malloc(3*sizeof(int));

  total=0;

  for(i=0;i<size;i++){
    total+=fit[i];
  }
  //printf("total: %d\n", total);
  fittest[2]=total; //use this to give the fitness of the population

  prob[0]=(double)fit[0]/(double)total;

  for(i=1;i<size;i++){
    prob[i]=prob[i-1]+(double)fit[i]/(double)total;
  }


  //choosing first parent//
  rand=drand48();
  
  if(rand<=prob[0]){
    fittest[0]=0;
  }else{
    for(i=1;i<size-1;i++){
      if(prob[i-1]<=rand && rand<prob[i]){
	fittest[0]=i;
	break;
      }
    }
  }

  
  //choosing second parent//

  fittest[1]=fittest[0]; //just to set up do while condition

  do{
    rand=drand48();
  
    if(rand<=prob[0]){
      fittest[1]=0;
    }else{
      for(i=1;i<size-1;i++){
	if(prob[i-1]<=rand && rand<prob[i]){
	  fittest[1]=i;
	  break;
	}
      }
    }
  }while(fittest[1]==fittest[0]);

  return fittest;
  
  free(fittest);
  free(fit);
  free(prob);

}
