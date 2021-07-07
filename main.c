#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
int main(int argc, char *argv[])
{
    Node *game;
    int zero = 0;
    char initial[10] = "ABCDEFGH_\0",*aux,*aux2,inversions=0;
    strcpy(initial,argv[1]);
    printf("%s\n",initial);
    for(aux = initial; *aux != '\0'; aux++){
        if(*aux == '_'){
            break;
        };
        zero++;
    };
    for(aux = initial; *aux != '\0'; aux++){
        if(*aux == '_'){
            continue;
        }
        inversions += *aux-65;
        for(aux2 = initial; *aux2 != '\0'; aux2++){
            if(*aux2 == '_'){
                continue;
            }else if(*aux2 < *aux){
                inversions--;
            }else if(*aux2 == *aux){
                break;
            };
        };
    };
    printf("Inversions %d\n",inversions);
    if(inversions%2!=0){
        printf("Este puzzle não tem solução");
        exit(0);
    }
    game = NewNode(initial,zero,'\0');
    starter(game);
    answer();
    FreeTree(game);
    clean();
    printf("Cheguei ao fim");
    return 0;
}

/* TO DO: IF FATHER COMES FROM AN DOWN PLAY THERE'S NO NEED TO MAKE THE UP PLAY, JUST A WASTE OF TIME AND MEMORY*/
