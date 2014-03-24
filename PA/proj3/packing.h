#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int thisnode;
  struct node * parnode;
  struct node * lcnode;
  struct node * rcnode;
  char cutline;
  double width;
  double height;
  double xcoord;
  double ycoord;
}Tree;

Tree *Load(char * Filename);
Tree *Pack(Tree * packtree);
void preorder(Tree *packtree);
void postorder(Tree *packtree);
void inorder(Tree *packtree);


