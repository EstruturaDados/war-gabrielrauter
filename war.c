#include <stdio.h>
#include <string.h>

// --------------------------------------
// Estrutura de dados para representar um território
// --------------------------------------
struct Territorio {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército que o domina
    int tropas;      // Quantidade de tropas no território
};

int main() {
    // Vetor que armazenará até 5 territórios
    struct Territorio territorios[5];

    printf("=== Cadastro de Territorios ===\n");

    // --------------------------------------
    // Entrada de dados dos 5 territórios
    // --------------------------------------
    for (int i = 0; i < 5; i++) {
        printf("\n--- Territorio %d ---\n", i + 1);

        printf("Nome do territorio: ");
        scanf(" %[^\n]", territorios[i].nome); // Lê até a quebra de linha

        printf("Cor do exercito: ");
        scanf(" %[^\n]", territorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // --------------------------------------
    // Exibição dos dados cadastrados
    // --------------------------------------
    printf("\n\n=== Territorios Cadastrados ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    printf("\nCadastro concluido com sucesso!\n");

    return 0;
}
