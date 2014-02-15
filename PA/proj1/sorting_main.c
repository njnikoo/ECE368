#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main(int argc,char *argv[])
{
  if(argc < 2){
    printf("Need to provide file's name.\n");
    return 0;
  }

  long * Array;
  int Size;
  Array = Load_File(argv[2],&Size);

  if(Array == NULL)
    {
      return 1;
    }

  double comp;
  double  move;

  Shell_Insertion_Sort(Array,Size,&comp,&move);

  int sfile;
  sfile = Save_File(argv[4],Array,Size);
  
  printf("%d\n",sfile);
  

  

  return 0;
 


}
