#include<stdlib.h>

int *fitness(int pop_size, unsigned int *pop, int num_games)
{

  int i, j, k, fit, last_two_results, history, opp_hist, *fitness;
  int A_decision, B_decision, outcome;
 
  fitness=malloc(pop_size*sizeof(int));

  //reset all pop member's fitness to 0
  for(i=0;i<pop_size;i++){
    fitness[i]=0;
  }


  //set up 'round robin' type loop
  for(i=0;i<pop_size;i++){
    for(j=i+1;j<pop_size;j++){

      //setting a random initial history between two players
      last_two_results=rand()%16;
      history=last_two_results;

      for(k=0;k<num_games;k++){

	A_decision=pop[i]&(1<<history);

	opp_hist=((history&8)>>1)+((history&4)<<1)+((history&2)>>1)+((history&1)<<1);
	B_decision=pop[j]&(1<<opp_hist);


      }
    }
  }
  return fitness;
}
