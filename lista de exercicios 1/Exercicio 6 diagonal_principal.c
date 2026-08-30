#include <stdio.h>

int main() {
    int matriz[4][4];
    int somaDiagonal = 0;

    // Lendo os valores da matriz 4x4
    printf("Digite os valores para a matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Mostrando a matriz completa bonitinha
    printf("\n--- MATRIZ COMPLETA ---\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
    }

    // A diagonal principal rola quando a linha é igual à coluna (i == j)
    printf("\nDiagonal principal: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", matriz[i][i]);
        
        // Acumulando a soma dos elementos da diagonal
        somaDiagonal += matriz[i][i];
    }
    printf("\n");

    // Mostrando a soma final (dá 34 com o exemplo padrão)
    printf("Soma: %d\n", somaDiagonal);

    return 0;
}