#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAM_TABULEIRO; col++) {
        printf("%d ", col); // cabeçalho com índices das colunas
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i); // índice da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == NAVIO) return 0; // Sobreposição
    }
    return 1;
}

// Função para verificar se um navio pode ser posicionado verticalmente
int podePosicionarVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == NAVIO) return 0;
    }
    return 1;
}

// Validação para posicionar navio na diagonal principal (↘)
int podePosicionarDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] == NAVIO) return 0;
    }
    return 1;
}

// Validação para posicionar navio na diagonal secundária (↙)
int podePosicionarDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] == NAVIO) return 0;
    }
    return 1;
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Posicionamento na diagonal principal (↘)
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

// Posicionamento na diagonal secundária (↙)
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // NAVIO HORIZONTAL
    int linhaH = 2, colunaH = 4;
    if (podePosicionarHorizontal(tabuleiro, linhaH, colunaH)) {
        posicionarNavioHorizontal(tabuleiro, linhaH, colunaH);
    } else {
        printf("Erro ao posicionar navio horizontal em (%d,%d)\n", linhaH, colunaH);
    }

    // NAVIO VERTICAL
    int linhaV = 5, colunaV = 1;
    if (podePosicionarVertical(tabuleiro, linhaV, colunaV)) {
        posicionarNavioVertical(tabuleiro, linhaV, colunaV);
    } else {
        printf("Erro ao posicionar navio vertical em (%d,%d)\n", linhaV, colunaV);
    }

    // NAVIO DIAGONAL PRINCIPAL (↘)
    int linhaDP = 0, colunaDP = 0;
    if (podePosicionarDiagonalPrincipal(tabuleiro, linhaDP, colunaDP)) {
        posicionarNavioDiagonalPrincipal(tabuleiro, linhaDP, colunaDP);
    } else {
        printf("Erro ao posicionar navio diagonal principal em (%d,%d)\n", linhaDP, colunaDP);
    }

    // NAVIO DIAGONAL SECUNDÁRIA (↙)
    int linhaDS = 0, colunaDS = 9;
    if (podePosicionarDiagonalSecundaria(tabuleiro, linhaDS, colunaDS)) {
        posicionarNavioDiagonalSecundaria(tabuleiro, linhaDS, colunaDS);
    } else {
        printf("Erro ao posicionar navio diagonal secundária em (%d,%d)\n", linhaDS, colunaDS);
    }

    // Exibe o tabuleiro final
    printf("\n=== TABULEIRO FINAL ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
