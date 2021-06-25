#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node Node;
Node *aloca_node();
Node *NewNode(char *,int,char );
void move_up(Node *,int *,char *);
void move_down(Node *,int *,char *);
void move_left(Node *,int *,char *);
void move_right(Node *,int *,char *);
void distribution(Node *);
void starter(Node*);
void answer();
void FreeTree(Node *);
void clean();

#endif
