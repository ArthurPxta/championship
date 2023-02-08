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

<<<<<<< HEAD
int *functionVetorCompetidores(competidor *vetorCompetidores, int nCompetidores)
{
   cadastro = fopen("cadastro.txt", "r");

   vetorCompetidores = (int *) malloc (nCompetidores * sizeof(competidor));

   for(int i = 0; i < nCompetidores; i++)
   {
      fscanf(cadastro, "%d %s %s %.2f %d \n", vetorCompetidores[i].inscricao, vetorCompetidores[i].nome, vetorCompetidores[i].faixa, vetorCompetidores[i].peso, vetorCompetidores[i].idade);
   }

   return vetorCompetidores;
}

void removeCompetidores(competidor *vetorCompetidores, int nCompetidores)
{
   int inscricao;

   printf("\n Qual o id do competidor que deseja remover? ");
   scanf("%d", &inscricao);

   for(int i = 0; i < nCompetidores; i++)
   {
      if(inscricao == vetorCompetidores[i].inscricao)
      {
         
      }
   }
   
}

int contaCompetidores()
=======
int contarCompetidores()
>>>>>>> bc2d946dfe09e1657eace2d09782f596f9d9dd48
{
   cadastro = fopen("cadastro.txt", "r");
   // Testa se arquivo foi aberto corretamente
   if (cadastro == NULL)
   {
      printf("Error opening file.\n");
      printf("Function: getNumberOfStudents\n");
      return 1;
   }

   int nCompetidores = 0;
   char temp;

   while (fscanf(cadastro, "%c", &temp) != EOF)
   {
      if (temp == '\n')
         nCompetidores++;
   }
   fclose(cadastro);
   return nCompetidores;
}

// Cadastra um novo competidor, adicionando no arquivo
int cadastrarCompetidor(int nCompetidores)
{
   struct competidor competidor;

   // bug com o modo de cadastro a funciona para adicionar mas no primeiro caso falha
   // o w funciona apenas para o primeiro caso e nao para adicionar
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

   setbuf(stdin, NULL);

   printf("Informe a idade do competidor: ");
   scanf("%d", &competidor.idade);

   setbuf(stdin, NULL);

   nCompetidores++;

   //  competidor.inscricao = rand()%99999; //Fazer inscrição sequencial baseado no numero de participantes + 1;
   // Nova função cria o número de inscrição do competidor baseado na quantidade de competidores já inscritos, o número da inscrição será número de competidores + 1.
   competidor.inscricao = nCompetidores;

   fprintf(cadastro, "%d %s %s %.2f %d \n", competidor.inscricao, competidor.nome, competidor.faixa, competidor.peso, competidor.idade);

   fclose(cadastro);
   // comando para limpar a tela do terminal
   system("cls");

   return nCompetidores;
}

// Remove o competidor do vetor e do arquivo
void removerCompetidor()
{
}

// Altera algum dado do competidor do vetor e do arquivo
void alterarCompetidor()
{
}

// organizar o arquvivo antes de procurar o competidor
void acharCompetidor()
{
   int inscricao;
   printf("\nDigite o id do competidor que deseja: ");
   scanf("%d", &inscricao);
   printf("\nCompetidor de inscricao: %d", inscricao); // Fazer acentos funcionarem ??
}

// Começa o campeonato
void comecarCampeonato()
{
}

// Escreve o menu
int menu()
{
   int opcao;
   printf("\n\n------- MENU -------- \n");
   printf("1) CADASTRAR COMPETIDOR \n");
   printf("2) REMOVER COMPETIDOR \n");
   printf("3) ALTERAR DADOS DO COMPETIDOR \n");
   printf("4) PESQUISAR COMPETIDORES\n");
   printf("5) COMECAR CAMPEONATO \n");
   printf("6) SAIR \n");

   printf("\n Digite a Opcao: ");
   scanf("%d", &opcao);

   setbuf(stdin, NULL);
   return opcao;
}

int main()
{
   int opcao, nCompetidores = contarCompetidores();

   while (1)
   {

      opcao = menu();

      switch (opcao)
      {
      case 1:

         nCompetidores = cadastraCompetidor(nCompetidores);
         printf("\nO competidor foi cadastrado com sucesso!!\n");
         printf("Novo numero de competidores: %d", contarCompetidores());

         _sleep(3000);
         system("cls");
         break;

      case 2:
         // Criar função
         removerCompetidor();
         break;

      case 3:
         // Criar função
         alterarCompetidor();
         break;

      case 4:
         //   Por enquanto, mostra apenas o número de competidores
         printf("Numero de competidores: %d", nCompetidores);

         break;

      case 5:

         comecarCampeonato();
         break;

      case 6:

         printf("\nPrograma encerrado.\n");
         return 0;
         break;

      default:
         printf(" \n Opcao invalida! \n");
         break;
      }
   }
}