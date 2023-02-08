#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// declaração do ponteiro FILE
FILE *cadastro;

// declaração do struct competidor
typedef struct competidor
{
   char faixa[15], nome[50];
   float peso;
   int idade, inscricao;

} competidor;

// função que conta competidores
int contarCompetidores()
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
   system("cls");
   printf("\n---- CADASTRO DE COMPETIRORES ------\n");

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

   setbuf(stdin, NULL);

   printf("Informe a idade do competidor: ");
   scanf("%d", &competidor.idade);

   setbuf(stdin, NULL);

   nCompetidores++;

   competidor.inscricao = nCompetidores;

   fprintf(cadastro, "%d %s %s %.2f %d \n", competidor.inscricao, competidor.nome, competidor.faixa, competidor.peso, competidor.idade);

   fclose(cadastro);
   // comando para limpar a tela do terminal
   system("cls");

   return nCompetidores;
}

// Remove o competidor do vetor e do arquivo
void removerCompetidor(competidor *vetorCompetidores, int nCompetidores)
{  
   // limpa a tela 
   system("cls");
   printf("\n ----- REMOCAO DE COMPETIDORES ------ \n");
   int inscricao;
   char confirma;

   // vetor com a quantidade de competidores inscritos
   vetorCompetidores = (int *) malloc (nCompetidores * sizeof(struct competidor));

   printf("\n Qual o id do competidor que deseja remover? ");
   scanf("%d", &inscricao);
   setbuf(stdin,NULL);

   // func para ver se o competidor está no arquivo
   acharCompetidor(vetorCompetidores, nCompetidores, inscricao);

   for(int i = 0; i < nCompetidores; i++)
   {
      
      if(inscricao == vetorCompetidores[i].inscricao)
      {
         printf("\n Deseja remover o competidor %s faixa %s (S/n)", vetorCompetidores[i].nome, vetorCompetidores[i].faixa);
         scanf(" %c", &confirma);
         setbuf(stdin,NULL);

         if(toupper(confirma) == 'S')
         {
            vetorCompetidores[i].inscricao = 0;
         }
      }
   }
   // apaga o conteudo do arquivo anterior
   cadastro = fopen("cadastro.txt", "w+");
   // escreve a quantidade de competidores restantes
   for(int i = 0; i < nCompetidores;i++)
   {
      if(vetorCompetidores[i].inscricao != 0)
      {
         fprintf(cadastro, "%d %s %s %f %d \n", vetorCompetidores[i].inscricao, vetorCompetidores[i].nome, vetorCompetidores[i].faixa, vetorCompetidores[i].peso, vetorCompetidores[i].idade);

      }
   }
   // fecha o arquivo
   fclose(cadastro);
   //limpa a memoria do vetor
   free(vetorCompetidores);
   system("cls");
}

// Altera algum dado do competidor do vetor e do arquivo
void alterarCompetidor()
{
}

// verifica se o competidor esta no arquivo
void acharCompetidor(competidor *vetorCompetidores, int nCompetidores, int inscricao)
{

   cadastro = fopen("cadastro.txt", "r");

   for(int i = 0; i < nCompetidores; i++)
   {
      fscanf(cadastro, "%d %s %s %f %d", &vetorCompetidores[i].inscricao, vetorCompetidores[i].nome, vetorCompetidores[i].faixa, &vetorCompetidores[i].peso, &vetorCompetidores[i].idade);
      if(inscricao == vetorCompetidores[i].inscricao)
      {
         printf("\n O competidor %s esta no arquvivo \n", vetorCompetidores[i].nome);
      }
   }

   fclose(cadastro);
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

   competidor *vetorCompetidores;

   while (1)
   {

      opcao = menu();

      switch (opcao)
      {
      case 1:

         nCompetidores = cadastrarCompetidor(nCompetidores);

         printf("\nO competidor foi cadastrado com sucesso!!\n");
         printf("Novo numero de competidores: %d", contarCompetidores());

         _sleep(3000);
         system("cls");
         break;

      case 2:
         // Criar função
         removerCompetidor(vetorCompetidores, nCompetidores);

         printf("\n O competidor foi removido com sucesso \n");
         printf("Novo numero de competidores: %d", contarCompetidores());

         _sleep(3000);
         system("cls");
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