/*
Faça um algoritmo para ajudar a dar nomes às
criancinhas recém-nascidas da Polônia. Leia a
quantidade M de crianças e, para cada criança, leia a
quantidade Ni de caracteres que o nome dela deve ter.
Force as seguintes condições M>0 e 3≤Ni≤10 para todo
0≤i<40. Após isso, gere aleatoriamente as Ni
letras do
nome da i-ésima criança. A primeira letra deve ser
maiúscula e as demais minúsculas. Imprima o nome de
cada criança!
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main (){
    int m, n, i, quantidades[m], j, elemento;
    char letra, nomes[m][n], alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    do {
        printf("Informe a quantidade de crianças: ");
        scanf("%d", &m);
    } while (m <= 0);
    for (i = 0; i < m; i++) {
       do {
        printf("Informe a quantidade de caracteres do nome da criança %d: ", i + 1);
        scanf("%d", &n);
        quantidades[i] = n;
    } while (n < 3 || n > 10); 
    }
    srand(time(NULL));
    for (i = 0; i < m; i++) {
        n = quantidades[i];
        for (j = 0; j < n; j++) {
            elemento = rand() % 26;
            letra = alfabeto[elemento];
            if (!(j))
                nomes[i][j] = toupper(letra);
            else 
                nomes[i][j] = letra;
        }
        printf("Nome da criança %d: %s\n", i + 1, nomes[i]);
    }

    
}