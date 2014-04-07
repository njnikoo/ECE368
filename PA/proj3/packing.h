#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int thisnode;
  struct node * parnode;
  struct node * lcnode;
  struct node * rcnode;
  char cutline[5];
  double width;
  double height;
  double xcoord;
  double ycoord;
}Tree;

typedef struct head{
  Tree * treehead;
  Tree * arrhead;
  int blocks;
  int nodes;

}Head;

Head * Load(char * Filename);
void preorder(Tree* pretree);
void inorder(Tree* intree);
void postorder(Tree *posttree);
void packhelp(Tree * help);
void getdim(Tree * dimtree);
void getcoord(Tree * coord,double x,double y);

