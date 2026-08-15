# Estrutura de Dados I

Código desenvolvido durante a aula de Estrutura de Dados I.

## Conteúdos utilizados

- Struct
- Vetores
- Matrizes
- Laços de repetição
- Condicionais
- Booleanos
- Cálculo de médias

---

#include <stdio.h>
#include <stdbool.h>

// Estrutura que armazena os dados de cada aluno
struct Aluno {
    char Nome[30];
    int Idade;
    char Sexo;
    float Notas[3];
    bool Aprovado;
};

int main() {

    float MediaAprov;
    int QtdAlunos;

    // Vetor para armazenar até 100 alunos
    struct Aluno Alunos[100];

    int aprovMasculino = 0;
    int aprovFeminino = 0;
    float SomaTurma = 0;

    // Solicita a média mínima para aprovação
    printf("Informe a media de aprovacao: ");
    scanf("%f", &MediaAprov);

    // Solicita a quantidade de alunos
    printf("Informe a quantidade de alunos: ");
    scanf("%i", &QtdAlunos);

    // Cadastro dos alunos
    for (int i = 0; i < QtdAlunos; i++) {

        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", Alunos[i].Nome);

        printf("Idade: ");
        scanf("%d", &Alunos[i].Idade);

        printf("Sexo (M/F): ");
        scanf(" %c", &Alunos[i].Sexo);

        // Cadastro das três notas
        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &Alunos[i].Notas[j]);
        }

        // Calcula a média do aluno
        float media = (Alunos[i].Notas[0] +
                       Alunos[i].Notas[1] +
                       Alunos[i].Notas[2]) / 3;

        // Soma as médias para calcular a média da turma
        SomaTurma += media;

        // Verifica se o aluno foi aprovado
        if (media >= MediaAprov) {

            Alunos[i].Aprovado = true;

            // Conta alunos e alunas aprovados
            if (Alunos[i].Sexo == 'M') {
                aprovMasculino++;
            } else if (Alunos[i].Sexo == 'F') {
                aprovFeminino++;
            }

        } else {
            Alunos[i].Aprovado = false;
        }
    }

    // Calcula a média geral da turma
    float MediaTurma = SomaTurma / QtdAlunos;

    printf("\nMedia da turma: %.2f\n", MediaTurma);

    printf("\nQuantidade de alunos aprovados: %d\n", aprovMasculino);
    printf("Quantidade de alunas aprovadas: %d\n", aprovFeminino);

    // Mostra os alunos aprovados
    printf("\n--- RELATORIO DE APROVADOS ---\n");

    for (int i = 0; i < QtdAlunos; i++) {
        if (Alunos[i].Aprovado) {
            printf("%s\n", Alunos[i].Nome);
        }
    }

    // Mostra os alunos reprovados
    printf("\n--- RELATORIO DE REPROVADOS ---\n");

    for (int i = 0; i < QtdAlunos; i++) {
        if (!Alunos[i].Aprovado) {
            printf("%s\n", Alunos[i].Nome);
        }
    }

    return 0;
}
