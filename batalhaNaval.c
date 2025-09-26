#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("====> Tabuleiro Batalha Naval <====\n\n");
    printf("   "); // Espaço para alinhar os números das linhas
    
    for (char letra = 'A'; letra < 'A' + TAM_TABULEIRO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        // Imprime número da linha (1 a 10), com alinhamento
        printf("%2d ", i + 1);

        // Imprime o conteúdo da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int linha_horizontal = 2;  
    int coluna_horizontal = 3; 

    int linha_vertical = 5;    
    int coluna_vertical = 7; 

    // 3. Valida posição e sobreposição do navio horizontal
    if (coluna_horizontal + TAM_NAVIO > TAM_TABULEIRO) {
        
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) 
        return 1;
    }

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // 4. Valida posição e sobreposição do navio vertical
    if (linha_vertical + TAM_NAVIO > TAM_TABULEIRO) {
      
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            return 1;
        }
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // 5. Exibe o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}
