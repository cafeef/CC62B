#include <stdio.h>
#include "bib.h"
int buscaCaractere(char string[], char caractere, int *posicao) {
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] == caractere) {
			*posicao = i + 1;
			return 1;
		}
	}
	return 0;
}

int quantidadeCaractere(char string[]) {
	int quantidade = 0;
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		quantidade = quantidade + 1;
	}
	return quantidade;
}

void concatenaString(char string1[], char string2[]) {
	int i, i1;
	char string3[40];
	for (i = 0; string1[i] != '\0'; i++)
		string3[i] = string1[i];
	for (i1 = 0; string2[i1] != '\0'; i++, i1++)
		string3[i] = string2[i1];
	string3[i] = '\0';
	printf("As duas palavras concatenadas é:\n");
	for (i = 0; string3[i] != '\0'; i++)
		printf("%c", string3[i]);
	printf("\n");
}