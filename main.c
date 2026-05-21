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