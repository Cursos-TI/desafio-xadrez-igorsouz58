#include <stdio.h>

// Função para simular o movimento da Torre (usa 'for')
void moverTorre(int casas) {
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casas; i++) {
        printf("Casa %d: Movendo para frente (linha)\n", i);
    }
    printf("\n");
}

    // TORRE - Movimento Recursivo
void moverTorreRecursivo(int passo, int max) {
    if (passo > max) {
        printf("\n");
        return;
    }
    printf("Torre - Casa %d: Movendo para frente (linha)\n", passo);
    moverTorreRecursivo(passo + 1, max);
}

// Função para simular o movimento do Bispo (usa 'while')
void moverBispo(int casas) {
    printf("Movimento do Bispo:\n");
    int i = 1;
    while (i <= casas) {
        printf("Casa %d: Movendo na diagonal\n", i);
        i++;
    }
    printf("\n");
}

    // BISPO - Movimento Recursivo com Loops Aninhados
void moverBispoDiagonalRecursivo(int passo, int max) {
    if (passo > max) {
        printf("\n");
        return;
    }

    // Loops aninhados: vertical e horizontal (diagonal)
    for (int v = 1; v <= 1; v++) {
        for (int h = 1; h <= 1; h++) {
            printf("Bispo - Casa %d: Movendo na diagonal (vertical %d, horizontal %d)\n", passo, v, h);
        }
    }

    moverBispoDiagonalRecursivo(passo + 1, max);
}

// Função para simular o movimento da Rainha (usa 'do-while')
void moverRainha(int casas) {
    printf("Movimento da Rainha:\n");
    int i = 1;
    do {
        if (i % 2 == 1)
            printf("Casa %d: Movendo na diagonal\n", i); // Alterna entre movimentos
        else
            printf("Casa %d: Movendo em linha reta\n", i);
        i++;
    } while (i <= casas);
    printf("\n");
}
// RAINHA - Movimento Recursivo Alternado
void moverRainhaRecursivo(int passo, int max) {
    if (passo > max) {
        printf("\n");
        return;
    }
    if (passo % 2 == 1)
        printf("Rainha - Casa %d: Movendo na diagonal\n", passo);
    else
        printf("Rainha - Casa %d: Movendo em linha reta\n", passo);

    moverRainhaRecursivo(passo + 1, max);
}

// ------------------- CAVALO -------------------
void moverCavalo() {
    printf("Movimento do Cavalo (duas casas para cima, uma para direita):\n");

    int movimentosDesejados = 3;
    int movimentosFeitos = 0;

    for (int i = 0; i < 10; i++) { // simula tentativas de movimentos
        for (int j = 0; j < 10; j++) {
            // Condição para simular uma posição válida
            if ((i + j) % 3 == 0) {
                movimentosFeitos++;
                printf("Movimento %d:\n", movimentosFeitos);
                int passo = 1;

                while (passo <= 2) {
                    printf("  Passo %d: Movendo uma casa para cima\n", passo);
                    passo++;
                }

                printf("  Passo 3: Movendo uma casa para a direita\n");

                if (movimentosFeitos >= movimentosDesejados)
                    break;
            } else {
                continue; // ignora posições inválidas
            }
        }
        if (movimentosFeitos >= movimentosDesejados)
            break;
    }
    printf("\n");
}

// ------------------- MAIN -------------------
int main() {
    int casas = 5; // número de passos a serem simulados para Torre, Bispo e Rainha

    printf("=== Simulação de Movimentos de Peças de Xadrez ===\n\n");

    moverTorreRecursivo(1, casas);
    moverBispoDiagonalRecursivo(1, casas);
    moverRainhaRecursivo(1, casas);
    moverCavalo();

    return 0;
}