
#include "Item.h"
#include "tree.h"
#include "queue.h"

struct _element {
  Item this;
  int level;
  struct _element *next;
};

struct _queue {
  Element *first;
  Element *last;
};



Queue *NewQueue()
{
  Queue * q = malloc(sizeof(Queue));
  q->first = NULL;
  q->last = NULL;
  return q;
}



void InsertLast(Queue* queue, Item this)
{
  Element *elem;

  if ((queue == NULL )|| (this == NULL))
     return;

  elem = malloc(sizeof(Element));
  elem->this = this;
  elem->next = NULL;
  if (queue == NULL)
     return;

  if (queue->last != NULL){

     queue->last->next = elem;
  }

  queue->last = elem;
  if (queue->first == NULL)
     queue->first = elem;

  return;
}




Item GetFirst(Queue* queue)
{
  Element *q = queue->first;
  Item this = (Item) NULL;

  if (queue->first != NULL) {
     queue->first = queue->first->next;
     if(queue->first == NULL){
        queue->last = NULL;
     }
     this = q->this;
     free(q);
  }

  return this;
}
void clean_queue(Queue* queue){
    Element *q,*aux=queue->first;

    while(aux != NULL){
        q = aux;
        aux = aux->next;
        free(q);

    }
    free(queue);
}


