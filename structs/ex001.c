#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[50];
    int ra;
    int idade;
} TipoAluno;

TipoAluno *aloca(int n);
void alterar(TipoAluno *paluno, int n);
void libera(TipoAluno **p);

int main() {
    TipoAluno *p;
    int n, i;
    printf("Informe número de registros: ");
    scanf("%d", &n);
    p = aloca(n);
    alterar(p, n);
    for (i = 0; i < n; i++)
        printf("\nAluno %s inserido!", (p + i)->nome);
    libera(p);
}

TipoAluno *aloca(int n) {
    TipoAluno *pa;
    pa = (TipoAluno *) malloc(sizeof(TipoAluno) * n);
    if(pa == NULL) return NULL;
    return pa;
}

void alterar(TipoAluno *paluno, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Digite nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", (paluno + i)->nome);
        setbuf(stdin, NULL);
        printf("Digite o RA: ");
        scanf("%d", &((paluno + i)->ra));
        printf("Digite a idade: ");
        scanf("%d", &((paluno + i)->idade));
    }
}

void libera(TipoAluno **p) {
    free(*p);
    *p = NULL;
}