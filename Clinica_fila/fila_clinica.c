#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct do Paciente
struct Paciente {
    char nome[50];
    int idade;
    int eh_prioritario; // 1 se for idoso (>= 60), 0 se for normal
};

// Struct do No da lista encadeada
struct Node {
    struct Paciente dados;
    struct Node* proximo;
};

// Ponteiros globais para o inicio e o fim da fila
struct Node* inicio = NULL;
struct Node* fim = NULL;

// Funcao para adicionar paciente
void adicionar(char nome[], int idade) {
    struct Node* novo = (struct Node*) malloc(sizeof(struct Node));
    strcpy(novo->dados.nome, nome);
    novo->dados.idade = idade;
    novo->dados.eh_prioritario = (idade >= 60);
    novo->proximo = NULL;

    // Se a fila estiver vazia
    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    }
    // Se for prioritario, fura a fila e entra no inicio
    else if (novo->dados.eh_prioritario) {
        novo->proximo = inicio;
        inicio = novo;
    }
    // Se for normal, entra no fim
    else {
        fim->proximo = novo;
        fim = novo;
    }
    
    printf("Paciente %s adicionado com sucesso.\n", nome);
}

// Funcao para atender o primeiro da fila
void atender() {
    if (inicio == NULL) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    struct Node* temp = inicio;
    
    printf("\nAtendendo o paciente: %s\n", temp->dados.nome);

    inicio = inicio->proximo;

    if (inicio == NULL) {
        fim = NULL;
    }

    free(temp);
}

// Funcao para listar a fila
void listar() {
    printf("\n--- FILA DE ESPERA ---\n");
    struct Node* atual = inicio;
    
    if (atual == NULL) {
        printf("Nenhum paciente na fila.\n");
        printf("----------------------\n");
        return;
    }

    int pos = 1;
    while (atual != NULL) {
        if (atual->dados.eh_prioritario) {
            printf("%d. %s (%d anos) - PRIORITARIO\n", pos, atual->dados.nome, atual->dados.idade);
        } else {
            printf("%d. %s (%d anos) - Normal\n", pos, atual->dados.nome, atual->dados.idade);
        }
        atual = atual->proximo;
        pos++;
    }
    printf("----------------------\n");
}

int main() {
    adicionar("Joao", 30);
    adicionar("Maria", 25);
    adicionar("Vovo Ana", 72);
    adicionar("Pedro", 40);

    listar();

    atender();
    listar();

    return 0;
}