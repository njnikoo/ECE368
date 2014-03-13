#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "packing.h"


int main(int argc,char *argv[]){
  if(argc< 2){
    printf("Need to provide file's name\n");
    return 0;
  }

  Tree * binfile = Load(argv[1]);
 
  

}
