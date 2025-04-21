#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Protótipos das funções
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                        int linha_origem, int coluna_origem);


int main() {
    // Tabuleiro principal (0 = água, 3 = navio, 5 = area de habilidade)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // matrizes para as habilidades (0 = não afetado, 1 = afetado)
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // inicializa o tabuleiro com água e alguns navios
    inicializarTabuleiro(tabuleiro);

    // Cria as matrizes de habilidades
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // exibe o tabuleiro original
    printf("tabuleiro original:\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");

    //aplica a habilidade cone na posição (2, 2)
    printf("Aplicando habilidade cone em (2, 2):\n");
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    exibirTabuleiro(tabuleiro);
    printf("\n");

    //Aplica a habilidade Cruz na posição (5, 5)
    printf("Aplicando Habilidade Cruz em (5, 5):\n");
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    exibirTabuleiro(tabuleiro);
    printf("\n");

    //aplica a habilidade octaedro na posição (7, 7)
    printf("aplicando habilidade octaedro em (7, 7):\n");
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);
    exibirTabuleiro(tabuleiro);

    return 0;
}


// inicializa o tabuleiro com água (0) e coloca alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j< TAM_TABULEIRO; j++) {
            // Água em todas as posições
            tabuleiro[i][j] = 0;

            // adiciona alguns navios em posicões especificas
            if ((i == 1 && j == 1) || (i == 3 && j == 4) ||
                (i == 5 && j == 7) || (i == 8 && j == 2)) {
                    tabuleiro[i][j] = 3;
           }
        }
    }
}

// Exibe o tabuleiro formado
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])  {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Cria a matriz de habilidade em formato de cone (apontando para baixo)
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // verifica se a posição está dentro do cone
            if (i >= centro && abs(j - centro) <= (i - centro)) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Cria a matriz de habilidade em formto de cruz
void  criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE /2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // verifiva se está na linha ou coluna central
            if (i == centro || j == centro) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada           
            }
        }
    }
}

// criar a matriz de habilidade em formato de octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // verifica se a posição dentro do losano
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
}

// aplica a habilidade ao tabuleiro na posição especificada
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                        int linha_origem, int coluna_origem) {
    // calcula o deslocamento para centralizar a habilidade
    int deslocamento = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // calcula a posição no tabuleiro
            int linha_tab = linha_origem - deslocamento + i;
            int coluna_tab = coluna_origem - deslocamento + j;

            // verifica se está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO &&
                coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO) {
                    // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                    if (habilidade[i][j] == 1) {
                        tabuleiro[linha_tab][coluna_tab] = 5; // Área de habilidade
                    }
                }
            }
        }
    }