#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <time.h>

int main(int argc,char *argv[])
{
  if(argc < 2){
    printf("Need to provide file's name.\n");
    return 0;
  }
  
  long * Array;
  int Size;
  clock_t clock1 = clock();
  Array = Load_File(argv[2],&Size);
  clock_t clock2 = clock();
 
  if(Array == NULL)
    {
      return 0;
    }
  double comp;
  double move;

  clock_t clock7 = 0;
  clock_t clock8 = 0;
  if(*argv[1] == 'i'){
    clock7 = clock();
    Shell_Insertion_Sort(Array,Size,&comp,&move);
    clock8 = clock();
     
  }
 
  clock_t clock9 = 0;
  clock_t clock10 = 0;
  if(*argv[1] == 's'){
    clock9 = clock();
    Shell_Selection_Sort(Array,Size,&comp,&move);
    clock10 = clock();
    

  }

  clock_t clock3 = clock();
  Save_File(argv[4],Array,Size);
  clock_t clock4 = clock();
  
  clock_t clock5 = clock();
  Print_Seq(argv[3],Size);
  clock_t clock6 = clock();

  clock_t in = clock2 - clock1;
  clock_t out = clock4 - clock3;
  clock_t seq = clock6 - clock5;

  long double t = (long double)(in + out + seq)/(long double)(CLOCKS_PER_SEC);
  
  clock_t sortingi = clock8 - clock7;
  clock_t sortings = clock10 - clock9;

  long double finalsort = (long double)(sortingi + sortings)/(long double)(CLOCKS_PER_SEC);
  

  printf("Number of comparisons: %Le\n",(long double)comp);
  printf("Number of moves: %Le\n",(long double)move);
  printf("I/O time: %Le\n",t);
  printf("Sorting time: %Le\n",finalsort);
  
  free(Array);
  
  return 0;
 
}
