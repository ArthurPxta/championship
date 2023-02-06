#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct competidor
{
    char faixa[15], nome[50];
    float peso;
    int idade, inscricao;

} competidor ;

int Cadastrar_Competidor(int n_competidores)
{
    struct competidor competidor;

    FILE *cadastro = fopen("cadastro.txt", "a");
            
    printf("Informe o nome do competidor:");
    scanf("%15[^\n]", competidor.nome);
            
    setbuf(stdin, NULL);
            
    printf("Informe a faixa do competidor:");
    scanf("%50[^\n]", competidor.faixa);
            
    setbuf(stdin, NULL);

    printf("Informe o peso do competidor:");
    scanf("%f", &competidor.peso);

    //setbuf(stdin, NULL);
            
    printf("Informe a idade do competidor: ");
    scanf("%d", &competidor.idade);

    competidor.inscricao = rand()%99999;

    fprintf(cadastro, "%d %s %s %.2f %d\n", competidor.inscricao, competidor.nome, competidor.faixa, competidor.peso, competidor.idade);
            
    fclose(cadastro);

    n_competidores++;

    return n_competidores;
}

int main ()
{   
    int opc, n_competidores = 0;


    competidor competidor;

    while (1)
    {
        printf("\n------- MENU -------- \n");
        printf("1) CADASTRAR COMPETIDOR \n");
        printf("2) REMOVER COMPETIDOR \n");
        printf("3) ALTERAR DADOS DO COMPETIDOR \n");
        printf("4) COMECAR CAMPEONATO \n");
        printf("5) SAIR \n");

        printf("\n Digite a Opcao: ");
        scanf("%d", &opc);

        setbuf(stdin, NULL);

        switch (opc)
        {
        case 1 :

        n_competidores = Cadastrar_Competidor(n_competidores);

        printf("O numero de competidores é; %d", n_competidores);
        
            break;

        case 2:


            break;

        case 3:


            break;

        case 4:


            break;

        case 5:
            
            return 0;

            break;

        default:
            printf(" \n Opcao invalida! \n");
            break;
        }
    }
}