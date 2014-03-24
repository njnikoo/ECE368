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

Tree *Load(char * Filename);
//Tree *Pack(Tree * packtree);
void preorder(int rootnode,Tree * packtree);
//void postorder(Tree *packtree);
//void inorder(Tree *packtree);


