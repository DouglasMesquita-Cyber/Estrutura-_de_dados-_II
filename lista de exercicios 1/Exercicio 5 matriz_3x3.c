#include <stdio.h>

int main() {
    // Declarando a matriz 3x3 e as variáveis de apoio
    int matriz[3][3];
    int soma = 0;
    int maior;

    // Lendo os valores da matriz (usando dois loops: um pra linha e outro pra coluna)
    printf("Digite os valores para a matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
            // Já aproveita o loop pra somar tudo
            soma += matriz[i][j];
            
            // Na primeira posição, assume que o primeiro número é o maior
            if (i == 0 && j == 0) {
                maior = matriz[i][j];
            } else if (matriz[i][j] > maior) {
                // Se achar um valor maior, atualiza
                maior = matriz[i][j];
            }
        }
    }

    // Mostrando a matriz no formato de tabela bonitinho
    printf("\n--- MATRIZ 3x3 ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d \t", matriz[i][j]);
        }
        printf("\n"); // Pula pra próxima linha na tela
    }

    // Mostrando a soma e o maior valor encontrados
    printf("\nSoma de todos os elementos: %d\n", soma);
    printf("Maior valor da matriz: %d\n", maior);

    return 0;
}