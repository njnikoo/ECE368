#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int thisnode;
  int parnode;
  int lcnode;
  int rcnode;
  char cutline;
  double width;
  double height;
  double xcoord;
  double ycoord;
}Tree;

Tree *Load(char * Filename,int * rootnode);
void preorder(Tree* pretree,int rootnode);
void inorder(Tree* intree,int rootnode);
void postorder(Tree *posttree,int rootnode);
//Tree *Pack(Tree * packtree);

