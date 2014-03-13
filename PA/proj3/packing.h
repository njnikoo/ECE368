#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int thisnode;
  struct node * parnode;
  struct node * left;
  struct node * right;
  char cutline;
  double width;
  double height;
  double xcoord;
  double ycoord;
}Tree;

Tree *Load(char * Filename);


