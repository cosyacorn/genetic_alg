#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

void showbits(unsigned int x);
int fitness(unsigned int y);
int *selection2(unsigned int *z, int size);
int crossover(unsigned int x, unsigned int y);



int main(int argc, char *argv[]){

  int nprocs, myid;
  int i, *fittest, pop_size, iters, temp1, temp2, pop_fitness;
  unsigned int *x;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Status status;

  srand(time(NULL));
  srand48(time(NULL));

  pop_size=1000;
  iters=10000;

  fittest=malloc(3*sizeof(int));
  x=malloc(pop_size*sizeof(unsigned int));

  for(i=0;i<pop_size;i++){
    x[i]=rand();
    //printf("%d\n", x[i]);
  }
  

  for(i=0;i<iters;i++){
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

  free(fittest);
  free(x);

  return 0;
}
