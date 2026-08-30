#include <stdio.h>

int main() {
    // Vetor para guardar os 20 números
    int numeros[20];
    int qtdPares = 0;
    int somaPares = 0;

    // Lendo os 20 números do usuário
    printf("Digite 20 numeros inteiros:\n"); //pedido p usuario digitar 
    for (int i = 0; i < 20; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Mostrando os resultados na tela
    printf("\n--- RESULTADOS ---\n");

    // Filtrando e mostrando apenas os números pares
    printf("Numeros pares encontrados: ");
    for (int i = 0; i < 20; i++) {
        // Se o resto da divisão por 2 for 0, o número é par
        if (numeros[i] % 2 == 0) {
            printf("%d ", numeros[i]);
            
            // Conta mais um para a quantidade de pares
            qtdPares++;
            
            // somando o valor par na nossa soma total
            somaPares += numeros[i];
        }
    }
    printf("\n");

    // Exibindo a quantidade e a soma dos pares
    printf("Total de numeros pares: %d\n", qtdPares);
    printf("Soma dos numeros pares: %d\n", somaPares);

    return 0;
}