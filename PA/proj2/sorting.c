#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

Node * Create(long val){
  Node * created;
  created -> value = val;
  created -> next = NULL;
  return(created);
}

Node * Load_File(char * Filename){
  FILE * fptr = fopen(Filename,"r");
  if(fptr == NULL){
    printf("Did not load the File!\n");
    return NULL;
  }
  
  long vals;
  Node * integers = Create(&vals);
  int call = fscanf(fptr,"%d\n",vals);
  if(call == 1){
    Node * linklist = malloc((*Node) * sizeof(Node));
  }
  if(linklist == NULL){
    printf("No Memory left!\n");
    return NULL;
  }
  linklist -> next = integers -> val; // how to get its own value;
  while(linklist -> next != NULL){
  
  int store1 = fscanf(fptr,"%d",&linklist);

  }
  integers -> next = NULL;
  fclose(fptr);
  return(linklist);

}

int Save_File(char * Filename,Node * list)
{
  int count = 0;
  FILE * outputfile = fopen(Filename,"w");
  list = list -> next;
  while(list != NULL){
    fprintf(outputfile,"%li\n",list -> value);
    count += 1;
    list = list -> next;
  }
  fclose(outputfile);
  return(count);

}
