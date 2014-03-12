#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <time.h>

int main(int argc,char *argv[]){
  if(argc < 2){
    printf("Need to provide file's name\n");
    return 0;
  }

  Node * lf;
  clock_t clock1 = clock();
  lf = Load_File(argv[1]);
  clock_t clock2 = clock();

  Node * shell;
  clock_t clock3 = clock();
  shell = Shell_Sort(lf);
  clock_t clock4 = clock();
  
  clock_t clock5 = clock();
  int saving = Save_File(argv[2],shell);
  clock_t clock6 = clock();

    if(saving < 0){
    printf("does not write to output\n");
    return 0;
  }

  clock_t in = clock2 - clock1;
  clock_t out = clock6 - clock5;

  clock_t sorti = clock4 - clock3;
  
  long double io = (long double)(in + out)/(long double)(CLOCKS_PER_SEC);
  long double sortingtime = (long double)(sorti)/(long double)(CLOCKS_PER_SEC);

  printf("I/O time: %Le\n",io);
  printf("Sorting time: %Le\n",sortingtime);

  return 0;  

}
