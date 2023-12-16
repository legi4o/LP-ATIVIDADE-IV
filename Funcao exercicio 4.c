#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct ContaBancaria
{
    int numeroConta;
    char nomeTitular[50];
    double saldo;
    char tipoConta[20];
};

void depositar(struct ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Depósito de %.2lf realizado com sucesso.\n", valor);
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("Saque de %.2lf realizado com sucesso.\n", valor);
    }
    else
    {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
}

void imprimirSaldo(struct ContaBancaria conta)
{
    printf("Saldo atual: %.2lf\n", conta.saldo);
}

int main()
{
    struct ContaBancaria minhaConta;
    minhaConta.numeroConta = 1234;
    strcpy(minhaConta.nomeTitular, "Fulano de Tal");
    minhaConta.saldo = 1000.00;
    strcpy(minhaConta.tipoConta, "Corrente");

    setlocale(LC_ALL, "portuguese");

    int opcao;
    float valor;

    do
    {
        printf("\nEscolha uma opção:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Ver saldo\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor para depósito: ");
            scanf("%lf", &valor);
            depositar(&minhaConta, valor);
            break;
        case 2:
            printf("Digite o valor para saque: ");
            scanf("%lf", &valor);
            sacar(&minhaConta, valor);
            break;
        case 3:
            imprimirSaldo(minhaConta);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
