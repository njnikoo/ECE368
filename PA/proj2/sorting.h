#include <stdio.h>
#include <stdlib.h>

typedef struct_node{
  long value;
  struck_node *next;
}Node;

typedef struct_list{
  Node * node;
  struct_list * next;
  struct_list * prev;
}List;

Node * Load_File(char *Filename);
int Save_File(char *Filename,Node *list);
Node *Shell_Sort(Node *list);
Node * Create(long val);
Node * Insert(Node * inserts,long val1);
