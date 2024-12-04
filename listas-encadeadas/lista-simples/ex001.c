#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct No {
    int chave;
    struct No *prox;
} TNo;

int alocaK(int *k);
TNo *alocaNo(int k);
void InsereLista(TNo **lista, int k);
void InsereListaFinal(TNo **lista, int k);
void imprimeLista(TNo *lista);
TNo *buscar(TNo *lista, int k);
int valor_max(TNo *lista);
int valor_min(TNo *lista);
int soma(TNo *lista);
int tamanho(TNo *lista);
int frequencia(TNo *lista, int k);
void removeLista(TNo **lista, int k);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    TNo *lista = NULL, *endereco = NULL;
    int op = 0, k = 0;
    while (op != 11) {
        printf("\nEscolha uma das opções abaixo:\n1 - Inserir no começo\n2 - Inserir no final\n3 - Imprimir lista\n4 - Buscar elemento na lista\n5 - Valor máximo da lista\n6 - Valor mínimo da lista\n7 - Soma dos elementos\n8 - Tamanho da lista\n9 - Frequência de um elemento na lista\n10 - Remover um elemento da lista\n11 - Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                alocaK(&k);
                InsereLista(&lista, k);
                break;
            case 2:
                alocaK(&k);
                InsereListaFinal(&lista, k);
                break;
            case 3:
                printf("Lista: ");
                imprimeLista(lista);
                Sleep(5000);
                break;
            case 4:
                alocaK(&k);
                endereco = buscar(lista, k);
                if(!endereco) printf("Elemento não encontrado na lista.\n");
                else printf("Endereço de %d: %p", k, endereco);
                Sleep(5000);
                break;
            case 5:
                printf("O valor máximo é: %d\n", valor_max(lista));
                Sleep(5000);
                break;
            case 6:
                printf("O valor mínimo é: %d\n", valor_min(lista));
                Sleep(5000);
                break;
            case 7:
                if (!soma(lista)) printf("Lista vazia!\n");
                else printf("A soma dos elementos é: %d\n", soma(lista));
                Sleep(5000);
                break;
            case 8:
                if (!tamanho(lista)) printf("Lista vazia!");
                else printf("O tamanho da lista é: %d\n", tamanho(lista));
                Sleep(5000);
                break;
            case 9:
                alocaK(&k);
                if (!frequencia(lista, k)) printf("Elemento não está na lista!\n");
                else printf("A frequência do elemento na lista é: %d\n", frequencia(lista, k));
                Sleep(5000);
                break;
            case 10:
                alocaK(&k);
                removeLista(&lista, k);
                break;
            case 11:
                printf("Encerrando o programa...\n");
                free(lista);
                lista = NULL;
                printf("Programa encerrado.\n");
                exit(1);
            default:
                printf("Opção inválida, digite novamente.\n");
                break;
        }
        system("cls");
    }
}

int alocaK(int *k) {
    printf("Informe o elemento: ");
    scanf("%d", k);
}

TNo *alocaNo(int k) {
    TNo *novo = NULL;
    novo = (TNo *) malloc(sizeof(TNo));
    if (!novo) return NULL;
    novo->chave = k;
    novo->prox = NULL;
    return novo;
}

void InsereLista(TNo **lista, int k) {
    TNo *novo = alocaNo(k);
    if (novo) {
        novo->prox = *lista;
        *lista = novo;
    }
}

void InsereListaFinal(TNo **lista, int k) {
    TNo *novo = alocaNo(k);
    if (!(*lista)) {
        InsereLista(lista, k);
        return;
    }
    if (novo) {
        TNo *aux = *lista;
        while (aux->prox != NULL) 
            aux = aux->prox;
        aux->prox = novo;
    }
}

void imprimeLista(TNo *lista) {
    while (lista) {
        printf("%d ", lista->chave);
        lista = lista->prox;
    }
}

TNo *buscar(TNo *lista, int k) {
    while (lista) {
        if (lista->chave == k) 
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

int valor_max(TNo *lista) {
    int maior = 0;
    while(lista) {
        if ((lista->chave) > maior)
            maior = lista->chave;
        lista = lista->prox;
    }
    return maior;
}

int valor_min(TNo *lista) {
    int menor = 1000;
    while(lista) {
        if ((lista->chave) < menor)
            menor = lista->chave;
        lista = lista->prox;
    }
    return menor;
}

int soma(TNo *lista) {
    int soma = 0;
    while(lista) {
        soma += lista->chave;
        lista = lista->prox;
    }
    return soma;
}

int tamanho(TNo *lista) {
    int tamanho = 0;
    while(lista) {
        tamanho += 1;
        lista = lista->prox;
    }
    return tamanho;
}

int frequencia(TNo *lista, int k) {
    int frequencia = 0;
    while (lista) {
        if (lista->chave == k) 
            frequencia++;
        lista = lista->prox;
    }
    return frequencia;
}

void removeLista(TNo **lista, int k) {
    TNo *endereco = buscar(*lista, k);
    TNo *aux = *lista;
    if (!endereco)
        printf("\nElemento não está na lista");
    else {
        if (aux == endereco)
            aux = endereco->prox;
        else {
            TNo *anterior = *lista; 
            while (anterior->prox != endereco) {
                anterior = anterior->prox; // Encontrar o nó anterior
            }
            anterior->prox = endereco->prox; // Ajustar ponteiro
            free(endereco); // Desalocar memória do nó removido
        }
    }
}