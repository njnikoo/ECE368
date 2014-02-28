#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

long *Load_File(char * Filename,int * Size)
{
  FILE * fptr = fopen(Filename,"r");
  if(fptr == NULL){
      printf("Did not load File!\n");
      return NULL;
  }
  int call;
  call = fscanf(fptr,"%d",Size);
  if(call == 1){
  //first line is total # of elements in file store into size
  long * Array = malloc((*Size) * sizeof(long)); //not sure if this is correct or not 
  
  if(Array == NULL){
    printf("No Memeory left!\n"); 
    return NULL;
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


  fclose(fptr);//closes file pointer 
  return(Array); // returns the array 
  }

  else{
    return NULL; //if fails returns NULL
  }
}

int Save_File(char * Filename,long * Array,int Size)
{
  FILE * fptr = fopen(Filename,"wb");//opens file but not read only
  int count;
  
  if(fptr == NULL){
    printf("Error opening the file!\n"); // if NULL prints error message
    return 0;
  }
  fprintf(fptr,"%d\n",Size); 
  for(count = 0;count < Size;count++){//prints the integers line by line to file
    fprintf(fptr,"%ld\n",Array[count]);
  }

  fclose(fptr); // closes file pointer
  return(Size); 
  
  


}
void Shell_Insertion_Sort(long * Array,int Size,double *N_Comp,double *N_Move)
{
  int k,p,gap,seq_count,i,j;
  long temp;
  k = 1;
  p = 0;
  while(k < Size){ // generates sequence
    k = k * 3;
    p = p+ 1;
  }
  k = k / 3; //divides by 3 in order to get correct sequence
  p = p - 1; // same but subtracts by one 
  while(p >= 0){
    gap = k;
    seq_count = p;
    do{
      for(j = gap;j < Size;j++){
	temp = Array[j];
	i = j;
	while(i >= gap && Array[i - gap] > temp){ //insertion sort 
	  Array[i] = Array[i - gap];
	  i = i - gap;
	  *N_Comp += 1;
	}
	Array[i] = temp;
	*N_Move += 1;
      }
      gap = (gap / 3) * 2; //needed to move right to left top to bottom
      seq_count = seq_count - 1; 
      
    }while(seq_count >= 0);
    k = k / 3; // goes to next row and goes thorugh loop again 
    p = p - 1;
    
  }
}



void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
  int k,p,gap,seq_count,i,j;
  long temp;
  k = 1;
  p = 0;
  while(k < Size){//generates sequence
    k = k * 3;
    p = p+ 1;
  }
  k = k / 3;
  p = p - 1;
  while(p >= 0){//shell sort
    gap = k;
    seq_count = p;
    do{
      for(j = 0;j < Size;j++){
	 int indexmin = j;
	*N_Comp += 1;
	for(i = j;i < Size;i++){ //selection sort instead of insertion
	  if(Array[indexmin] > Array[i]){
	    indexmin = i;
	    *N_Comp += 1;
	  }
	}
	if(j != indexmin){
	temp = Array[j];
	Array[j] = Array[indexmin];
	Array[indexmin] = temp;
	*N_Move += 3;
	}
	 }
      gap = (gap / 3) * 2;
      seq_count = seq_count - 1;
    }while(seq_count >= 0); //needed to go to next row and continue
    k = k / 3;
    p = p - 1;
  
  }

}

int Print_Seq(char * Filename,int Size)
{
  FILE * fptr = fopen(Filename,"wb");
  int a,h,j,k,p,gap,seqsize,prins;
  int i = 0;
  k = 1;
  p = 0;
  while(k < Size){//generates sequence
    k = k * 3;
    p = p+ 1;
  }
  k = k / 3;
  p = p - 1;
  seqsize = ((p + 1) * (p + 2)) / 2; //gets the size of the sequence
  //prins = fprintf(fptr,"%d",Size);
  prins = fprintf(fptr,"%d\n",seqsize);
  gap = 1;
  for(h = 0;h < p;h++){//to go left to right top to bottom 
    i++;
    gap = gap * 2; // mutiply by two to go down tree
    j = gap;
    prins = fprintf(fptr,"%d\n",gap);
    for(a = 1;a < i + 1;a++){
      j = (j * 3) / 2;//needed to go left to right
      prins = fprintf(fptr,"%d\n",j);
    }
  }

  fclose(fptr);
  return(prins);

}




