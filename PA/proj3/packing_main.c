#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "packing.h"


int main(int argc,char *argv[]){
  if(argc< 2){
    printf("Need to provide file's name\n");
    return 0;
  }

  
  Head * binfile;
  Tree * node;
  Tree * array;
  
  binfile = Load(argv[1]);
  node = binfile -> treehead;
  packhelp(binfile -> treehead);
  array = binfile -> arrhead;
  

  printf("Preorder: ");
  preorder(node);
  printf("\n\n");
  printf("Inorder: ");
  inorder(node);
  printf("\n\n");
  printf("Postorder: ");
  postorder(node);
  printf("\n\n");

  //printf("%e\n",binfile[binfile[root].rcnode].width);
  //getdim(binfile,root);
  printf("Width:  %le\n",node -> width);
  printf("Height:   %le\n\n",node -> height);
  printf("X-coordinate: %le\n",array[binfile -> blocks - 1].xcoord);
  printf("Y-coordinate: %le\n\n",array[binfile -> blocks - 1].ycoord);
  
  return(0);

}
