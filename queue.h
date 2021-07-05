
#ifndef QUEUE
#define QUEUE

#include "Item.h"
#include <stdlib.h>

typedef struct _queue Queue;
typedef struct _element Element;


Queue *NewQueue();              
Item GetFirst(Queue*);          
void InsertLast(Queue*, Item);   
void clean_queue(Queue *);

#endif

