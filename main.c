#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
int main(int argc, char *argv[])
{
    Node *game;
    int zero = 0;
    char initial[10] = "ABCDE FGH\0",*aux,*aux2,inversions=0;
    for(aux = initial; *aux != '\0'; aux++){
        if(*aux == ' '){
            break;
        };
        zero++;
    };
     for(aux = initial; *aux != '\0'; aux++){
        if(*aux == ' '){
            continue;
        }
        inversions += *aux-65;
        for(aux2 = initial; *aux2 != '\0'; aux2++){
            printf("Estou a comparar %c ----- inversoes %d --------- %d\n",*aux,inversions,*aux); 
            if(*aux2 < *aux){
                /*printf("%c %c\n",*aux2,*aux);*/
                inversions--;
            };
            if(*aux2 == *aux){
                break;
            };
        };
    };
    game = NewNode(initial,zero,'\0');
    starter(game);
    answer();
    FreeTree(game);
    clean();
    printf("Cheguei ao fim");
    return 0;
}

/* TO DO: IF FATHER COMES FROM AN DOWN PLAY THERE'S NO NEED TO MAKE THE UP PLAY, JUST A WASTE OF TIME AND MEMORY*/
