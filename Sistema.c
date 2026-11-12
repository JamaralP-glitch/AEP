#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RlMax 100 // Difinir valor maximo de relatorio que será salvo.

//Essa parte seria o banco de dados que será ultilzado para amazenar as informações nos relatorios

char nome[RlMax][50];
int idade[RlMax];
float altura[RlMax];
float peso[RlMax];
int PAtividade[RlMax]; // ela é int pois irei ultilizar booleano como para validar, 1 = sim, 0 = não
char Atividade[RlMax][50];

int total = 0; // essa variavel será o nosso relatorios que foram criados


/* A função abaixo será para criar os relatorio */

void CriarRelatorio() {
    if (total >= RlMax){
        printf("Banco de Dados cheio!\n");
         return;
    }

    printf("\n-----------Criar Relatorio-------------\n");

    printf("Nome: ");
    scanf(" %[^\n]", nome[total]); // esse comando %[^\n] serve para ler nomes com espaços

    printf("Idade: ");
    scanf("%d", &idade[total]);
    
    
    printf("Altura (ex: 1.63): ");
    scanf("%f", &altura[total]);
 
    printf("Peso (kg): ");
    scanf("%f", &peso[total]);
 
    printf("Pratica alguma atividade fisica? (1 = Sim, 0 = Nao): ");
    scanf("%d", &PAtividade[total]);
 
    if (PAtividade[total] == 1) {
        printf("Informe qual atividade fisica: "); // esse comando %[^\n] serve para ler nomes com espaços
        scanf(" %[^\n]",Atividade[total]);
    } else {
        strcpy(Atividade[total], "Nenhuma");
    }
 
    total = total + 1; 

    // o ID do relatorio é o valor de total (1º relatorio = ID 1, 2º = ID 2, asssim chegando até 100)
    printf("\nRelatorio criado! ID do relatorio: %d\n", total);
}


/* A função abaixo será para pesquisar os relatorios */

void PesquisarRelatorio() {
    int id, tipo;

    printf("\n-----------Pesquisar Relatorio-------------\n");

    if (total == 0) {
        printf("Nenhum relatorio criado ainda.\n");
        return;
    }

    printf("ID do relatorio: ");
    scanf("%d", &id);

    if (id < 1 || id > total) {
        printf("Relatorio nao encontrado.\n");
        return;
    }

    // as posições dos vetores começam em 0, por isso usamos id - 1
    printf("Relatorio simples ou detalhado? (1 = Simples, 2 = Detalhado): ");
    scanf("%d", &tipo);

    if (tipo == 1) {
        printf("\n-----------Relatorio Simples-------------\n");
        printf("ID: %d\n", id);
        printf("Nome: %s\n", nome[id - 1]);
    } else {
        printf("\n-----------Relatorio Detalhado-------------\n");
        printf("ID: %d\n", id);
        printf("Nome: %s\n", nome[id - 1]);
        printf("Idade: %d\n", idade[id - 1]);
        printf("Altura: %.2f\n", altura[id - 1]);
        printf("Peso: %.1f\n", peso[id - 1]);
        printf("Atividade fisica: %s\n", Atividade[id - 1]);
    }
}


/* Programa principal: login e menu */

int main() {
    char login[20], senha[20];
    int opcao;

    printf("-----------Login de Colaborador-------------\n");
    printf("Login: ");
    scanf("%s", login);
    printf("Senha: ");
    scanf("%s", senha);

    if (strcmp(login, "admin") != 0 || strcmp(senha, "1234") != 0) // Condições para fazer o login
     {
        printf("Login ou senha incorretos.\n");
        return 0;
    }
    
        // menu para de opçoes para consegueir selecionar as os caminhos no código
    do {
        printf("\n-----------Menu-------------\n");
        printf("1 - Criar relatorio\n");
        printf("2 - Pesquisar relatorio\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            CriarRelatorio();
        } else if (opcao == 2) {
            PesquisarRelatorio();
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    printf("Fim do programa.\n");
    return 0;
}
