#include <stdio.h>

int main() {
    int numeros[10];

    // Lendo os 10 números do usuário
    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    // Mostrando o vetor do jeito que a gente digitou
    printf("Vetor original: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Invertendo o vetor sem criar outro: 
    // a gente só vai até a metade (5) trocando o começo com o fim
    for (int i = 0; i < 5; i++) {
        int aux = numeros[i];          // Guarda o valor atual
        numeros[i] = numeros[9 - i];   // Joga o do final pro começo
        numeros[9 - i] = aux;          // Põe o guardado lá no final
    }

    // Mostrando o vetor depois de inverter
    printf("Vetor invertido: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}