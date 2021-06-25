
#include "tree.h"
#include "queue.h"


struct _Node{
    Node *st,*nd,*rd,*th;
    short int blank;
    char move[10];
    char p;
};

static char solution[10] = "ABCD EFGH\0";
Queue *stack;

Node *aloca_node(){
    return (Node* )malloc(sizeof(Node));
}

void starter(Node *play){
    stack = QueueNew();
    InsertLast(stack,play);
}

Node *NewNode(char move_trial[10],int zero,char past){

    Node *nodo;
    nodo =  aloca_node();
    nodo->blank = zero;
    nodo->move[0] = '\0';
    strcpy(nodo->move, move_trial);
    nodo->p = past;
    nodo->st = NULL;
    nodo->nd = NULL;
    nodo->rd = NULL;
    nodo->th = NULL;
    return nodo;

}

void move_up(Node *play,int *cenas,char aux2[10]){
    char aux;
    if(play->blank < 3 || play->p == 'D'){
        aux2[0] = '\0';
    }else if( play->blank >= 3){
        *cenas  = play->blank-3;
        aux = (play->move)[*cenas];
        strcpy(aux2,play->move);
        aux2[play->blank] = aux;
        aux2[*cenas] = ' ';
    }

}
void move_down(Node *play,int *cenas,char aux2[10]){
    char aux;
    if(play->blank >= 6 || play->p == 'U'){
        aux2[0] = '\0';
    }else if( play->blank >= 0){
        *cenas  = play->blank+3;
        aux = play->move[*cenas];
        strcpy(aux2,play->move);
        aux2[play->blank] = aux;
        aux2[*cenas] = ' ';
    }

}
void move_left(Node *play,int *cenas,char aux2[10]){
    char aux;
    if(play->blank == 0 || play->blank == 3 || play->blank == 6 || play->p == 'D' ){
        aux2[0] = '\0';
    }else{
        *cenas  = play->blank-1;
        aux = play->move[*cenas];
        strcpy(aux2,play->move);
        aux2[play->blank] = aux;
        aux2[*cenas] = ' ';
    }
}
void move_right(Node *play,int *cenas,char aux2[10]){
    char aux;
    if(play->blank == 2 || play->blank == 5 || play->blank == 8 || play->p == 'L'){
        aux2[0] = '\0';
    }else{
        *cenas  = play->blank+1;
        aux = play->move[*cenas];
        strcpy(aux2,play->move);
        aux2[play->blank] = aux;
        aux2[*cenas] = ' ';
    }

}

void distribution(Node *play){
    int empty = 0;
    char aux[10];
    aux[0] = '\0';
    move_right(play,&empty,aux);

    if(aux[0] != '\0'){
        play->st = NewNode(aux,empty,'R');
        InsertLast(stack,play->st);
    }
    aux[0] = '\0';
    move_left(play,&empty,aux);

    if(aux[0] != '\0'){
        play->nd = NewNode(aux,empty,'L');
        InsertLast(stack,play->nd);
    }
    aux[0] = '\0';
    move_up(play,&empty,aux);

    if(aux[0] != '\0'){
        play->rd = NewNode(aux,empty,'U');
        InsertLast(stack,play->rd);
    }
    aux[0] = '\0';
    move_down(play,&empty,aux);
    if(aux[0] != '\0'){
        play->th = NewNode(aux,empty,'D');
        InsertLast(stack,play->th);
    }

}

void answer(){
    Node *aux;
    while(stack != NULL){
        aux = GetFirst(stack);
        printf("%s\n",aux->move);
        if(aux != NULL){
            if(strcmp(aux->move,solution) == 0){
                return;
            }else{
                distribution(aux);
            }
        }
    }


}
void clean(){
    clean_queue(stack);
}
void FreeTree(Node * root){
  if (root != NULL) {
    FreeTree(root->st);
    FreeTree(root->nd);
    FreeTree(root->rd);
    FreeTree(root->th);
    free(root);
  }
}
