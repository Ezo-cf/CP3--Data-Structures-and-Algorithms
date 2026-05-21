#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tipo[12];
    float valor;
    float saldoDepois;
} Operacao;

void exibirMenu(float saldo);
void consultarSaldo(float saldo);
float depositar(float saldo, Operacao historico[], int *total);
float sacar(float saldo, Operacao historico[], int *total);
void extrato(float saldo, Operacao historico[], int total);
void salvarOperacao(Operacao historico[], int *total, char tipo[], float valor, float saldoDepois);
void pausar();
void limparTela();

int main() {
    float saldo = 1000.0;
    int opcao = -1;
    Operacao historico[100];
    int totalOp = 0;

    limparTela();
    printf("\n");
    printf("  ==============================\n");
    printf("   BEM-VINDO AO CAIXA ELETRONICO\n");
    printf("  ==============================\n");
    printf("  Saldo inicial: R$ %.2f\n\n", saldo);
    pausar();

    do {
        limparTela();
        exibirMenu(saldo);
        scanf("%d", &opcao);
        while(getchar() != '\n');

        limparTela();

        switch(opcao) {
            case 1: consultarSaldo(saldo); break;
            case 2: saldo = depositar(saldo, historico, &totalOp); break;
            case 3: saldo = sacar(saldo, historico, &totalOp); break;
            case 4: extrato(saldo, historico, totalOp); break;
            case 0: printf("\nObrigado por usar o caixa. Ate logo!\n\n"); break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n\n");
                pausar();
        }
    } while(opcao != 0);

    return 0;
}

void exibirMenu(float saldo) {
    printf("===== MENU ATM =====\n");
    printf("Saldo atual: R$ %.2f\n", saldo);
    printf("1 - Consultar saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Extrato\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void consultarSaldo(float saldo) {
    printf("\nSeu saldo atual e: R$ %.2f\n\n", saldo);
    pausar();
}

float depositar(float saldo, Operacao historico[], int *total) {
    float valor;
    printf("Digite o valor para deposito: R$ ");
    scanf("%f", &valor);

    if (valor > 0) {
        saldo += valor;
        salvarOperacao(historico, total, "Deposito", valor, saldo);
        printf("\nDeposito realizado com sucesso!\n");
    } else {
        printf("\nValor invalido!\n");
    }

    printf("Saldo atual: R$ %.2f\n\n", saldo);
    pausar();
    return saldo;
}

float sacar(float saldo, Operacao historico[], int *total) {
    float valor;
    printf("Digite o valor para saque: R$ ");
    scanf("%f", &valor);

    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        salvarOperacao(historico, total, "Saque", valor, saldo);
        printf("\nSaque realizado com sucesso!\n");
    } else {
        printf("\nSaldo insuficiente ou valor invalido!\n");
    }

    printf("Saldo atual: R$ %.2f\n\n", saldo);
    pausar();
    return saldo;
}

void extrato(float saldo, Operacao historico[], int total) {
    int i;
    printf("\n===== EXTRATO =====\n");

    if (total == 0) {
        printf("Nenhuma operacao realizada.\n");
    } else {
        for (i = 0; i < total; i++) {
            printf("%d. %s - R$ %.2f | Saldo: R$ %.2f\n",
                   i + 1,
                   historico[i].tipo,
                   historico[i].valor,
                   historico[i].saldoDepois);
        }
    }

    printf("\nSaldo atual: R$ %.2f\n\n", saldo);
    pausar();
}

void salvarOperacao(Operacao historico[], int *total, char tipo[], float valor, float saldoDepois) {
    strcpy(historico[*total].tipo, tipo);
    historico[*total].valor = valor;
    historico[*total].saldoDepois = saldoDepois;
    (*total)++;
}

void pausar() {
    printf("Pressione ENTER para continuar...");
    getchar();
}

void limparTela() {
    system("cls || clear");
}