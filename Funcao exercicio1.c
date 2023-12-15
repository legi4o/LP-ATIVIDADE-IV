#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tam 3

struct dadoscontatos
{
    char nome[100];
    char email[200];
    char telefone[200];
};

void pesquisarcontato(struct dadoscontatos *contatos, char *contato)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (strcmp(contatos[i].nome, contato) == 0)
        {
            printf(" Nome: %s \n", contatos[i].nome);
            printf(" Telefone: %s \n", contatos[i].telefone);

            return;
        }
    }

    printf(" Contato não encontrado");
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    struct dadoscontatos contatos[tam];
    char contato[100];
    int i;

    for (i = 0; i < tam; i++)
    {
        printf(" Digite o nome do contato: ");
        gets(contatos[i].nome);
        printf(" Digite o número de telefone: ");
        gets(contatos[i].telefone);
        printf(" Digite o email: ");
        gets(contatos[i].email);
        printf("\n");
    }

    printf(" Digite o nome do contato que desja buscar: ");
    gets(contato);

    printf("\n");

    pesquisarcontato(contatos, contato);

    return 0;
}