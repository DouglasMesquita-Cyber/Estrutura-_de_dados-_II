#include <stdio.h>

// Moldizinho da struct para guardar os dados do funcionário
struct Funcionario {
    char nome[50];
    int idade;
    char cargo[30];
    float salario;
};

int main() {
    // Vetor para guardar até 10 funcionários e variáveis de controle
    struct Funcionario f[10];
    int total = 0, op;

    // O do-while mantém o menu rodando até a pessoa digitar 0 para sair
    do {
        printf("\n1. Cadastrar | 2. Listar | 3. Maior Salario | 4. Media | 5. Acima da Media | 0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        // Opção 1: Cadastrar funcionário (se não passou do limite de 10)
        if (op == 1 && total < 10) {
            // O espaço antes de cada % diz para o C ignorar o Enter anterior
            printf("Nome: "); scanf(" %s", f[total].nome);
            printf("Idade: "); scanf(" %d", &f[total].idade);
            printf("Cargo: "); scanf(" %s", f[total].cargo);
            printf("Salario: "); scanf(" %f", &f[total].salario);
            
            total++; // Aumenta um no total de cadastrados
            printf("Cadastrado com sucesso!\n");
        }
        
        // Opção 2: Listar todo mundo que foi cadastrado
        else if (op == 2) {
            for (int i = 0; i < total; i++) {
                printf("\n[%d] %s | %d anos | %s | R$ %.2f\n", i+1, f[i].nome, f[i].idade, f[i].cargo, f[i].salario);
            }
        }
        
        // Opção 3: Descobrir quem tem o maior salário
        else if (op == 3 && total > 0) {
            int maior = 0; // Assume que o primeiro é o maior inicialmente
            for (int i = 1; i < total; i++) {
                if (f[i].salario > f[maior].salario) {
                    maior = i; // Atualiza se achar alguém que ganha mais
                }
            }
            printf("\nMaior salario: %s (R$ %.2f)\n", f[maior].nome, f[maior].salario);
        }
        
        // Opção 4: Calcular a média salarial da empresa
        else if (op == 4 && total > 0) {
            float soma = 0;
            for (int i = 0; i < total; i++) {
                soma += f[i].salario; // Soma todos os salários
            }
            printf("\nMedia salarial: R$ %.2f\n", soma / total);
        }
        
        // Opção 5: Mostrar quem ganha acima da média
        else if (op == 5 && total > 0) {
            float soma = 0;
            for (int i = 0; i < total; i++) {
                soma += f[i].salario;
            }
            float media = soma / total; // Descobre a média primeiro
            
            printf("\nAcima da media (R$ %.2f):\n", media);
            for (int i = 0; i < total; i++) {
                if (f[i].salario > media) { // Se o salário for maior que a média, imprime
                    printf("- %s (R$ %.2f)\n", f[i].nome, f[i].salario);
                }
            }
        }
        
    } while (op != 0); // Continua no loop até digitar 0

    return 0;
}
