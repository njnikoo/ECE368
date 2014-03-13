#include <stdio.h>
#include <stdlib.h>
#include "packing.h"

Tree * Load(char * Filename){
  File * fptr = fopen(Filename,"r");
  if(fptr == NULL){
    printf("Did not load the File!\n");
    return NULL;
  }
  int call;
  int reading;
  call = fscanf(fptr,"%d",&reading);
  call = fscanf(fptr,"%d",&reading);
  Tree * bintree = malloc((reading) * sizeof(Tree));
  int i;
  int store;
  for(i < 0;i < reading;i++){
    store = fscanf(fptr,"%d",bintree[i]);
    //the I need to figure out way to go right and down..
    //then assign parent node
    //if the thing int is -1 do not set left or right child if not then read into and set left and right child
    //then cutline
    //next the width and height
    //the the x and y coordinates
    //then need to start creating tree starting with 9 in terms of connecting
  }
  
  //Then close the file pointer and return the tree back. 
}
