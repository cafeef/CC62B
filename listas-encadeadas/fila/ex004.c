#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct Alunos {
    char nome[10];
    int periodo;
    struct Alunos *prox;
} TAluno;

typedef struct Cabeca {
    int cont;
    TAluno *inicio;
    TAluno *fim;
} TCabeca;

TCabeca *criacabeca();
TAluno *alocaAluno(const char *nome, int periodo);
void InsereAluno(TCabeca *fila, const char *nome, int periodo);
void Imprimir(TAluno *fila);

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    TCabeca *fila = criacabeca();
    InsereAluno(fila, "Fernanda", 2);
    InsereAluno(fila, "Lucas", 2);
    Imprimir(fila->inicio);
}

TCabeca *criacabeca() {
    TCabeca *novo = (TCabeca *) malloc(sizeof(TCabeca));
    if (novo) {
        novo->cont = 0;
        novo->inicio = NULL;
        novo->fim = NULL;
        return novo;
    }
    else return NULL;
}

TAluno *alocaAluno(const char *nome, int periodo) {
    TAluno *novo = (TAluno *) malloc(sizeof(TAluno));
    if (novo) {
        strcpy(novo->nome, nome);
        novo->periodo = periodo;
        novo->prox = NULL;
    }
    else return NULL;
}

void InsereAluno(TCabeca *fila, const char *nome, int periodo) {
    TAluno *novo = alocaAluno(nome, periodo);
    if (novo) {
        if (!fila->inicio) {
            fila->inicio = novo;
            fila->fim = novo;
            fila->cont++;
        }
        else {
            TAluno *aux = fila->fim;
            aux->prox = novo;
            fila->fim = novo;
            fila->cont++;
        }
    }
    else return;
}

void Imprimir(TAluno *fila) {
    if (fila) {
        while (fila) {
            printf("Nome: %s - Período: %d\n", fila->nome, fila->periodo);
            fila = fila->prox;
        }
    }
    else {
        printf("Fila vazia!\n");
        return;
    }
}
