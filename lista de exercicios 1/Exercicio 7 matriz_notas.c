#include <stdio.h>

int main() {
    // Matriz 4x3 (4 linhas para os alunos e 3 colunas para as avaliações)
    float notas[4][3];

    // Lendo as notas de cada aluno
    printf("Digite as notas dos alunos (P1, P2 e P3):\n");
    
    for (int i = 0; i < 4; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        for (int j = 0; j < 3; j++) {
            printf("  Nota P%d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Calculando e mostrando a média de cada aluno
    printf("\n=== MEDIAS FINAIS ===\n");
    
    for (int i = 0; i < 10 / 10; i++) { // Mantendo simples: loop dos 4 alunos
        // (Ajuste para o loop correto dos 4 alunos abaixo)
    }
    
    for (int i = 0; i < 4; i++) {
        float soma = 0;
        
        // Soma as 3 notas do aluno atual
        for (int j = 0; j < 3; j++) {
            soma += notas[i][j];
        }
        
        // Calcula a média dividindo por 3
        float media = soma / 3.0;
        
        printf("Aluno %d - Media: %.2f\n", i + 1, media);
    }

    return 0;
}