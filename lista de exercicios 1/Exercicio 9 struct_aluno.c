#include <stdio.h>
#include <string.h>

// Criando a struct Aluno com os campos pedidos
struct Aluno {
    char nome[50];
    int idade;
    float nota1;
    float nota2;
    float nota3;
};

int main() {
    // Declarando o vetor para guardar 5 alunos
    struct Aluno alunos[5];
    
    // Variáveis de controle para contagens e para achar o melhor aluno
    int qtdAprovados = 0;
    int qtdReprovados = 0;
    int indiceMelhorAluno = 0;
    float maiorMedia = -1;

    printf("Cadastro de Alunos:\n");
    
    // Loop para ler os dados dos 5 alunos
    for (int i = 0; i < 5; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        
        // Lendo o nome
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        while(getchar() != '\n'); // Limpa o buffer do teclado

        // Lendo a idade
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        while(getchar() != '\n');

        // Lendo as três notas individualmente
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        while(getchar() != '\n');

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        while(getchar() != '\n');

        printf("Nota 3: ");
        scanf("%f", &alunos[i].nota3);
        // Não precisa de getchar no último campo (nota3)
    }

    // Exibindo o resultado e as médias de cada um
    printf("\n=== RESULTADOS DA TURMA ===\n");
    for (int i = 0; i < 5; i++) {
        
        // Calculando a média das 3 notas
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;

        printf("Aluno: %s | Media: %.2f - ", alunos[i].nome, media);

        // Classificando entre Aprovado e Reprovado
        if (media >= 7.0) {
            printf("Aprovado\n");
            qtdAprovados++; // Soma mais um nos aprovados
        } else {
            printf("Reprovado\n");
            qtdReprovados++; // Soma mais um nos reprovados
        }

        // Lógica para descobrir quem tirou a maior média da turma
        if (i == 0 || media > maiorMedia) {
            maiorMedia = media;
            indiceMelhorAluno = i; // Guarda a posição do aluno destaque
        }
    }

    // Informações finais exigidas pelo exercício
    printf("\n=== RESUMO GERAL ===\n");
    printf("Total de Aprovados: %d\n", qtdAprovados);
    printf("Total de Reprovados: %d\n", qtdReprovados);
    printf("Aluno com a maior media: %s (Media: %.2f)\n", alunos[indiceMelhorAluno].nome, maiorMedia);

    return 0;
}