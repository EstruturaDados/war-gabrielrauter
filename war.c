#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --------------------------------------------------------
// Estrutura de dados do território
// --------------------------------------------------------
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// --------------------------------------------------------
// Função para cadastrar territórios
// --------------------------------------------------------
void cadastrarTerritorios(Territorio* mapa, int total) {
    printf("=== Cadastro de Territorios ===\n");

    for (int i = 0; i < total; i++) {
        printf("\n--- Territorio %d ---\n", i + 1);

        printf("Nome do territorio: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf(" %[^\n]", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// --------------------------------------------------------
// Exibir territórios cadastrados
// --------------------------------------------------------
void exibirTerritorios(Territorio* mapa, int total) {
    printf("\n\n=== Territorios Cadastrados ===\n");
    for (int i = 0; i < total; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do exercito: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

// --------------------------------------------------------
// Função de ataque entre territórios
// --------------------------------------------------------
void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n=== ATAQUE EM ANDAMENTO ===\n");

    // Rolagem de dados (1 a 6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("Dado do atacante (%s): %d\n", atacante->nome, dadoAtacante);
    printf("Dado do defensor  (%s): %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("\n>>> O atacante venceu a batalha!\n");

        // Metade das tropas do atacante tomam o território
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;

        // Troca de controle territorial
        strcpy(defensor->cor, atacante->cor);

        printf("O territorio %s agora pertence ao exército %s!\n",
               defensor->nome, defensor->cor);
        printf("Tropas movidas para o território conquistado: %d\n",
               defensor->tropas);

    } else {
        printf("\n>>> O defensor venceu a batalha!\n");

        // Atacante perde 1 tropa
        if (atacante->tropas > 0) {
            atacante->tropas -= 1;
            printf("O atacante perdeu 1 tropa. Tropas restantes: %d\n", atacante->tropas);
        }
    }
}

// --------------------------------------------------------
// Liberar memória
// --------------------------------------------------------
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

// --------------------------------------------------------
// Função principal
// --------------------------------------------------------
int main() {
    srand(time(NULL)); // Garante aleatoriedade

    int total;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &total);

    // Alocação dinâmica de memória para os territórios
    Territorio* mapa = (Territorio*)malloc(total * sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro inicial
    cadastrarTerritorios(mapa, total);
    exibirTerritorios(mapa, total);

    int opcao;

    // Loop de ações
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Realizar ataque\n");
        printf("2 - Exibir territorios\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int a, d;

            printf("\nEscolha o numero do territorio atacante: ");
            scanf("%d", &a);

            printf("Escolha o numero do territorio defensor : ");
            scanf("%d", &d);

            // Validando índices
            if (a < 1 || a > total || d < 1 || d > total) {
                printf("Opcao invalida!\n");
                continue;
            }

            // Ajustando índices (0-based)
            a--; d--;

            // Validar se são da mesma cor
            if (strcmp(mapa[a].cor, mapa[d].cor) == 0) {
                printf("Erro: voce nao pode atacar um territorio da mesma cor!\n");
                continue;
            }

            atacar(&mapa[a], &mapa[d]);
        }

        else if (opcao == 2) {
            exibirTerritorios(mapa, total);
        }

    } while (opcao != 0);

    liberarMemoria(mapa);
    printf("Memoria liberada. Encerrando o programa...\n");

    return 0;
}