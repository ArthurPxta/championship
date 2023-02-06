#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *cadastro;

typedef struct competidor
{
   char faixa[15], nome[50];
   float peso;
   int idade, inscricao;

} competidor;

int contaCompetidores()
{
   cadastro = fopen("cadastro.txt", "r");
   // Testa se arquivo foi aberto corretamente
   if (cadastro == NULL)
   {
      printf("Error opening file.\n");
      printf("Function: getNumberOfStudents\n");
      return 1;
   }

   int nCompetidores = 1;
   char temp;

   while (fscanf(cadastro, "%c", &temp) != EOF)
   {
      if (temp == '\n')
         nCompetidores++;
   }
   fclose(cadastro);
   return nCompetidores;
}

void achaCompetidor()
{
   int inscricao;
   printf("\nDigite o id do competidor que deseja: ");
   scanf("%d", &inscricao);
   printf("\nCompetidor de inscricao: %d", inscricao); // Fazer acentos funcionarem ??
}

// Alteração no nome da função: nome atualizado para seguir o padrão camelCase, convenção para nome de funções e variáveis
// int Cadastrar_Competidor(int n_competidores)
int cadastrarCompetidor(int nCompetidores)
{
   struct competidor competidor;

   cadastro = fopen("cadastro.txt", "a");
   // Testa se arquivo foi aberto corretamente
   if (cadastro == NULL)
   {
      printf("Error opening file.\n");
      printf("Function: getNumberOfStudents\n");
      return 1;
   }

   printf("Informe o nome do competidor:");
   scanf("%15[^\n]", competidor.nome);

   setbuf(stdin, NULL);

   printf("Informe a faixa do competidor:");
   scanf("%50[^\n]", competidor.faixa);

   setbuf(stdin, NULL);

   printf("Informe o peso do competidor:");
   scanf("%f", &competidor.peso);

   // setbuf(stdin, NULL);

   printf("Informe a idade do competidor: ");
   scanf("%d", &competidor.idade);

   nCompetidores++;

   //  competidor.inscricao = rand()%99999; //Fazer inscrição sequencial baseado no numero de participantes + 1;
   // Nova função cria o número de inscrição do competidor baseado na quantidade de competidores já inscritos, o número da inscrição será número de competidores + 1.
   competidor.inscricao = nCompetidores;

   fprintf(cadastro, "\n%d %s %s %.2f %d", competidor.inscricao, competidor.nome, competidor.faixa, competidor.peso, competidor.idade);

   fclose(cadastro);

   return nCompetidores;
}

int main()
{
   int opc, nCompetidores = contaCompetidores();

   competidor competidor;

   while (1)
   {
      printf("\n\n------- MENU -------- \n");
      printf("1) CADASTRAR COMPETIDOR \n");
      printf("2) REMOVER COMPETIDOR \n");
      printf("3) ALTERAR DADOS DO COMPETIDOR \n");
      printf("4) PESQUISAR COMPETIDORES\n");
      printf("5) COMECAR CAMPEONATO \n");
      printf("6) SAIR \n");

      printf("\n Digite a Opcao: ");
      scanf("%d", &opc);

      setbuf(stdin, NULL);

      switch (opc)
      {
      case 1:

         nCompetidores = cadastrarCompetidor(nCompetidores);

         printf("O numero de competidores eh: %d", contaCompetidores()); // Fazer os acentos funcionarem ??

         break;

      case 2:

         break;

      case 3:

         break;

      case 4:
         //   Por enquanto, mostra apenas o número de competidores
         printf("Numero de competidores: %d", nCompetidores);
         achaCompetidor();

         break;

      case 5:
         break;

      case 6:

         printf("Programa encerrado.");
         return 0;
         break;

      default:
         printf(" \n Opcao invalida! \n");
         break;
      }
   }
}