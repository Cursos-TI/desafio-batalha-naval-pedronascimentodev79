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

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas pré-definidas para os navios
    int linhaNavioH = 2, colunaNavioH = 4; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 1; // Navio vertical

    // Verifica e posiciona navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linhaNavioH, colunaNavioH)) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioH, colunaNavioH);
    } else {
        printf("Não foi possível posicionar o navio horizontal nas coordenadas (%d,%d).\n", linhaNavioH, colunaNavioH);
    }

    // Verifica e posiciona navio vertical
    if (podePosicionarVertical(tabuleiro, linhaNavioV, colunaNavioV)) {
        posicionarNavioVertical(tabuleiro, linhaNavioV, colunaNavioV);
    } else {
        printf("Não foi possível posicionar o navio vertical nas coordenadas (%d,%d).\n", linhaNavioV, colunaNavioV);
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
