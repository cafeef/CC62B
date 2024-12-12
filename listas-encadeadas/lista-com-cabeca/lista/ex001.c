#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct funcionario {
    char cpf[12];
    char nomeCompleto[25];
    char telefone[15];
    char email[25];
    float salario;
    struct funcionario *prox;
} Funcionario;

typedef struct departamento {
    char setor[15];
    int qtd_funcionarios;
    Funcionario *funcionarios;
} Departamento;

/*
1 - criar departamento
2 - alocar funcionarios
3 - adicionar funcionários
4 - exibir
*/
void aloca_variaveis (char *cpf, char *nomeCompleto, char *telefone, char *email, float *salario);
Departamento *criarDepartamento(const char *setor);
Funcionario *alocaFuncionario(const char *cpf, const char *nomeCompleto, const char *telefone, const char *email, float salario);
void inserirFuncionario(Departamento *departamento, const char *cpf, const char *nomeCompleto, const char *telefone, const char *email, float salario);
void exibirFuncionarios(Departamento *departamento, Funcionario *funcionario);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char setor[15], cpf[12], nomeCompleto[25], telefone[15], email[25];
    float salario;
    int op = 0;
    Departamento *departamento = NULL;
    printf("Digite o setor do departamento: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", setor);
    departamento = criarDepartamento(setor);
    while (op != 3) {
        printf("\n\nDigite uma das opções abaixo:\n1 - Cadastrar funcionário\n2 - Exibir funcionários\n3 - Sair do programa\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            aloca_variaveis(cpf, nomeCompleto, telefone, email, &salario);
            inserirFuncionario(departamento, cpf, nomeCompleto, telefone, email, salario);
            system("cls");
            break;
        case 2: 
            exibirFuncionarios(departamento, departamento->funcionarios);
            break;
        case 3:
            printf("Encerrando o programa...\n");
            free(departamento);
            departamento = NULL;
            system("cls");
            printf("Programa encerrado.\n");
            exit(1);
        default:
            break;
        }
    }
}

void aloca_variaveis (char *cpf, char *nomeCompleto, char *telefone, char *email, float *salario) {
    printf("Digite o CPF do funcionário: ");
    scanf("%s", cpf);
    getchar();
    printf("Digite o nome completo do funcionário: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", nomeCompleto);
    printf("Digite o telefone do funcionário: ");
    scanf("%s", telefone);
    printf("Digite o e-mail do funcionário: ");
    scanf("%s", email);
    printf("Digite o salário do funcionário: ");
    scanf("%f", salario);
}

Departamento *criarDepartamento(const char *setor) {
    Departamento *departamento = (Departamento *) malloc(sizeof(Departamento));
    if (departamento) {
        strcpy(departamento->setor, setor);
        departamento->qtd_funcionarios = 0;
        departamento->funcionarios = NULL;
        return departamento;
    }
    else return NULL;
}

Funcionario *alocaFuncionario(const char *cpf, const char *nomeCompleto, const char *telefone, const char *email, float salario) {
    Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));
    if (novo) {
        strcpy(novo->cpf, cpf);
        strcpy(novo->nomeCompleto, nomeCompleto);
        strcpy(novo->telefone, telefone);
        strcpy(novo->email, email);
        novo->salario = salario;
        novo->prox = NULL;
        return novo;
    }
    else return NULL;
}

void inserirFuncionario(Departamento *departamento, const char *cpf, const char *nomeCompleto, const char *telefone, const char *email, float salario) {
    Funcionario *novo = NULL;
    novo = alocaFuncionario(cpf, nomeCompleto, telefone, email, salario);
    if (novo) {
        if (!departamento->funcionarios) {
            departamento->funcionarios = novo;
            departamento->qtd_funcionarios++;
        }
        else {
            novo->prox = departamento->funcionarios;
            departamento->funcionarios = novo;
            departamento->qtd_funcionarios++;
        }
    }
    else return;
}

void exibirFuncionarios(Departamento *departamento, Funcionario *funcionario) {
    if (!funcionario) printf("Não tem funcionários!\n");
    else {
        printf("\nFuncionários do departamento %s\n", departamento->setor);
        while(funcionario) {
            printf("CPF: %s\nNome: %s\nTelefone: %s\nE-mail: %s\nSalário: %.2f\n\n", funcionario->cpf, funcionario->nomeCompleto, funcionario->telefone, funcionario->email, funcionario->salario);
            funcionario = funcionario->prox;
        }
    }
}