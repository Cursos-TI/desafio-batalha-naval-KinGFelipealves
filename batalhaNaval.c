#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3 // Valor que representa um navio no tabuleiro

// Função para imprimir o tabuleiro formatado
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

// Função para verificar se uma posição está livre
int estaLivre(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Função para posicionar um navio horizontal ou vertical
int posicionarNavioHV(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        // Validação de limite horizontal
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++)
            if (!estaLivre(tabuleiro, linha, coluna + i)) return 0;

        // Posiciona o navio
        for (int i = 0; i < TAM_NAVIO; i++)
            tabuleiro[linha][coluna + i] = NAVIO;

    } else if (direcao == 'V') {
        // Validação de limite vertical
        if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++)
            if (!estaLivre(tabuleiro, linha + i, coluna)) return 0;

        // Posiciona o navio
        for (int i = 0; i < TAM_NAVIO; i++)
            tabuleiro[linha + i][coluna] = NAVIO;
    } else {
        return 0; // Direção inválida
    }

    return 1; // Sucesso
}

// Função para posicionar navio diagonal
int posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'D') {
        // Diagonal ↘ (linha++, coluna++)
        if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO)
            return 0;

        for (int i = 0; i < TAM_NAVIO; i++)
            if (!estaLivre(tabuleiro, linha + i, coluna + i)) return 0;

        for (int i = 0; i < TAM_NAVIO; i++)
            tabuleiro[linha + i][coluna + i] = NAVIO;

    } else if (direcao == 'E') {
        // Diagonal ↙ (linha++, coluna--)
        if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - (TAM_NAVIO - 1) < 0)
            return 0;

        for (int i = 0; i < TAM_NAVIO; i++)
            if (!estaLivre(tabuleiro, linha + i, coluna - i)) return 0;

        for (int i = 0; i < TAM_NAVIO; i++)
            tabuleiro[linha + i][coluna - i] = NAVIO;

    } else {
        return 0; // Direção inválida
    }

    return 1; // Sucesso
}

int main() {
    // 1. Inicializa tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // 2. Posiciona dois navios horizontais ou verticais
    if (!posicionarNavioHV(tabuleiro, 2, 1, 'H')) {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }

    if (!posicionarNavioHV(tabuleiro, 5, 5, 'V')) {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }

    // 3. Posiciona dois navios diagonais
    if (!posicionarNavioDiagonal(tabuleiro, 6, 0, 'D')) {
        printf("Erro ao posicionar navio diagonal ↘.\n");
        return 1;
    }

    if (!posicionarNavioDiagonal(tabuleiro, 0, 9, 'E')) {
        printf("Erro ao posicionar navio diagonal ↙.\n");
        return 1;
    }

    // 4. Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
