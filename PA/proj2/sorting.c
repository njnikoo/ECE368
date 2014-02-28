#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

Node * Create(long val){ // this is create a new node and return
  Node * created = malloc(sizeof(Node));
  created -> value = val;
  created -> next = NULL;
  return(created);
}

void Insert(Node * inserts,long val1){ // this is used to call in loadfile to intialize the node at start of the file
  Node * presnode = Create(val1);
  presnode -> next = inserts -> next;
  inserts -> next = presnode;
  return;

}

Node * Load_File(char * Filename){
  FILE * fptr = fopen(Filename,"r"); //opens file in read only mode
  if(fptr == NULL){ // checks to see if NULL
    printf("Did not load the File!\n");
    return NULL;
  }
  
  long vals;
  int counter = 0;
  Node * dummys = malloc(sizeof(Node));
  dummys -> next = NULL;
  while(fscanf(fptr,"%li\n",&vals) != -1){ // load values line by line while it is not -1 
    Insert(dummys,vals);
    counter += 1;
  }
 
  dummys -> value = counter;
  fclose(fptr);  // closes file pointer
  return(dummys); //the list of integers

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

Node * Trav(Node * dummy, int length){
  Node * head;
  int i = 0;
  head = dummy -> next;
  while(i < length){
    head = head -> next;
    i++;
  }

  return(head);
  

}

Node *Shell_Sort(Node *list){
  int k,p,gap,seq_count,i,j;
  Node * getsize;
  long temp;
  int size;
  size = list -> value;
  k = 1;
  p = 0;

  while(k < size){
    k = k * 3;
    p = p + 1;    
  }
  k = k / 3;
  p = p - 1;
  while(p >= 0){
    gap = k;
    seq_count = p;
    do{
      //gap = 1;
      for(j = gap;j < size;j++){
	getsize = Trav(list,j);
	//printf("%li\n", getsize->value);
	temp = getsize -> value;
       	i = j;
	while((i >= gap) && ((Trav(list,i - gap)) -> value) > temp){
	  getsize = Trav(list,i);
	  getsize -> value = ((Trav(list,i - gap)) -> value);
	  i = i - gap;
	}
	getsize = Trav(list,i);
	getsize -> value = temp;
      }

      gap = (gap / 3) * 2;
      seq_count = seq_count - 1;
     
    }while(seq_count >= 0);
    k = k / 3;
    p = p - 1;
  }


  return(list);
}


