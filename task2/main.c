#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void showbits(unsigned int x);
int *fitness(int pop_size, unsigned int *pop, int num_games);
int *selection2(unsigned int *z, int size);
int crossover(unsigned int x, unsigned int y);
int mutate(unsigned int x, double prob);


int main(int argc, char **argv){


  int i, *fittest, pop_size, gens, iters, crate, mrate, temp1, temp2, pop_fitness, *fit;
  int sflag, gflag, iflag, cflag, mflag, opt;
  unsigned int *x;

  opterr=0;
  sflag=0;
  gflag=0;
  iflag=0;
  cflag=0;
  mflag=0;

  //FLAGS:
  //s=size of pop
  //g=number of gens
  //i=iters of pd
  //c=crossover rate
  //m=mutation rate

  while((opt=getopt(argc,argv,"s:g:i:c:m:")) !=-1){
    switch(opt){

    case 's':
      pop_size=atoi(optarg);
      sflag=1;
      break;

    case 'g':
      gens=atoi(optarg);
      gflag=1;
      break;

    case 'i':
      iters=atoi(optarg);
      iflag=1;
      break;

    case 'c':
      crate=atof(optarg);
      cflag=1;
      break;

    case 'm':
      mrate=atof(optarg);
      mflag=1;
      break;

    case '?': 
      if(optopt=='n')
	printf("Unknown option '-%c'\n", optopt);
      else
	printf("what's going on here\n");
      return 1;

    default:
      abort();


    }
  }

  if(sflag==0 || gflag==0 || iflag==0 || cflag==0 || mflag==0){
    printf("------CORRECT USAGE:------ \n%s -s <pop size> -g <num gens> -i <iters of PD> -c <cross rate> -m <mutate rate>\n", argv[0]);
  }else{

    printf("%d\n",pop_size);

    srand(time(NULL));
    srand48(time(NULL));
    
    //pop_size=10000;
    //iters=10000;
  
    fittest=malloc(3*sizeof(int));
    x=malloc(pop_size*sizeof(unsigned int));
    fit=malloc(pop_size*sizeof(int));
    


    for(i=0;i<pop_size;i++){
      x[i]=rand();
    }
  
    fit=fitness(pop_size, x, iters);
    
    for(i=0;i<pop_size;i++){
      printf("%d\n",fit[i]);
    }
    
    /*
    for(i=0;i<gens;i++){
      fittest = selection2(x, pop_size);
      //printf("fittest %d\n", fittest[0]);
      temp1=crossover(x[fittest[0]],x[fittest[1]]);
      temp2=crossover(x[fittest[1]],x[fittest[0]]);
      x[fittest[0]]=temp1;
      x[fittest[1]]=temp2;
      pop_fitness=fittest[2];
      if(i%100==0){
	printf("fitness of pop = %d; iteration %d\n", pop_fitness, i);
      }
    }
    */
    free(fittest);
    free(x);
    free(fitness);
  }
  return 0;
}
