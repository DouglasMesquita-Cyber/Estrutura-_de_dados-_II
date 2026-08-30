#include <stdio.h>

// Criando o molde (struct) para guardar os dados do funcionário num pacotinho só
struct Funcionario {
    char nome[50];    // Vetor de caracteres para guardar o nome
    int idade;        // Número inteiro para a idade
    char cargo[30];   // Vetor para o cargo (ex: "Analista")
    float salario;    // Número com casas decimais para o salário
};

int main() {
    // Vetor capaz de guardar até 10 funcionários na memória do computador
    struct Funcionario f[10];
    
    // 'total' controla quantos funcionários já foram cadastrados de verdade (começa em 0)
    // 'op' guarda a opção que o usuário escolher no menu
    int total = 0, op;

    // O do-while garante que o menu vai ficar aparecendo repetidas vezes 
    // até que o usuário decida sair digitando 0.
    do {
        // Desenhando o menu visual bonitinho na tela
        printf("\n=================================\n");
        printf("       SISTEMA DE FUNCIONARIOS\n");
        printf("=================================\n\n");
        printf("1 - Cadastrar funcionarios\n");
        printf("2 - Listar funcionarios\n");
        printf("3 - Maior salario\n");
        printf("4 - Media salarial\n");
        printf("5 - Salarios acima da media\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao: ");
        
        // Lendo a opção que o usuário digitou
        scanf("%d", &op);

        // ==========================================
        // OPÇÃO 1: CADASTRAR FUNCIONÁRIO
        // ==========================================
        if (op == 1 && total < 10) {
            // O espaço antes de cada % (ex: " %s") é um truque do C para 
            // ignorar o "Enter" que fica sobrando no teclado e não pular nenhuma linha.
            printf("\nNome: "); scanf(" %s", f[total].nome);
            printf("Idade: "); scanf(" %d", &f[total].idade);
            printf("Cargo: "); scanf(" %s", f[total].cargo);
            printf("Salario: "); scanf(" %f", &f[total].salario);
            
            total++; // Aumenta 1 no contador, pois acabamos de salvar mais um funcionário com sucesso
            printf("\nCadastrado com sucesso!\n");
        }
        // Se a pessoa tentar cadastrar e a lista já estiver lotada (10/10)
        else if (op == 1 && total >= 10) {
            printf("\nLimite de 10 funcionarios atingido!\n");
        }
        
        // ==========================================
        // OPÇÃO 2: LISTAR TODOS OS FUNCIONÁRIOS
        // ==========================================
        else if (op == 2) {
            // Se o contador for 0, significa que não tem nada cadastrado ainda
            if (total == 0) {
                printf("\nNenhum funcionario cadastrado ainda.\n");
            } else {
                printf("\n--- LISTA DE FUNCIONARIOS ---\n");
                // Passa por cada funcionário cadastrado e imprime os dados na tela
                for (int i = 0; i < total; i++) {
                    printf("[%d] %s | %d anos | %s | R$ %.2f\n", i+1, f[i].nome, f[i].idade, f[i].cargo, f[i].salario);
                }
            }
        }
        
        // ==========================================
        // OPÇÃO 3: MOSTRAR O MAIOR SALÁRIO
        // ==========================================
        else if (op == 3) {
            if (total == 0) {
                printf("\nCadastre alguem primeiro!\n");
            } else {
                int maior = 0; // Assume inicialmente que o primeiro funcionário (posição 0) é o que ganha mais
                
                // Compara o salário do recordista atual com o de todos os outros
                for (int i = 1; i < total; i++) {
                    if (f[i].salario > f[maior].salario) {
                        maior = i; // Se achar alguém que ganha mais, atualiza o índice do campeão
                    }
                }
                // Mostra os dados do funcionário que tem o maior salário da lista
                printf("\nMaior salario: %s (%s) - R$ %.2f\n", f[maior].nome, f[maior].cargo, f[maior].salario);
            }
        }
        
        // ==========================================
        // OPÇÃO 4: CALCULAR A MÉDIA SALARIAL
        // ==========================================
        else if (op == 4) {
            if (total == 0) {
                printf("\nSem funcionarios para calcular a media.\n");
            } else {
                float soma = 0;
                // Soma o salário de todos os funcionários cadastrados
                for (int i = 0; i < total; i++) {
                    soma += f[i].salario; 
                }
                // A média é o valor total somado dividido pela quantidade de funcionários
                printf("\nMedia salarial: R$ %.2f\n", soma / total);
            }
        }
        
        // ==========================================
        // OPÇÃO 5: SALÁRIOS ACIMA DA MÉDIA
        // ==========================================
        else if (op == 5) {
            if (total == 0) {
                printf("\nNenhum funcionario cadastrado.\n");
            } else {
                // Passo 1: Descobrir a média salarial primeiro para servir de base
                float soma = 0;
                for (int i = 0; i < total; i++) {
                    soma += f[i].salario;
                }
                float media = soma / total; 
                
                printf("\nSalarios acima da media (R$ %.2f):\n", media);
                int achou = 0; // Bandeirinha para sabermos se encontramos alguém

                // Passo 2: Passa pela lista de novo comparando cada salário com a média
                for (int i = 0; i < total; i++) {
                    if (f[i].salario > media) {
                        printf("- %s | R$ %.2f\n", f[i].nome, f[i].salario);
                        achou = 1; // Mudou para 1 porque achamos pelo menos um
                    }
                }
                // Se a bandeirinha continuar 0, ninguém ganha acima da média
                if (!achou) {
                    printf("Ninguem ganha acima da media atual.\n");
                }
            }
        }
        // ==========================================
        // OPÇÃO 0: SAIR DO SISTEMA
        // ==========================================
        else if (op == 0) {
            printf("\nSaindo do sistema... Bons estudos!\n");
        }
        // Caso o usuário digite um número que não existe no menu
        else {
            printf("\nOpcao invalida! Tente de novo.\n");
        }
        
    } while (op != 0); // O loop continua rodando enquanto a opção for diferente de 0

    return 0;
}