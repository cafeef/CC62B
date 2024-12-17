/*adicionar documento na fila, mandar imprimir o
próximo documento (ou seja, retirar da fila), mostrar documentos enfileirados, e cancelar
a impressão de um documento específico.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct Documento {
    char nome[30];
    char extensao[5];
    int tamanho; // bytes
    int imprimirColorido; // 1-verdadeiro, 0-falso
    struct Documento *prox;
} TDocumento;

TDocumento *alocaDocumento (const char *nome, const char *extensao, int tamanho, int imprimirColorido);
void AdicionarDocumento(TDocumento **fila);
void ImprimirProximo(TDocumento **fila);
void ImprimirDocumento(TDocumento *fila);
void RemoverDocumento(TDocumento **fila);


int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    TDocumento *fila = NULL;
    int op = 0;
    while(op != 5) {
        printf("\nEscolha uma opção: \n1 - Adicionar documento na fila\n2 - Imprimir próximo documento\n3 - Mostrar documentos na fila\n4 - Remover um documento da fila\n5 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            AdicionarDocumento(&fila);
            break;
        case 2:
            ImprimirProximo(&fila);
            break;
        case 3:
            ImprimirDocumento(fila);
            break;
        case 4:
            RemoverDocumento(&fila);
            break;
        case 5:
            printf("Encerrando programa...\n");
            exit(1);
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

TDocumento *alocaDocumento (const char *nome, const char *extensao, int tamanho, int imprimirColorido) {
    TDocumento *novo = (TDocumento *) malloc(sizeof(TDocumento));
    if (novo) {
        strcpy(novo->nome, nome);
        strcpy(novo->extensao, extensao);
        novo->tamanho = tamanho;
        novo->imprimirColorido = imprimirColorido;
        novo->prox = NULL;
        return novo;
    }
    else return NULL;
}

void AdicionarDocumento(TDocumento **fila) {
    int op = 0, tamanho = 0, imprimirColorido = 0;
    char nome[30], extensao[5];
    printf("Informe nome: ");
    scanf("%s", nome);
    printf("Informe extensão do documento: ");
    scanf("%s", extensao);
    printf("Informe tamanho: ");
    scanf("%d", &tamanho);
    printf("Imprimir em colorido? [1 - SIM || 0 - NÃO]: ");
    scanf("%d", &tamanho);
    TDocumento *novo = alocaDocumento(nome, extensao, tamanho, imprimirColorido);
    if (novo) {
        if (!*fila) {
            (*fila) = novo;
        }
        else {
            TDocumento *aux = *fila;
            while (aux->prox) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    else {
        printf("Erro em adicionar o documento.\n");
        return;
    }
}

void ImprimirProximo(TDocumento **fila) {
    TDocumento *aux = *fila;
    if (*fila) {
        *fila = (*fila)->prox;
    }
    else {
        printf("Fila de impressão vazia!\n");
    }
    free(aux);
    aux = NULL;
}

void ImprimirDocumento(TDocumento *fila) {
    int i = 1;
    if (fila) {
        while (fila) {
            printf("%d: %s.%s\n", i, fila->nome, fila->extensao);
            fila = fila->prox;
            i++;
        }
    }
    else printf("Fila de impressão vazia!\n");
}

void RemoverDocumento(TDocumento **fila) {
    if (*fila) {
        TDocumento *aux = *fila;
        TDocumento *ant = NULL;
        char nome[30];
        printf("Informe nome do documento: ");
        scanf("%s", nome);
        if (!strcmp((*fila)->nome, aux->nome))
            ImprimirProximo(fila);
        else {
            while(aux) {
            if(!strcmp(aux->nome, nome)) {
                ant->prox = aux->prox;
                free(aux);
                aux = NULL;
                break;
            }
            else {
                ant = aux;
                aux = aux->prox;
            }
        }
        if (!aux) printf("Documento não está na fila!\n");
        }
        
    }
    else {
        printf("Fila de impressão vazia!\n");
        return;
    }
    
}