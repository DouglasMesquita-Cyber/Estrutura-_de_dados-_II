#include <stdio.h>
#include <stdlib.h>

typedef struct arvgen {            // define o tipo da arvore 
    char info;                    //tipo de dado
    struct arvgen *prim; // aponta pro primerio
    struct arvgen *prox;       // aponta p proximo
} ArvGen;   // fechou o bloco da struct


ArvGen* copia(ArvGen *a) // funcao que copia uma arvora e recebe um ponteiro para arvore orignal
{
    ArvGen *nova; // declara novo ponterio chamado nova 

    if (a == NULL) // se A for vazio retorna NULL 
        return NULL;

    nova = malloc(sizeof(ArvGen)); // criando espaço na memoria para um novo nó

    nova->info = a->info;   // copia o valor de info original para o atual
    nova->prim = copia(a->prim); // copia o primeiro filho do no original para o novo nó
    nova->prox = copia(a->prox);  // pega o proximo irmao do no original para o novo nó 

    return nova; // retorna o ponteiro para nova arvore
}


int igual(ArvGen *a, ArvGen *b) // recebe arvore A e arvore b
{
    if (a == NULL && b == NULL)  // se arvore A e B "ao mesmo tempo" estiver vazia vai retornar 1
        return 1;

    if (a == NULL || b == NULL) // se apenas uma estiver vazia vai retornar 0
        return 0;

    if (a->info != b->info) // se as info forem diferentes retorna 0
        return 0;

    if (igual(a->prim, b->prim) == 0)  // se os primerios filhos A,B forem diferentes retorna 0 
        return 0;

    if (igual(a->prox, b->prox) == 0) // se oproximos irmao de A,B forem diferentes retorne 0
        return 0;

    return 1; // retorna as arvores iguas 
}


int main() // ponto de entrada do programa 
{
    return 0; // finaliza o programa 
}