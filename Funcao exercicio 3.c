#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto
{
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

float calcularValorTotal(struct Produto produto)
{
    return produto.preco * produto.quantidadeEstoque;
}

void adicionarProduto(struct Produto *produto)
{
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &produto->preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidadeEstoque);
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > produto->quantidadeEstoque)
    {
        printf("Quantidade insuficiente em estoque.\n");
    }
    else
    {
        produto->quantidadeEstoque -= quantidadeCompra;
        printf("Compra realizada com sucesso.\n");
    }
}

void consultarEstoque(struct Produto produto)
{
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("Valor total em estoque: %.2f\n", calcularValorTotal(produto));
}

int main()
{
    struct Produto meuProduto;
    int opcao;

    setlocale(LC_ALL, "portuguese");

    do
    {
        printf("\nMenu:\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Realizar uma compra\n");
        printf("3 - Consultar estoque\n");
        printf("4 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarProduto(&meuProduto);
            break;
        case 2:
            realizarCompra(&meuProduto);
            break;
        case 3:
            consultarEstoque(meuProduto);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}