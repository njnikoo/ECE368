#include <stdio.h>
#include <stdlib.h>
#include "packing.h"
#include <string.h>
#include <time.h>
Head * Load(char * Filename){
  FILE * fptr = fopen(Filename,"r"); // opens the file
  if(fptr == NULL){
    printf("Did not load the File!\n");
    return NULL;
  }
  int call;
  int reading;
  int blocks;
  int nodes;
  
  call = fscanf(fptr,"%d",&blocks);//scanfs in intial data
  call = fscanf(fptr,"%d",&nodes);

  if(call){

  }
  
  Head * bintree = malloc(sizeof(Head)); //makes trees
  Tree * array = malloc(sizeof(Tree) * nodes);

  bintree -> blocks = blocks;
  bintree -> nodes = nodes;
  bintree -> arrhead = array;

  int parloc;
  int leftloc;
  int rightloc;
  int i;
  char width[20];
  char height[20];
  
  
  
  for(i = 0;i < nodes;i++){
    reading = fscanf(fptr,"%d %d %d %d %s %s %s",&(array[i].thisnode),&(parloc),&(leftloc),&(rightloc),array[i].cutline,width,height);
    if(reading){

    }

    if(leftloc == -1){
      array[i].lcnode = NULL;
    }
    else{
      array[i].lcnode = &(array[leftloc - 1]);
    }
    if(rightloc == -1){
      array[i].rcnode = NULL;
    }
    else{
      array[i].rcnode = &(array[rightloc - 1]);
    }
    if(parloc == -1){
      bintree -> treehead = &array[i];
      array[i].parnode = NULL;
    }
    else{
      array[i].parnode = &(array[parloc - 1]);
    }	
    if(strcmp(width, "-") == 0){
	  array[i].height = -1;
	  array[i].width = -1;
	}
    else{
	  sscanf(height,"%le",&(array[i].height));
	  sscanf(width,"%le",&(array[i].width));
	}
  }
  fclose(fptr);
  return bintree;

}
void preorder(Tree * pretree){ 
  if(pretree != NULL){
  printf("%d ",pretree -> thisnode);
  preorder(pretree -> lcnode);
  preorder(pretree -> rcnode);
  }
}

void inorder(Tree * intree ){
  if(intree != NULL){
    inorder(intree -> lcnode);
    printf("%d ",intree -> thisnode);
    inorder(intree -> rcnode);
  }
}

void postorder(Tree * posttree){
  if(posttree != NULL){
    postorder(posttree -> lcnode);
    postorder(posttree -> rcnode);
    printf("%d ",posttree -> thisnode);
    
  }

}

void packhelp(Tree * help){
  if(help != NULL){
    getdim(help);
    getcoord(help,0,0);
  }
}

void getdim(Tree * dimtree){ //funtion is not working but i really tried 
 //Need to start with tree and traverse
  //if root is H go to the right and go to farthest depth of tree and left node(0,0)
  //H use the max width and add the height
  //V go to the left all the way
  //V add the width and take the max heigh
  //if((dimtree[rootnode].lcnode <= 0) || (dimtree[rootnode].rcnode <= 0)){
  // return;
  //}
  if(strcmp((dimtree -> cutline), "-") == 0){
    return;
  }
  getdim(dimtree -> lcnode);
  getdim(dimtree -> rcnode);
  if((strcmp((dimtree -> cutline), "H")) == 0){
    if((dimtree -> lcnode -> width) > (dimtree -> rcnode -> width)){
      dimtree -> width = dimtree -> lcnode -> width;
    }
    else{
      dimtree -> width = dimtree -> rcnode -> width;
    }
    dimtree -> height = dimtree -> lcnode -> height + dimtree -> rcnode -> height;
  }
  if((strcmp((dimtree -> cutline), "V")) == 0){
    if((dimtree -> lcnode -> height) > (dimtree -> rcnode -> height)){
      dimtree -> height = dimtree -> lcnode -> height;
    }
    else{
      dimtree -> height = dimtree -> rcnode -> height;
    }
    dimtree -> width = dimtree -> rcnode -> width + dimtree -> lcnode -> width;
  }
}

void getcoord(Tree * coord,double x,double y){
  if(coord != NULL){
    if(strcmp((coord -> cutline), "H") == 0){
      getcoord(coord -> rcnode,x,y);
      getcoord(coord -> lcnode,x,(y + coord -> rcnode -> height));
    }
    if(strcmp((coord -> cutline), "V") == 0){
      getcoord(coord -> lcnode,x,y);
      getcoord(coord -> rcnode,(x + coord -> lcnode -> width),y);
    }
    if(strcmp((coord -> cutline), "-") == 0){
      coord -> xcoord = x;
      coord -> ycoord = y;
    }
  }
}

  
