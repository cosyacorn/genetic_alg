#include<stdlib.h>

int *fitness(int pop_size, unsigned int *pop, int num_games)
{

  int i, j, k, last_two_results, history, opp_hist, *fitness;
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

	//opponent's history is the same as A's history but with each pair swapped
	//ie, if A stores CD then B must store DC and so on...
	opp_hist=((history&8)>>1)+((history&4)<<1)+((history&2)>>1)+((history&1)<<1);
	B_decision=pop[j]&(1<<opp_hist);

	A_decision=A_decision>>history;
	B_decision=B_decision>>opp_hist;

	if(A_decision==B_decision && A_decision==0){
	  fitness[i]+=3;
	  fitness[j]+=3;
	  outcome=0;
	}else if(A_decision<B_decision){
	  fitness[j]+=5;
	  outcome=1;
	}else if(A_decision>B_decision){
	  fitness[i]+=5;
	  outcome=2;
	}else if(A_decision==B_decision && A_decision==1){
	  fitness[i]+=1;
	  fitness[j]+=1;
	  outcome=3;
	}
	history=((history&3)<<2)+outcome;
      }
    }
  }
  return fitness;
}
