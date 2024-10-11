/*
Exercício

Criar uma biblioteca que tenha as funções:
1) buscar um caracter em uma string, retornar a posição do caracter na string
2) contar o número de caracteres de uma string
3) concatenar duas strings
*/

#include <stdio.h>
#include "bib.h"
int main() {
	int posicao = 1, op, retorno, quantidade;
	char caractere;
	char string[20], string1[20], string2[20];
	do {
		printf("Escolha uma das opções abaixo:\n1- Buscar caractere em uma palavra\n2-Contar o número de letras\n3 - Concatenar duas palavras\n4 - Sair\n");
		scanf("%d", &op);
		switch (op) {
			case 1: {
				printf("Digite a string que deseja: \n");
				scanf("%s", string);
				printf("Digite o caractere que deseja: \n");
				scanf(" %c", &caractere);
				retorno = buscaCaractere(string, caractere, &posicao);
				if (retorno)
					printf("A palavra contém o caractere indicado e está na posição %d \n", posicao); 
				else
					printf("A palavra não contém o caractere indicado\n");
			} break;
			case 2: {
				printf("Digite a string que deseja: \n");
				scanf("%s", string);
				quantidade = quantidadeCaractere(string);
				printf("A palavra contém %d letras\n", quantidade);
			} break;
			case 3: {
				printf("Digite a primeira string que deseja: \n");
				scanf("%s", string1);
				printf("Digite a segunda string que deseja: \n");
				scanf("%s", string2);
				concatenaString(string1, string2);
			} break;
		}
	}while (op != 4);
	//scanf("%[^\n]", string);
}