#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "packing.h"


int main(int argc,char *argv[]){
  if(argc< 2){
    printf("Need to provide file's name\n");
    return 0;
  }

  int root;
  Tree * binfile = Load(argv[1],&root);
  printf("Preorder: ");
  preorder(binfile,root);
  printf("\n\n");
  printf("Inorder: ");
  inorder(binfile,root);
  printf("\n\n");
  printf("Postorder: ");
  postorder(binfile,root);
  printf("\n\n");
 
  
  return(0);

}
