#include<stdio.h>

void incluir(int vcod[], float vsaldo[], int tam);
//void incluir(int *vcod, float *vsaldo, int tam);
float verSaldo(int cod, float vsaldo[]);
void depositar(int cod, float valor, float vsaldo[]);
void saque(int cod, float valor, float vsaldo[]);
int main()
{
    int tam, op=0, ok1 = 0, ok2 = 0, ok3 = 0;
    printf("Informe a quantidade de clientes: ");
    scanf("%d",&tam);
    int codigo1[tam], i, codigo2[tam], codigo3[tam];
    float saldo1[tam], saldo2[tam], saldo3[tam];
    while(op!=5)
    {
        printf("\n1-Incluir\n2-Deposito\n3-Saque\n4-Saldo\n5-Sair\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: {
                int agencia;
                printf("Informe a agencia: ");
                scanf("%d", &agencia);
                if (agencia == 1 && ok1 == 0) {
                    incluir(codigo1, saldo1, tam);
                    ok1 = 1;
                }  
                else {
                    if (agencia == 2 && ok2 == 0) {
                        incluir(codigo2, saldo2, tam);
                        ok2 = 1;
                    }
                    else {
                        if (agencia == 3 && ok3 == 0) {
                            incluir(codigo3, saldo3, tam);
                            ok3 = 1;
                        }
                        else {
                            if (agencia==1 || agencia==2 || agencia==3)
                                printf("Agencia ja incluida");
                            else
                               printf("Agencia nao existe!");
                        }
                    }
                }

            }break;
            case 2:{
                float valor;
                int cod, agencia;
                printf("Informe codigo do cliente: ");
                scanf("%d",&cod);
                printf("Informe valor do deposito: ");
                scanf("%f",&valor);
                printf("Informe a agencia: ");
                scanf("%d", &agencia);
                if (agencia == 1)
                    depositar(cod, valor, saldo1);
                else
                    if (agencia == 2)
                        depositar(cod, valor, saldo2);
                    else
                        if (agencia == 3)
                            depositar(cod, valor, saldo3);
                        else
                            printf("\nAgencia nao existe!");
            }break;
            case 3:{
                float valor, s;
                int cod, agencia;
                printf("Informe codigo do cliente: ");
                scanf("%d",&cod);
                printf("Informe valor do saque: ");
                scanf("%f",&valor);
                printf("Informe a agencia: ");
                scanf("%d", &agencia);
                if (agencia == 1) {
                    s = verSaldo(cod, saldo1);
                    if(s > valor)
                        saque(cod, valor, saldo1);
                    else
                        printf("\nSaldo insuficiente!");
                }
                else {
                    if (agencia == 2) {
                    s = verSaldo(cod, saldo2);
                        if(s > valor)
                            saque(cod, valor, saldo2);
                        else
                            printf("\nSaldo insuficiente!");
                    }
                    else {
                        if (agencia == 3) {
                            s = verSaldo(cod, saldo3);
                            if(s > valor)
                                saque(cod, valor, saldo3);
                            else
                                printf("\nSaldo insuficiente!");
                        }
                        else
                            printf("\nAgencia nao existe!");
                    }
                }
            }break;
            case 4:{
                int cod, agencia;
                float s;
                printf("\nInforme codigo do cliente: ");
                scanf("%d",&cod);
                printf("Informe a agencia: ");
                scanf("%d", &agencia);
                if (agencia == 1) {
                    s = verSaldo(cod, saldo1);
                    printf("Cliente %d: %f",cod, s);
                }
                else {
                    if (agencia == 2) {
                        s = verSaldo(cod, saldo2);
                        printf("Cliente %d: %f",cod, s);
                    }
                    else {
                        if (agencia == 3) {
                            s = verSaldo(cod, saldo3);
                            printf("Cliente %d: %f",cod, s);
                        }
                        else {
                            printf("\nAgencia invalida!");
                        }
                    }
                }

            }break;
            case 5:{
                printf("FIM!");
            }break;
            default: printf("\nOpcao invalida!");
        }
    }

    //for(i=0; i<tam; i++)
       //printf("Cliente %d: %f", codigo[i], saldo[i]);

}

void incluir(int vcod[], float vsaldo[], int tam)
{
   int i;
   for(i=0; i<tam; i++)
    {
        vcod[i] = i+1;//prog controla
        vsaldo[i]=0;
    }
}

float verSaldo(int cod, float vsaldo[])
{
    return vsaldo[cod-1];
}

void depositar(int cod, float valor, float vsaldo[])
{
    vsaldo[cod-1] = vsaldo[cod-1] + valor;
}

void saque(int cod, float valor, float vsaldo[])
{
    vsaldo[cod-1] = vsaldo[cod-1] - valor;
}
