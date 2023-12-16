#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h> // Biblioteca para utilizar o tipo de dado booleano

struct Aluno
{
    char nome[50];
    char dataNascimento[15];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct Aluno aluno)
{
    return (aluno.nota1 + aluno.nota2) / 2.0;
}

bool verificarAprovacao(struct Aluno aluno)
{
    return aluno.media >= 7.0;
}

int main()
{
    struct Aluno alunos[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a data de nascimento do aluno %d: ", i + 1);
        scanf("%s", alunos[i].dataNascimento);

        printf("Digite a primeira nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Digite a segunda nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcularMedia(alunos[i]);
    }

    printf(" Médias dos alunos:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Aluno %d: %.2f\n", i + 1, alunos[i].media);
    }

    printf(" Situação dos alunos:\n");
    for (int i = 0; i < 5; i++)
    {
        printf(" Aluno %d: ", i + 1);
        if (verificarAprovacao(alunos[i]))
        {
            printf(" Aprovado\n");
        }
        else
        {
            printf(" Reprovado\n");
        }
    }

    return 0;
}
