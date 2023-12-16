#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Funcionario
{
    char nome[50];
    char cargo[50];
    float salario;
};

float mediaSalarialPorCargo(struct Funcionario funcionarios[], int tamanho, const char *cargo)
{
    float somaSalarios = 0.0;
    int contador = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(funcionarios[i].cargo, cargo) == 0)
        {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador > 0)
    {
        return somaSalarios / contador;
    }
    else
    {
        return 0.0;
    }
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    struct Funcionario empresa[5] = {
        {"Joao", "Programador", 3000.0},
        {"Maria", "Programador", 3500.0},
        {"Pedro", "Analista", 4000.0},
        {"Laura", "Gerente", 6000.0},
        {"Carlos", "Programador", 3200.0}};

    const char *cargoProcurado = "Programador";
    float mediaSalarial;

    mediaSalarial = mediaSalarialPorCargo(empresa, 5, cargoProcurado);

    if (mediaSalarial > 0)
    {
        printf("Média salarial dos programadores: %.2f\n", mediaSalarial);
    }
    else
    {
        printf("Não há funcionários com o cargo especificado.\n");
    }

    return 0;
}
