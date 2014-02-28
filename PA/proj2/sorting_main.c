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
  lf = Load_File(argv[1]);

  Node * shell;
  shell = Shell_Sort(lf);
  
//  printf("%li\n",shell -> value);

  int saving = Save_File(argv[2],shell);
//  printf("%d\n",saving);
  if(saving < 0){
    printf("does not write to output\n");
    return 0;
  }
  return 0;  

}
