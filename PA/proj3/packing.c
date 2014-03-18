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
    bintree -> parnode = fscanf(fptr,"%d",bintree[i]);  //then assign parent nodes
    bintree -> lcnode = fscnaf(fptr,"%d",bintree[i]);
    bintree -> rcnode = fscnaf(fptr,"%d",bintree[i]);//ask about -1 and NULL
    bintree -> cutline = fscanf(fptr,"%d",bintree[i]);
    if(bintree -> cutline = '-'){
      //move to next value and read width then go to height after if
    }
    bintree -> width = fscanf(fptr,"%d",bintree[i]);
    bintree -> height = fscanf(fptr,"%d",bintree[i]);
   
  }
  
  fclose(fptr);
  return bintree;

}
