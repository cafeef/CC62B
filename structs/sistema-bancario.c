#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
    int numero;
    float saldo;
} ContaBancaria;

ContaBancaria *inicializa();
void deposita(ContaBancaria *p);
void saque(ContaBancaria *p);
void saldo(ContaBancaria *p);
void libera(ContaBancaria **p);

int main() {
    int op = 0;
    ContaBancaria *p = NULL;
    printf("Bem vindo ao sistema banc�rio!\n");
    do {
        printf("Escolha uma das op��es abaixo:\n1 - Iniciar\n2 - Depositar\n3 - Sacar\n4 - Saldo\n5 - Sair\n");
        scanf("%d", &op);
        switch (op) {
        case 1: {
            p = inicializa();
        } break;
        case 2: {
            if (p == NULL) {
                printf("N�o � poss�vel depositar sem uma conta inicializada. Inicie sua conta primeiro.\n");
                break;
            } 
            else
                deposita(p);
        } break;
        case 3: {
            if (p == NULL) {
                printf("N�o � poss�vel sacar sem uma conta inicializada. Inicie sua conta primeiro.\n");
                break;
            }
            else
                saque(p); 
        } break;
        case 4: {
            if (p == NULL) {
                printf("N�o � poss�vel ver saldo sem uma conta inicializada. Inicie sua conta primeiro.\n");
                break;
            }
            else
                saldo(p);
        } break;
        case 5: {
            printf("Encerrando...\n");
            libera(&p);
        } break;   
        default: {
            printf("Op��o inv�lida, digite novamente!\n");
        }
            
    }
    } while (op != 5);
    
}

ContaBancaria *inicializa() {
    ContaBancaria *p;
    p = (ContaBancaria *) malloc(sizeof(ContaBancaria));
    p->numero = 0;
    p->saldo = 0;
    if (p == NULL) 
        return NULL;
    else 
        return p;
}

void deposita(ContaBancaria *p) {
    float valor;
    printf("Informe valor: ");
    scanf("%f", &valor);
    p->saldo = p->saldo + valor;
    printf("Dep�sito realizado.\n");
}

void saque(ContaBancaria *p) {
    float valor;
    printf("Informe valor: ");
    scanf("%f", &valor);
    if (p->saldo < valor)
        printf("N�o � poss�vel realizar o saque, saldo insuficiente.\n");
    else {
        p->saldo = p->saldo - valor;
        printf("Saque realizado.\n");
    }
}

void saldo(ContaBancaria *p) {
    printf("Seu saldo �: %f\n", p->saldo);
}

void libera(ContaBancaria **p) {
    free(p);
    *p = NULL;
}