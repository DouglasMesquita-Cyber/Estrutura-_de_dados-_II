#include <stdio.h>   // Biblioteca padrão para usar printf
#define MAX 5        // Tamanho máximo do vetor 

int data[MAX];   // Vetor que armazena os elementos
int inicio = 0;  // Índice de onde o PRÓXIMO elemento será removido
int final = 0;   // Índice de onde o PRÓXIMO elemento será inserido
int qnt = 0;     // Quantidade de elementos atualmente armazenados


// Insere um elemento no final

void enqueue(int item) {
    if (qnt == MAX) {
        // Se qnt for igual a MAX, não há espaço livre
        printf("Cheio!\n");
        return;   // Sai da função sem inserir nada
    }

    data[final] = item;          // Guarda o item na posição indicada por final
    final = (final + 1) % MAX;   // Avança final; se passar do fim do vetor, volta para 0 (circular)
    qnt++;                        // Incrementa a contagem, pois agora há mais um elemento
}


// Remove um elemento do início

int dequeue() {
    if (qnt == 0) {
        // Se qnt for 0, não há nenhum elemento para remover
        printf("Vazio!\n");
        return -1;   // Valor de erro (não representa um elemento real)
    }

    int item = data[inicio];       // Lê o item que está na posição inicio 
    inicio = (inicio + 1) % MAX;   // Avança inicio; se passar do fim do vetor, volta para 0
    qnt--;                          // Decrementa a contagem, pois um elemento saiu

    return item;   // Retorna o item removido para quem chamou a função
}


// Mostra todos os elementos, do mais antigo ao mais novo

void display() {
    printf("Dados: ");
    for (int i = 0; i < qnt; i++) {
        
        // começando em inicio e "dando a volta" no vetor se necessário
        printf("%d ", data[(inicio + i) % MAX]);
    }
    printf("\n");
}

// Função principal - onde o programa começa a executar

int main() {
    enqueue(10);   // data: [10, _, _, _, _]   inicio=0 final=1 qnt=1
    enqueue(20);   // data: [10, 20, _, _, _]  inicio=0 final=2 qnt=2
    enqueue(30);   // data: [10, 20, 30, _, _] inicio=0 final=3 qnt=3
    display();     // Dados: 10 20 30

    dequeue();     // remove 10 (o mais antigo)  inicio=1 qnt=2
    display();     // Dados: 20 30

    enqueue(40);   // data: [_, 20, 30, 40, _]  final=4 qnt=3
    enqueue(50);   // data: [_, 20, 30, 40, 50] final=0 (deu a volta!) qnt=4
    enqueue(60);   // data: [60, 20, 30, 40, 50] final=1 qnt=5 (cheio)
    display();     // Dados: 20 30 40 50 60

    return 0;   // Indica que o programa finalizou 
}