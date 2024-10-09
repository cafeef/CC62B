#include <stdio.h>
#include "meu-banco.h"

int main() {
    int op = 0, tam;
    int vcod1[tam], vcod2[tam], vcod3[tam], num_agencia, ok1 = 0, ok2 = 0, ok3 = 0;
    float vsaldo1[tam], vsaldo2[tam], vsaldo3[tam];
    do {
        printf("Escolha entre uma das opções abaixo o que deseja fazer.\n1 - Incluir\n2 - Depósito\n3 - Saque\n4 - Ver saldo\n5 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1: 
            printf("Qual o número da agência? ");
            scanf("%d", &num_agencia);
            if (num_agencia == 1 && ok1 == 0) {
                printf("Qual sua quantidade de clientes? ");
                scanf("%d", &tam);
                incluir(vcod1, vsaldo1, tam);
                ok1 = 1;
            }
            else if (num_agencia == 2 && ok2 == 0) {
                printf("Qual sua quantidade de clientes? ");
                scanf("%d", &tam);
                incluir(vcod2, vsaldo2, tam);
                ok2 = 1;
            }
            else if (num_agencia == 3 && ok3 == 0) {
                printf("Qual sua quantidade de clientes? ");
                scanf("%d", &tam);
                incluir(vcod3, vsaldo3, tam);
                ok3 = 1;
            }
            else if (num_agencia == 1 || num_agencia == 2 || num_agencia == 3)
                printf("Agência já incluída!\n");
                else
                printf("Agência inválida!\n");
            break;
        case 2: {
            int cod_cliente;
            float valor;
            printf("Qual o número da agência? ");
            scanf("%d", &num_agencia);
            if (num_agencia == 1) {
                printf("Qual é o código do cliente? ");
                scanf("%d", &cod_cliente);
                printf("Qual é o valor? ");
                scanf("%f", &valor);
                deposito(cod_cliente, vsaldo1, valor);
            }
            else if (num_agencia == 2) {
                printf("Qual é o código do cliente? ");
                scanf("%d", &cod_cliente);
                printf("Qual é o valor? ");
                scanf("%f", &valor);
                deposito(cod_cliente, vsaldo2, valor);
            }
            else if (num_agencia == 3) {
                printf("Qual é o código do cliente? ");
                scanf("%d", &cod_cliente);
                printf("Qual é o valor? ");
                scanf("%f", &valor);
                deposito(cod_cliente, vsaldo3, valor);
            }
            else
                printf("Agência não existe!");
        } break;
        case 3: {
            int cod_cliente;
            float valor, s;
            printf("Qual o número da agência? ");
            scanf("%d", &num_agencia);
            if (num_agencia == 1) {
                printf("Qual é o código do cliente? ");
                scanf("%d", &cod_cliente);
                printf("Qual é o valor? ");
                scanf("%f", &valor);
                s = versaldo(cod_cliente, vsaldo1);
                if (s < valor)
                    printf("Saldo insuficiente!\n");
                else 
                    saque(cod_cliente, vsaldo1, valor);
            }
            else if (num_agencia == 2) {
                printf("Qual é o código do cliente? ");
                scanf("%d", &cod_cliente);
                printf("Qual é o valor? ");
                scanf("%f", &valor);
                s = versaldo(cod_cliente, vsaldo2);
                if (s < valor)
                    printf("Saldo insuficiente!\n");
                else 
                    saque(cod_cliente, vsaldo2, valor);
            }
            else if (num_agencia == 3) {
                printf("Qual é o código do cliente? ");
                scanf("%d", &cod_cliente);
                printf("Qual é o valor? ");
                scanf("%f", &valor);
                s = versaldo(cod_cliente, vsaldo3);
                if (s < valor)
                    printf("Saldo insuficiente!\n");
                else 
                    saque(cod_cliente, vsaldo3, valor);
            }
            else
                printf("Agência não existe!");
        }break;
        case 4: {
            int cod_cliente;
            float s;
            printf("Qual é o código do cliente? ");
            scanf("%d", &cod_cliente);
            printf("Qual o número da agência? ");
            scanf("%d", &num_agencia);
            if (num_agencia == 1) {
                s = versaldo(cod_cliente, vsaldo1);
                printf("Saldo cliente %d: %f\n", cod_cliente, s);
            }
            else if (num_agencia == 2) {
                s = versaldo(cod_cliente, vsaldo2);
                printf("Saldo cliente %d: %f\n", cod_cliente, s);
            }
            else if (num_agencia == 3) {
                s = versaldo(cod_cliente, vsaldo3);
                printf("Saldo cliente %d: %f\n", cod_cliente, s);
            }
        }break;
        case 5: {
            printf("FIM!");
        }break;
        default: printf("Opção inválida!\n");
        }
        
    } while (op != 5);
    
}

void incluir(int vcod[], float vsaldo[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vcod[i] = i + 1;
        vsaldo[i] = 0;
    }  
}

void deposito(int cod_cliente, float vsaldo[], float valor) {
    vsaldo[cod_cliente - 1] = vsaldo[cod_cliente - 1] + valor;
}

void saque(int cod_cliente, float vsaldo[], float valor) {
    vsaldo[cod_cliente - 1] = vsaldo[cod_cliente - 1]  - valor;
}

float versaldo(int cod_cliente, float vsaldo[]) {
    return vsaldo[cod_cliente - 1];
}