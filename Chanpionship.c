#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declaração do ponteiro FILE
FILE *cadastro;

// declaração do struct competidor
typedef struct competidor
{
   char faixa[15], nome[50];
   float peso;
   int idade, inscricao;

} competidor;

competidor *vetorCompetidores;

// carrega os competidores do arquivo no vetor
void carregarCompetidores(int nCompetidores)
{
   cadastro = fopen("cadastro.txt", "r");
   vetorCompetidores = (competidor *)malloc(nCompetidores * sizeof(competidor));
   for (int i = 0; i < nCompetidores; i++)
   {
      fscanf(cadastro, "%d %s %s %f %d", &vetorCompetidores[i + 1].inscricao,
             vetorCompetidores[i + 1].nome, vetorCompetidores[i + 1].faixa,
             &vetorCompetidores[i + 1].peso, &vetorCompetidores[i + 1].idade);
   }
   fclose(cadastro);
}

void salvarCompetidores(int nCompetidores)
{
   cadastro = fopen("cadastro.txt", "w");

   if (cadastro == NULL)
   {
      printf("Error opening file.\n");
      printf("Function: getNumberOfStudents\n");
      return 1;
   }

   for (int i = 0; i < nCompetidores; i++)
   {
      fprintf(cadastro, "%d %s %s %g %d\n",
              vetorCompetidores[i + 1].inscricao,
              vetorCompetidores[i + 1].nome,
              vetorCompetidores[i + 1].faixa,
              vetorCompetidores[i + 1].peso,
              vetorCompetidores[i + 1].idade);
   }
   fclose(cadastro);
}
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

int cadastrarCompetidor(int nCompetidores)
{
   system("cls");
   printf("\n---- CADASTRO DE COMPETIRORES ------\n");

   nCompetidores++;

   if ((vetorCompetidores = realloc(vetorCompetidores, nCompetidores * sizeof(competidor))) == NULL)
   {
      exit(1);
   }

   vetorCompetidores[nCompetidores].inscricao = nCompetidores;

   printf("Informe o nome do competidor:");
   scanf("%15[^\n]", vetorCompetidores[nCompetidores].nome);

   setbuf(stdin, NULL);

   printf("Informe a faixa do competidor:");
   scanf("%50[^\n]", vetorCompetidores[nCompetidores].faixa);

   setbuf(stdin, NULL);

   printf("Informe o peso do competidor:");
   scanf("%f", &vetorCompetidores[nCompetidores].peso);

   setbuf(stdin, NULL);

   printf("Informe a idade do competidor: ");
   scanf("%d", &vetorCompetidores[nCompetidores].idade);

   setbuf(stdin, NULL);

   salvarCompetidores(nCompetidores);

   printf("\nO competidor foi cadastrado com sucesso!!\n");
   printf("Novo numero de competidores: %d", nCompetidores);
   _sleep(3000);

   // Retorna o novo número de competidores
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
   // vetorCompetidores = (int *) malloc (nCompetidores * sizeof(struct
   // competidor));

   printf("\n Qual o id do competidor que deseja remover? ");
   scanf("%d", &inscricao);
   setbuf(stdin, NULL);

   // func para ver se o competidor está no arquivo
   // acharCompetidor(vetorCompetidores, nCompetidores, inscricao);

   for (int i = 0; i < nCompetidores; i++)
   {

      if (inscricao == vetorCompetidores[i].inscricao)
      {
         printf("\n Deseja remover o competidor %s faixa %s (S/n)",
                vetorCompetidores[i].nome, vetorCompetidores[i].faixa);
         scanf(" %c", &confirma);
         setbuf(stdin, NULL);

         if (toupper(confirma) == 'S')
         {
            vetorCompetidores[i].inscricao = 0;
         }
      }
   }
   // apaga o conteudo do arquivo anterior
   cadastro = fopen("cadastro.txt", "w+");
   // escreve a quantidade de competidores restantes
   for (int i = 0; i < nCompetidores; i++)
   {
      if (vetorCompetidores[i].inscricao != 0)
      {
         fprintf(cadastro, "%d %s %s %f %d \n", vetorCompetidores[i].inscricao,
                 vetorCompetidores[i].nome, vetorCompetidores[i].faixa,
                 vetorCompetidores[i].peso, vetorCompetidores[i].idade);
      }
   }
   // fecha o arquivo
   fclose(cadastro);
   // limpa a memoria do vetor
   free(vetorCompetidores);

   system("cls");
   
   printf("\n O competidor foi removido com sucesso \n");
   printf("Novo numero de competidores: %d", contarCompetidores());
   _sleep(3000);
}

// Altera algum dado do competidor do vetor e do arquivo
void alterarCompetidor() {}

// verifica se o competidor esta no arquivo
void acharCompetidor()
{
   int id;

   system("cls");
   printf("Competidores registrados: %d\n", contarCompetidores());
   printf("Digite a inscricao do competidor: ");
   scanf(" %d", &id);

   printf("\nNome: %s\nInscricao: %d\nFaixa: %s\nPeso: %g\nIdade: %d", vetorCompetidores[id].nome, vetorCompetidores[id].inscricao, vetorCompetidores[id].faixa, vetorCompetidores[id].peso, vetorCompetidores[id].idade);

   printf("\nAperte qualquer tecla para continuar.\n");
   // Aparentemente, getch funciona apenas no windows
   _getch();
   // solução com scanf("%c", &temp); não funcionou, pois era necessário apertar um tecla + Enter
}

// Começa o campeonato
void comecarCampeonato() {}

// Escreve o menu
int menu()
{
   int opcao;

   system("cls");
   printf("------- MENU -------- \n");
   printf("1) CADASTRAR COMPETIDOR \n");
   printf("2) REMOVER COMPETIDOR \n");
   printf("3) ALTERAR DADOS DO COMPETIDOR \n");
   printf("4) PESQUISAR COMPETIDORES\n");
   printf("5) COMECAR CAMPEONATO \n");
   printf("6) SAIR \n");

   printf("\nDigite a Opcao: ");
   scanf("%d", &opcao);

   setbuf(stdin, NULL);
   return opcao;
}

int main()
{
   int opcao, nCompetidores = contarCompetidores();

   carregarCompetidores(nCompetidores);

   while (1)
   {

      opcao = menu();

      switch (opcao)
      {
      case 1:

         nCompetidores = cadastrarCompetidor(nCompetidores);
         break;

      case 2:
         removerCompetidor(vetorCompetidores, nCompetidores);
         break;
      case 3:
         // alterarCompetidor();
         break;
      case 4:
         acharCompetidor();
         break;
      case 5:
         comecarCampeonato();
         printf("\nPrograma encerrado.\n");
         return 0;
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
   free(vetorCompetidores);
}