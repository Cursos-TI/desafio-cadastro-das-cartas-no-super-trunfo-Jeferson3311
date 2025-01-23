#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARTAS 100

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

void cadastrarCarta(CartaCidade *carta) {
    printf("\n--- Cadastro de Carta ---\n");
    printf("Digite o código da cidade (ex: A01, B02): ");
    scanf("%s", carta->codigo);
    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB da cidade (em bilhões de dólares): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void exibirCarta(const CartaCidade *carta) {
    printf("\n--- Dados da Carta (%s) ---\n", carta->codigo);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de dólares\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontos_turisticos);
}

void exibirCartas(const CartaCidade *cartas, int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhuma carta cadastrada ainda.\n");
    } else {
        printf("\n=== Cartas Cadastradas ===\n");
        for (int i = 0; i < quantidade; i++) {
            exibirCarta(&cartas[i]);
        }
    }
}

int main() {
    CartaCidade cartas[MAX_CARTAS];
    int quantidade = 0;
    int opcao;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar nova carta\n");
        printf("2. Exibir cartas cadastradas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (quantidade < MAX_CARTAS) {
                    cadastrarCarta(&cartas[quantidade]);
                    quantidade++;
                } else {
                    printf("\nLimite de cartas atingido!\n");
                }
                break;
            case 2:
                exibirCartas(cartas, quantidade);
                break;
            case 3:
                printf("\nSaindo do sistema. Até logo!\n");
                exit(0);
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
