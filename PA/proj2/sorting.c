#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

Node * Create(long val){
  Node * created = malloc(sizeof(Node));
  created -> value = val;
  created -> next = NULL;
  return(created);
}

Node * Insert(Node * inserts,long val1){
  Node * presnode = Create(val1);
  presnode -> next = inserts;
  return(presnode);

}

Node * Load_File(char * Filename){
  FILE * fptr = fopen(Filename,"r");
  if(fptr == NULL){
    printf("Did not load the File!\n");
    return NULL;
  }
  
  long vals;
  Node * integers = NULL;
  int call = 0;
  
  while(fscanf(fptr,"%li\n",&vals) != NULL){
    integers = Insert(integers,vals);
  }
  
  fclose(fptr);
  return(integers);

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
