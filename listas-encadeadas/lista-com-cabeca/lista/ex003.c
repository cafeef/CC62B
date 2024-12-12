#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Data {
    int dia;
    int mes;
} TData;

typedef struct Contato {
    char nome[45];
    char telefone[12];
    TData dataAniversario;
    struct Contato *prox;
} TContato;

typedef struct Agenda {
    int qnt_contatos;
    TContato *contatos;
} TAgenda;

TAgenda *criaagenda();
TContato *alocaContato();
void AdicionaContato(TAgenda *lista);
void imprimirContatos(TContato *contato);
void buscarContatos(TContato *contato);
void removerContato(TAgenda *lista, TContato *contato);
void removerTodos(TAgenda *lista, TContato *contato);

int main() {
    int op;
    SetConsoleOutputCP(CP_UTF8);
    TAgenda *agenda = criaagenda();
    while(op != 6) {
        printf("\nInforme a opção:\n1 - Adicionar novo contato\n2 - Exibir contatos\n3 - Pesquisar contato\n4 - Remover contato\n5 - Apagar todos os registros\n6 - Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                AdicionaContato(agenda);
                break;
            case 2:
                imprimirContatos(agenda->contatos);
                break;
            case 3: 
                buscarContatos(agenda->contatos);
                break;
            case 4:
                removerContato(agenda, agenda->contatos); 
                break;
            case 5:
                removerTodos(agenda, agenda->contatos);
                break;
            case 6:
                removerTodos(agenda, agenda->contatos);
                free(agenda);
                agenda = NULL;
                break;
        }
    }
}

TAgenda *criaagenda() {
    TAgenda *novo = (TAgenda *) malloc(sizeof(TAgenda));
    if (novo) {
        novo->qnt_contatos = 0;
        novo->contatos = NULL;
        return novo;
    }
    else return NULL;
}

TContato *alocaContato() {

    TContato *novo = (TContato *) malloc(sizeof(TContato));
    if (novo) {
        char nome[45], telefone[12];
        int dia, mes;
        printf("Informe nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", nome);
        setbuf(stdin, NULL);
        printf("Informe telefone: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", telefone);
        setbuf(stdin, NULL);
        printf("Informe dia do aniversário: ");
        scanf("%d", &dia);
        printf("Informe mês do aniversário: ");
        scanf("%d", &mes);
        strcpy(novo->nome, nome);
        strcpy(novo->telefone, telefone);
        novo->dataAniversario.dia = dia;
        novo->dataAniversario.mes = mes;
        novo->prox = NULL;
        return novo;
    }
    else return NULL;
}

void AdicionaContato(TAgenda *lista) {
    TContato *novo = alocaContato();
    if (novo) {
        if (!lista->contatos) {
            lista->contatos = novo;
            lista->qnt_contatos++;
        }
        else {
            novo->prox = lista->contatos;
            lista->contatos = novo;
            lista->qnt_contatos++;
        }
    }
}

void imprimirContatos(TContato *contato) {
    if (contato) {
        while(contato) {
            printf("\nNome: %s\nTelefone: %s\nAniversário: %d/%d\n", contato->nome, contato->telefone, contato->dataAniversario.dia, contato->dataAniversario.mes);
            contato = contato->prox;
        }
    }
    else printf("\nAgenda vazia!\n");
}

void buscarContatos(TContato *contato) {
    if (contato) {
        char nome_busca[45];
        printf("Informe o nome que deseja buscar: ");
        scanf("%s", nome_busca);
        while(contato) {
            if (!strcmp(contato->nome, nome_busca)) {
                printf("\nNome: %s\nTelefone: %s\nAniversário: %d/%d\n", contato->nome, contato->telefone, contato->dataAniversario.dia, contato->dataAniversario.mes);
                break;
            }
            else
            contato = contato->prox;
        }
        if (!contato) printf("\nContato não encontrado!\n");
    }
    else printf("\nAgenda vazia!\n");
}

void removerContato(TAgenda *lista, TContato *contato) {
    TContato *aux = contato, *anterior = contato;
    if (contato) {
        char nome_remove[45];
        printf("Informe o nome que deseja remover: ");
        scanf("%s", nome_remove);
        while(aux) {
            if (!strcmp(aux->nome, nome_remove))
                break;
            else
                aux = aux->prox;
        }
        if (aux) {
            if (!strcmp(aux->nome, lista->contatos->nome))
                lista->contatos = aux->prox;
            else {
                while (strcmp(anterior->prox->nome, aux->nome))
                    anterior = anterior->prox;
                anterior->prox = aux->prox;
                
            }
            free(aux);
            aux = NULL;
            lista->qnt_contatos--;
            anterior = NULL;
        }
        else printf("\nContato não encontrado!\n");
    }
    else printf("\nAgenda vazia!\n");
}

void removerTodos(TAgenda *lista, TContato *contato) {
    TContato *aux = contato;
    if (lista->contatos) {
        while(lista->contatos) {
            lista->contatos = aux->prox;
            free(aux);
            lista->contatos = lista->contatos->prox;
        }
        lista->qnt_contatos = 0;
    }
    else printf("\nAgenda vazia!\n");
}