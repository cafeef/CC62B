/*1 – Utilizando uma lista circular, crie as funções de inserção, remoção, busca e exibição
de elementos. */

typedef struct No {
    int chave;
    struct No *prox;
} TNo;

int main() {

}

TNo *alocaNo (int k) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    if (novo) {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    else return NULL;
}

void InsereNo(TNo **lista, int k) {
    TNo *novo = alocaNo(k);
    if (novo) {
        (*lista)->prox = novo;
        novo->prox = novo;
    }
}