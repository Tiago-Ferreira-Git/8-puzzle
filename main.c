#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
int main(int argc, char *argv[])
{
    Node *game;
    int zero = 0;
    char initial[10] = "AB CDEFGH\0",*aux;
    for(aux = initial; *aux != '\0'; aux++){
        if(*aux == ' '){
            break;
        };
        zero++;
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
