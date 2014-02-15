#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


long *Load_File(char * Filename,int * Size)
{
  FILE * fptr = fopen(Filename,"r");
  if(fptr == NULL){
      printf("Did not load File!\n");
      return 0;
  }
  int call;
  call = fscanf(fptr,"%d",Size);
  if(call == 1){
  //first line is total # of elements in file store into size
  long * Array = malloc((*Size) * sizeof(long)); //not sure if this is correct or not 
  
  if(Array == NULL){
    printf("No Memeory left!\n"); 
    return 0;
  }
  int store;
  int i;
  for(i = 0;i < (*Size);i++){
    store = fscanf(fptr,"%ld",&(Array[i]));//stores numbers into val
    if(store == 1){

    }
    else{
      return NULL;
    }
  }


  fclose(fptr);
  return(Array);
  }

  else{
    return NULL;
  }
}

int Save_File(char * Filename,long * Array,int Size)
{
  FILE * fptr = fopen(Filename,"wb");
  int count;
  
  if(fptr == NULL){
    printf("Error opening the file!\n");
    return EXIT_FAILURE;
  }
  fprintf(fptr,"%d\n",Size);
  for(count = 0;count < Size;count++){
    fprintf(fptr,"%ld\n",Array[count]);
  }

  fclose(fptr);
  return(Size);
  
  


}
void Shell_Insertion_Sort(long * Array,int Size,double *N_Comp,double *N_Move)
{
  int k,p,gap,seq_count,i,j;
  long temp;
  k = 1;
  p = 0;
  while(k < Size){
    k = k * 3;
    p = p+ 1;
  }
  k = k / 3;
  p = p - 1;
  while(p >= 0){
    gap = k;
    seq_count = p;
    do{
      for(j = gap;j < Size;j++){
	temp = Array[j];
	i = j;
	while(i >= gap && Array[i - gap] > temp){
	  Array[i] = Array[i - gap];
	  i = i - gap;
	}
	Array[i] = temp;
      }
      gap = (gap / 3) * 2;
      seq_count = seq_count - 1;
      
    }while(seq_count >= 0);
    k = k / 3;
    p = p - 1;
  }
}



void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
  int k,p,gap,seq_count,i,j;
  long temp;
  k = 1;
  p = 0;
  while(k < Size){
    k = k * 3;
    p = p+ 1;
  }
  k = k / 3;
  p = p - 1;
  while(p >= 0){
    gap = k;
    seq_count = p;
    do{
      for(j = 0;j < Size;j++){
	int indexmin = j;
	for(i = j;i < Size;i++){
	  if(Array[indexmin] > Array[i]){
	    indexmin = i;
	  }
	}
	temp = Array[j];
	Array[j] = Array[indexmin];
	Array[indexmin] = temp;
      }
      gap = (gap / 3) * 2;
      seq_count = seq_count - 1;
    }while(seq_count >= 0);
    k = k / 3;
    p = p - 1;
  
  }

}

int Print_Seq(char * Filename,int Size)
{


}



