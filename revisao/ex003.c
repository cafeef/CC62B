#include <stdio.h>

void incluir(int vcod[], float vsaldo[], int tam);
float verSaldo(int cod, float vsaldo[]);
float fazerDeposito(int cod, float vsaldo[], float valor);
float saque(int cod, float vsaldo[], float valor);

int main() {
    int tam, op = 0;
    printf("Quantos clientes tem em seu banco? ");
    scanf("%d", &tam);
    int vcod[tam];
    float vsaldo[tam];
    while (op != 5) {
        printf("1 para incluir\n2 Deposito\n3 Saque\n4 Saldo\n5 Sair\n");
        scanf("%d", &op);
        switch (op) {
        case 1: {
            incluir(vcod, vsaldo, tam);
            } break;
        case 2: {
            float valor;
            int cod;
            printf("Informe codigo ");
            scanf("%d", &cod);
            printf("Informe valor ");
            scanf("%f", &valor);
            fazerDeposito(cod, vsaldo, valor);
        }
            break;
        case 3: {
            float valor, s;
            int cod;
            printf("Informe codigo ");
            scanf("%d", &cod);
            printf("Informe valor de saque ");
            scanf("%f", &valor);
            s = s = verSaldo(cod, vsaldo);
            if (s > valor) {

            }
            else {
                printf("Saldo insuficiente");
            }
        }
            break;
        case 4: {
            int cod;
            float s;
            printf("Informe código: ");
            scanf("%d", &cod);
            s = verSaldo(cod, vsaldo);
            printf("Cliente %d: %.2f\n", cod, s);
            }
            break;
        case 5: {
            printf("Fim");
        }break;
        default: {
            printf("Opcao invalida!\n"); 
        }break;
        }
    }
    
}

void incluir(int vcod[], float vsaldo[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vcod[i] = i + 1;
        vsaldo[i] = 0;
    }
}

float verSaldo(int cod, float vsaldo[]) {
    return vsaldo[cod - 1];
    
}

float fazerDeposito(int cod, float vsaldo[], float valor) {
    vsaldo[cod - 1] = vsaldo[cod - 1] + valor;

}

float saque(int cod, float vsaldo[], float valor) {
    vsaldo[cod - 1] = vsaldo[cod - 1] - valor;
}