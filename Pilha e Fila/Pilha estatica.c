#include <stdio.h>
#define MAX 5 // Define a capacidade maxima do vetor 

int stack[MAX]; // chama a pilha 
int top = 0; // top indica quantos elementos existem na pilha

// Inserir (push)
void push(int value) {     
    if (top == MAX) {     // se o topo for igual a capacidade maxima 
        printf("Erro: Pilha cheia!\n");  //imprime esse erro 
    } else {
        stack[top] = value;  // caso tenha espaço, adicione no topo 
        top++;
        printf("Elemento %d inserido.\n", value); // imprime o elemento 
    }
}

// Remover (pop) 
int pop() {
    if (top == 0) {   //se quantidade de elementos na pilha ser zero
        printf("Erro: Pilha vazia!\n"); // imprima esse erro 
        return -1; // nao valida o elemento 
    } else {
        top--; //volta uma posição do top 
        int value = stack[top]; // guarda o valor na proxima posição livre 
        printf("Elemento %d removido.\n", value); // imprime os valores
        return value; // retorna o valor removido 
    }
}

// Mostrar pilha
void display() {
    if (top == 0) {
        printf("Pilha vazia.\n"); // se o topo for igual a 0 a pilha esta vazia e imprime "Pilha Vazia"
    } else {
        printf("Pilha: ");
        for (int i = 0; i < top; i++) { // percorre os elementos da pilha
            printf("%d ", stack[i]); // imprime o elemeto
        }
        printf("\n"); //pula linha
    }
}

int main() {
    push(10);  // Insere 10 -> pilha: [10]        top 1
    push(20); // Insere 20 -> pilha: [10,20]      top 2
    push(30);  // Insere 30 -> pilha: [10,20,30]  top 3
    display();  // Mostra: Pilha: 10 20 30

    pop();     // Remove o último inserido (30)   top 2
    display(); // mostra a pilha com os elementos 

    push(40);
    push(50);
    push(60);
    push(70); // quando chega aqui a pilha ja esta cheia e nao da mais para adicionar.
    display(); //imprime os elementos

    return 0; // finaliza o programa 
}