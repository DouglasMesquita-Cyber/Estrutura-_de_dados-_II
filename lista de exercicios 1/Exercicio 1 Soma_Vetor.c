#include <stdio.h>

int main() {
    // Declarando o vetor e as variáveis para soma e média
    int numeros[10];
    int soma = 0;
    float media = 0.0;

    // Pedindo os números para o usuário
    printf("Digite 10 numeros inteiros:\n");
    
    // Loop para ler os 10 valores e guardar no vetor
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        esmo para aproveit
        // Acumulando os valores...
        soma += numeros[i];
    }

    // Calculando a média
    media = (float)soma / 10;

    // Exibindo os resultados na tela
    printf("\n--- RESULTADOS ---\n");
    
    // Mostrando todos os números salvos no array
    printf("Numeros digitados: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Mostrando a soma e a média final
    printf("Soma dos elementos: %d\n", soma);
    printf("Media dos valores: %.2f\n", media);

    return 0;
}