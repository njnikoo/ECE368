#include <stdio.h>
#include <stdlib.h>
#include "packing.h"

Tree * Load(char * Filename){
  FILE * fptr = fopen(Filename,"r");
  if(fptr == NULL){
    printf("Did not load the File!\n");
    return NULL;
  }
  int call;
  int n;
  int reading;
  call = fscanf(fptr,"%d",&n);
  printf("%d\n",call);
  call = fscanf(fptr,"%d",&reading);
  printf("%d\n",call);
  Tree * bintree = malloc((reading) * sizeof(Tree));
  int i;
  int store;
  int cutstore;
  //char wh;
  int dim;
  int rootnode;
  for(i = 0;i < n;i++){
    store = fscanf(fptr,"%d",&(bintree[i].thisnode));
    printf("%d\n",store);
    //the I need to figure out way to go right and down..
    store = fscanf(fptr,"%d",&(bintree[i].parnode));
    if(bintree[i].parnode == -1){
      rootnode = bintree[i].thisnode;
      printf("%d\n",rootnode);
    }
    printf("%d\n",store);//then assign parent nodes
    store = fscanf(fptr,"%d",&(bintree[i].lcnode));
    printf("%d\n",store);
    store = fscanf(fptr,"%d",&(bintree[i].rcnode));
    printf("%d\n",store);
    cutstore = fscanf(fptr,"%c",&(bintree[i].cutline));
    printf("%d\n",cutstore);
    dim = fscanf(fptr,"%lf",&(bintree[i].width));
    printf("%d\n",dim);
    dim = fscanf(fptr,"%lf",&(bintree[i].height));
    //printf("%le\n",dim);
  }

  for(i = n;i < reading;i++){
    store = fscanf(fptr,"%d",&(bintree[i].thisnode));
    //printf("%d\n",store);
    store = fscanf(fptr,"%d",&(bintree[i].parnode));
     if(bintree[i].parnode == -1){
      rootnode = bintree[i].thisnode;
    }
    //printf("%d\n",store);
    store = fscanf(fptr,"%d",&(bintree[i].lcnode));
    //printf("%d\n",store);
    store = fscanf(fptr,"%d",&(bintree[i].rcnode));
    //printf("%d\n",store);
    cutstore = fscanf(fptr,"%c",&(bintree[i].cutline));
    // printf("%c\n",cutstore);
    //wh = fscanf(fptr,"%c",&bintree[i].width);
    //wh = fscanf(fptr,"%c",&bintree[i].height);
   

  }
  
 
  fclose(fptr);
  return bintree;

}


/*Tree * Pack(Tree * packtree){
  preorder(packtree);
  inorder(packtree);
  postorder(packtree);
  
 

}
*/

void preorder(int rootnode,Tree * packtree){
  if(rootnode != -1){
    printf("%d",packtree[rootnode-1].thisnode);
    preorder(packtree[rootnode - 1].lcnode);
    preorder(packtree[rootnode - 1].rcnode);
  }

}

/*void postorder(Tree * packtree){
  if(packtree != NULL){
    postorder(packtree -> lcnode);
    postorder(packtree -> rcnode);
    printf("%d",packtree -> current);
    
  }

}

void inorder(Tree *packtree){
  if(packtree != NULL){
    inorder(packtree -> lcnode);
    printf("%d",packtree -> current);
    inorder(packtree -> rcnode); 

  }

}
*/
