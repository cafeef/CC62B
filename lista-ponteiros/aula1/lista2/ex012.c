/*12. Escrever um procedimento que faça a União de dois vetores dinâmicos (C = A  B). Lembre-se de
liberar a memória dos vetores A e B após a concatenação.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pa, *pb, tamA, i, tamB, *pc, tamC = tamA + tamB, ia, ib;
    printf("Digite o tamanho do vetor A: ");
    scanf("%d", &tamA);
    pa = (int *) malloc(sizeof(int) * tamA);
    for (i = 0; i < tamA; i++) {
        printf("Digite o %d termo: ", i + 1);
        scanf("%d", &(*(pa + i)));
    }
    printf("Digite o tamanho do vetor B: ");
    scanf("%d", &tamB);
    pb = (int *) malloc(sizeof(int) * tamB);
    for (i = 0; i < tamB; i++) {
        printf("Digite o %d termo: ", i + 1);
        scanf("%d", &(*(pb + i)));
    }
    tamC = tamA + tamB;
    pc = (int *) malloc(sizeof(int) * tamC);
    for (i = 0; i < tamC; i++) {
        if (i < tamA) {
            *(pc + i) = *(pa + ia);
            ia++;
        }
        else {
            *(pc + i) = *(pb + ib);
            ib++;
        }
            
    }
        
    for (i = 0; i < tamC; i++)
        printf("%d ", *(pc + i));
    free(pa);
    pa = NULL;
    free(pb);
    pb = NULL;
}