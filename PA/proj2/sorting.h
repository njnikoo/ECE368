#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  long value;
  struct node *next;
}Node;

typedef struct list{
  Node * node;
  struct list * next;
  struct list * prev;
}List;

Node * Load_File(char *Filename);
int Save_File(char *Filename,Node *list);
Node * Create(long val);
void Insert(Node * inserts,long val1);
Node *Shell_Sort(Node *list);
Node * Trav(Node * dummy,int length);
