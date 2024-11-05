#include <stdlib.h>
#include <stdio.h>

typedef struct livro {
    int codigo;
    char nome[20], autor[15];
    int status, num_reservas, num_total;
} TLivro;

int main() {
    FILE *arq;
    int i, num_linhas;
    arq = fopen("livros.txt", "r");
    if (!arq)
        printf("Arquivo não aberto");
    printf("Arquivo aberto\n");
    fscanf(arq, "%d", &num_linhas);
    if(num_linhas == 5)
        printf("Sucesso\n");
    
}