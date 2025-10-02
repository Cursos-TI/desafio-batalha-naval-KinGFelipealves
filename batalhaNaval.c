#include <stdio.h>
#include <stdlib.h>  // Necessária para abs()

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define NAVIO 3
#define HABILIDADE 5

// Imprime o tabuleiro com os valores numéricos
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("====> Tabuleiro Batalha Naval <====\n\n");
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAM_TABULEIRO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Inicializa uma matriz com zeros
void inicializarMatriz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Gera matriz de Cone apontando para baixo
void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            matriz[i][j] = 1;
        }
    }
}

// Gera matriz de Cruz
void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        matriz[i][centro] = 1;  // Coluna central
        matriz[centro][i] = 1;  // Linha central
    }
}

// Gera matriz de Octaedro (losango)
void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Condição que forma um losango (octaedro em vista frontal)
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int linhaOrigem, int colunaOrigem) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = linhaOrigem - centro + i;
                int colunaTab = colunaOrigem - centro + j;

                // Verifica se está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {

                    // Não sobrescreve navio
                    if (tabuleiro[linhaTab][colunaTab] != NAVIO) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Posiciona navios manualmente
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    // Matrizes das habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa e gera as formas
    inicializarMatriz(cone);
    inicializarMatriz(cruz);
    inicializarMatriz(octaedro);

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone centrado em E5
    aplicarHabilidade(tabuleiro, cruz, 7, 7);      // Cruz centrada em H8
    aplicarHabilidade(tabuleiro, octaedro, 1, 8);  // Octaedro centrado em I2

    // Imprime o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}