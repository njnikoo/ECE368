#include <stdio.h>
#include <stdlib.h>
#include "packing.h"

Tree * Load(char * Filename,int *rootnode){
  FILE * fptr = fopen(Filename,"r");
  if(fptr == NULL){
    printf("Did not load the File!\n");
    return NULL;
  }
  int call;
  int n;
  int reading;
  if((call = fscanf(fptr,"%d",&n)) != 1){
    exit(1);
  }
  if((call = fscanf(fptr,"%d",&reading)) != 1){
    exit(1);
  }
  Tree * bintree = malloc((reading) * sizeof(Tree));
  int i;
  int store;
  int cutstore;
  int dim;
  for(i = 0;i < n;i++){
    if((store = fscanf(fptr,"%d",&(bintree[i].thisnode))) != 1){
      exit(1);
    }
    //the I need to figure out way to go right and down..
    if((store = fscanf(fptr,"%d",&(bintree[i].parnode))) != 1){
      exit(1);
    }
    if(bintree[i].parnode == -1){
      *rootnode = bintree[i].thisnode;
      //printf("%d\n",*rootnode);
    }
    if((store = fscanf(fptr,"%d",&(bintree[i].lcnode))) != 1){
      exit(1);
    }
    if((store = fscanf(fptr,"%d",&(bintree[i].rcnode))) != 1){
	exit(1);
      }
   if((cutstore = fscanf(fptr," %c",&(bintree[i].cutline))) != 1){
	exit(1);
      }
   if((dim = fscanf(fptr,"%lf",&(bintree[i].width))) != 1 ){
	exit(1);
      }
   if((dim = fscanf(fptr,"%lf",&(bintree[i].height))) != 1){
	exit(1);
      }
  }
  char dummy;
  for(i = n;i < reading;i++){
    if((store = fscanf(fptr,"%d",&(bintree[i].thisnode))) != 1){
      exit(1);
    }
    if((store = fscanf(fptr,"%d",&(bintree[i].parnode))) != 1 ){
	exit(1);
      }
    if(bintree[i].parnode == -1){
       *rootnode = bintree[i].thisnode;
    }
    if((store = fscanf(fptr,"%d",&(bintree[i].lcnode))) != 1){
	exit(1);
      }
    if((store = fscanf(fptr,"%d",&(bintree[i].rcnode))) != 1){
	exit(1);
      }
    if(( cutstore = fscanf(fptr," %c",&(bintree[i].cutline))) != 1){
	exit(1);
      }
    if((dim = fscanf(fptr," %c",&dummy)) != 1){
      exit(1);
    }
    if((dim = fscanf(fptr," %c",&dummy)) != 1){
      exit(1);
    }
 
  }
  
 
  fclose(fptr);
  return bintree;

}


void preorder(Tree *pretree,int rootnode){
  if(rootnode != -1){
    printf("%d ",pretree[rootnode-1].thisnode);
    preorder(pretree,pretree[rootnode-1].lcnode);
    preorder(pretree,pretree[rootnode - 1].rcnode);
  }

}

void inorder(Tree * intree,int rootnode ){
  if(rootnode != -1){
    inorder(intree,intree[rootnode - 1].lcnode);
    printf("%d ",intree[rootnode - 1].thisnode);
    inorder(intree,intree[rootnode - 1].rcnode); 

  }
}

void postorder(Tree * posttree,int rootnode){
  if(rootnode != -1){
    postorder(posttree,posttree[rootnode - 1].lcnode);
    postorder(posttree,posttree[rootnode - 1].rcnode);
    printf("%d ",posttree[rootnode - 1].thisnode);
    
  }

}

