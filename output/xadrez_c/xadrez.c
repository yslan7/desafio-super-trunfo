#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// constantes para o numero de movimentos
#define MOVES 3

// função recursiva para mover a torre
void moverTorre(int casas, const char *direcao) {
    if (casas<= 0) return;

    printf("%s\n", direcao);
    moverTorre(casas - 1, direcao);
}

// função recursiva para mover o bispo (diagonal)
void moverBispo(int casas, const char *direcaoVertical, const char *direcaoHorizontal) {
    if(casas <= 0) return;

    printf("%s e %s\n", direcaoVertical, direcaoHorizontal);
    moverBispo(casas - 1, direcaoVertical, direcaoHorizontal);
}

// função para mober o Bispo com loops aninhados
void moverBispoloops(int casas) {
    for (int v = 1; v <= casas; v++) {
        for (int h = 1; h <= casas; h++) {
            if (v == h) { // apenas movimentos diagonais
                printf("Cima e Direita\n");
            }
        }
    }
}

// função recursiva para mover a Rainha ( combina torre e bispo)
void moverRainha(int casas, const char *direcaoVertical, const char *direcaoHorizontal, int isDiagonal) {
    if (casas <= 0) return;

    if(isDiagonal) {
        printf("%s e %s\n", direcaoVertical, direcaoHorizontal);
    } else {
        if (strcmp(direcaoVertical,"" )== 0) {
            printf("%s\n", direcaoHorizontal);
        } else {
            printf("%s\n", direcaoVertical);
           }
        }

      moverRainha(casas - 1, direcaoVertical, direcaoHorizontal, isDiagonal);
    }

    // função para mover o cavalo em L (2 cima, 1 direita) com loops complexos
    void moverCavalo(int max_moves) {
        int moves = 0;

        for (int up = 1; up < 2; up++) {
            if (moves >= max_moves) break;

            for (int right =1; right <= 1; right++) {
                if (up == 2 && right == 1) {
                    printf("cima\n");
                    printf("cima\n");
                    printf("direita\n");
                    moves++;
                    break;
                }
            }
        }
    }

    int main() {
        printf("movimentos da torre:\n");
        moverTorre(MOVES, "cima");
        moverTorre(MOVES, "direita");
        printf("\n");

        printf("movimentos do bispo (recursivo):\n");
        moverBispo(MOVES, "cima", "direita");
        printf("\n");

        printf("Movimetos do bispo (loops aninhados):\n");
        moverBispoloops(MOVES);
        printf("\n");

        printf("movimentos da rainha:\n");
        printf("como torre:\n");
        moverRainha(MOVES, "cima", "", 0);
        printf("como Bispo:\n");
        moverRainha(MOVES, "cima", "direita", 1);
        printf("\n");

        printf("movimetos do cavalo:\n");
        moverCavalo(1); // move em L uma vez
        printf("\n");

        return 0;
    }




   
