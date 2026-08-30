#include <stdio.h>

int main() {
    int numeros[10];
    
    // Lendo os 10 números do usuário
    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // assumindo que o primeiro número é o maior e o menor de todos
    int maior = numeros[0];
    int menor = numeros[0];
    int posMaior = 0;
    int posMenor = 0;

    // Passando por todo o vetor para achar quem é maior e quem é menor
    for (int i = 1; i < 10; i++) {
        // Se amero maior, atualiza o campeão
        if (numeros[i] > maior) {
            maior = numeros[i];
            posMaior = i;
        }
        
        // achando um número menor, atualiza 
        if (numeros[i] < menor) {
            menor = numeros[i];
            posMenor = i;
        }
    }

    // Mostrando os resultados na tela
    printf("\n--- RESULTADOS ---\n");
    
    printf("Numeros digitados: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // resultado final 
    printf("Maior valor: %d (posicao %d)\n", maior, posMaior + 1);
    printf("Menor valor: %d (posicao %d)\n", menor, posMenor + 1);

    return 0;
}