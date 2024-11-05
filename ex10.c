#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

void inicializarTabuleiro(int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]);
void exibirTabuleiro(int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]);
int movimentoValido(int linha, int coluna, int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]);
void realizarMovimento(int linha, int coluna, int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]);
int verificarFimDeJogo(int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]);
void jogarYuckyChoccy();

int main() {
    jogarYuckyChoccy();
    return 0;
}

void inicializarTabuleiro(int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 'O';
        }
    }
}

void exibirTabuleiro(int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int movimentoValido(int linha, int coluna, int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]) {
    return (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho && tabuleiro[linha][coluna] == 'O');
}

void realizarMovimento(int linha, int coluna, int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]) {
    for (int i = linha; i < tamanho; i++) {
        for (int j = coluna; j < tamanho; j++) {
            tabuleiro[i][j] = 'X';  
        }
    }
}

int verificarFimDeJogo(int tamanho, char tabuleiro[TAM_MAX][TAM_MAX]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[i][j] == 'O') {
                return 0;  
            }
        }
    }
    return 1;  
}

void jogarYuckyChoccy() {
    int tamanho, linha, coluna, jogador = 1;
    char tabuleiro[TAM_MAX][TAM_MAX];
    
    printf("Escolha o tamanho do tabuleiro (exemplo: 3 para 3x3): ");
    scanf("%d", &tamanho);
    if (tamanho < 1 || tamanho > TAM_MAX) {
        printf("Tamanho inválido!\n");
        return;
    }
    
    inicializarTabuleiro(tamanho, tabuleiro);
    
    while (1) {
        exibirTabuleiro(tamanho, tabuleiro);
        printf("Jogador %d, escolha uma linha e coluna (0 a %d): ", jogador, tamanho - 1);
        scanf("%d %d", &linha, &coluna);
        
        if (movimentoValido(linha, coluna, tamanho, tabuleiro)) {
            realizarMovimento(linha, coluna, tamanho, tabuleiro);
            if (verificarFimDeJogo(tamanho, tabuleiro)) {
                exibirTabuleiro(tamanho, tabuleiro);
                printf("Jogador %d ganhou!\n", jogador);
                break;
            }
            jogador = (jogador == 1) ? 2 : 1;  
        } else {
            printf("Movimento inválido! Tente novamente.\n");
        }
    }
}
