#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct Idades {
    int idade;
    struct Idades *prox;
} TIdade;

TIdade *alocaIdade(int idade);
void InserirIdade(TIdade **lista, int idade);
void ImprimirFila(TIdade *lista);
void RemoverFila(TIdade **lista, int idade);
void OrdenarIdade(TIdade **lista, TIdade **fila_preferencial);
void JuntarListas(TIdade **preferencial, TIdade **normal);

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    TIdade *fila = NULL, *fila_preferencial = NULL;
    InserirIdade(&fila, 30);
    InserirIdade(&fila, 40);
    InserirIdade(&fila, 32);
    InserirIdade(&fila, 78);
    OrdenarIdade(&fila, &fila_preferencial);
    ImprimirFila(fila_preferencial);
    ImprimirFila(fila);
    JuntarListas(&fila_preferencial, &fila);
    ImprimirFila(fila_preferencial);
}

TIdade *alocaIdade(int idade) {
    TIdade *novo = (TIdade *) malloc(sizeof(TIdade));
    if (novo) {
        novo->idade = idade;
        novo->prox = NULL;
        return novo;
    }
    else return NULL;
}

void InserirIdade(TIdade **lista, int idade) {
    TIdade *novo = alocaIdade(idade);
    TIdade *aux = *lista;
    if (novo) {
        if (!*lista) {
            (*lista) = novo;
        }
        else {
            while(aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    else return;
}

void RemoverFila(TIdade **lista, int idade) {
    TIdade *aux = *lista;
    TIdade *ant = NULL;
    if (*lista) {
        if ((*lista)->idade == idade) {
            *lista = (*lista)->prox;
            free(aux);
            aux = NULL;
        }
        else {
            while(aux) {
                if (aux->idade == idade) {
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
        }
    }
    else {
        printf("Lista vazia!\n");
    }
}

void ImprimirFila(TIdade *lista) {
    if (lista) {
        while (lista) {
            printf("%d ", lista->idade);
            lista = lista->prox;
        }
        printf("\n");
    }
    else printf("Fila vazia!\n");
}

void OrdenarIdade(TIdade **lista, TIdade **fila_preferencial) {
    TIdade *aux = *lista;
    TIdade *anterior = NULL;
    while(aux) {
        if (aux->idade >= 60) {
            // Adiciona na fila preferencial
            InserirIdade(fila_preferencial, aux->idade);

            // Remove da lista original
            if (anterior == NULL) {
                // Caso especial: removendo o primeiro elemento
                *lista = aux->prox;
            } else {
                anterior->prox = aux->prox;
            }

            // Libera o nó atual e ajusta o ponteiro
            TIdade *remover = aux;
            aux = aux->prox;
            free(remover);
        } else {
            // Avança os ponteiros apenas se nenhum elemento foi removido
            anterior = aux;
            aux = aux->prox;
        }    
    }
}

void JuntarListas(TIdade **preferencial, TIdade **normal) {
    if (!*preferencial) {
        *preferencial = *normal;
    }
    else {
        TIdade *aux = *preferencial;
        while(aux->prox) {
            aux = aux->prox;
        }
        aux->prox = *normal;
        *normal = NULL;
    }
}
