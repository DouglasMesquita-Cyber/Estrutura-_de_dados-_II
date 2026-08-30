#include <stdio.h>
#include <string.h>

// Criando o nosso "molde" (struct) chamado Produto.
// Aqui a gente agrupa diferentes tipos de dados que pertencem a um mesmo item.
struct Produto {
    char nome[50];    // String para guardar o nome (vetor de caracteres)
    int codigo;       // Inteiro para o código do produto
    float preco;      // Float para o preço unitário (aceita casas decimais)
    int quantidade;   // Inteiro para o total que tem guardado no estoque
};

int main() {
    // Declarando um array da struct para conseguir cadastrar 5 produtos diferentes
    struct Produto produtos[5];
    
    // Variáveis de apoio para descobrir qual é o produto mais valioso no final
    int indiceMaior = 0;
    float maiorValorEstoque = 0;

    printf("Cadastro de Produtos:\n");
    
    // Loop principal que vai rodar 5 vezes para preencher o array de produtos
    for (int i = 0; i < 5; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        
        // 1. Lendo o Nome
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        
        // ESSENCIAL: O scanf("%s") deixa a tecla "Enter" (\n) presa no buffer do teclado.
        // O while(getchar() != '\n') limpa esse Enter para não estragar a leitura do próximo campo.
        while(getchar() != '\n'); 

        // 2. Lendo o Código
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        while(getchar() != '\n'); // Limpa o Enter do código também

        // 3. Lendo o Preço
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        while(getchar() != '\n'); // Limpa o Enter do preço

        // 4. Lendo a Quantidade
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
        // Nota: Não colocamos getchar() aqui na quantidade porque ela é o último dado 
        // lido do bloco. O loop já vai direto para o próximo produto de qualquer forma.
    }

    // Exibindo o relatório geral de todos os itens cadastrados
    printf("\n=== RELATORIO DE ESTOQUE ===\n");
    for (int i = 0; i < 5; i++) {
        
        // Calculando o valor total que esse produto empacota (Preço x Quantidade)
        float valorTotal = produtos[i].preco * produtos[i].quantidade;

        // Imprimindo as informações formatadas na tela
        printf("Produto: %s | Codigo: %d | Preco: R$ %.2f | Qtd: %d | Total em estoque: R$ %.2f\n", 
               produtos[i].nome, produtos[i].codigo, produtos[i].preco, produtos[i].quantidade, valorTotal);

        // Lógica para achar o maior valor em estoque:
        // Se for o primeiro loop (i == 0) a gente já assume ele como o campeão inicial.
        // Nos próximos, se o valor atual for maior que o recordista anterior, a gente atualiza!
        if (i == 0 || valorTotal > maiorValorEstoque) {
            maiorValorEstoque = valorTotal;
            indiceMaior = i; // Guarda em qual posição do array está o campeão
        }
    }

    // Mostrando o resultado final de quem acumulou mais grana no estoque
    printf("\nProduto com o maior valor em estoque:\n");
    printf("%s (Total: R$ %.2f)\n", produtos[indiceMaior].nome, maiorValorEstoque);

    return 0;
}