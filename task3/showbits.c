#include<stdio.h>
#include<stdlib.h>

void showbits(unsigned int x){
  int i;
  for(i=(sizeof(int)*8)-1; i>=0; i--)
    (x&(1<<i))?putchar('1'):putchar('0');
  printf("\n");
}
