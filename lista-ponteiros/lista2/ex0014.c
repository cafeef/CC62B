#include<stdio.h>
#include <stdlib.h>

int main () {
    int y, x=3, k=5, *p, *q; //inicializa as variaveis y, x e k. bem como ponteiros p e q
    p = &x; //define que p aponta para x
    q = (int *)malloc(6 * sizeof(int)); //define q um vetor dinâmico
    for (y = 0; y < 3; y++) { //inicia um laço de repetição tendo como y um incrementador que para quando y chega a 2
        p--; //faz p olhar para uma posição anterior, subtraindo  bytes do endereço de memória. acesso ilegal.
        scanf("%d", p); //edita o conteúdo que p aponta. escrita ilegal.
        p++; //p aumenta em 4 bytes e volta a olhar para x.
        scanf("%d", p); //edita o conteúdo de x.
        *q = k; //a primeira posição do vetor passa a ser k
        *(q+1) = x; //a segunda posição do vetor passa a ser x.
        q = q + 2; //o ponteiro do vetor pula 2 posições.
    } //esse procedimento se repete até y = 2. ou seja, repete 3 vezes.
}