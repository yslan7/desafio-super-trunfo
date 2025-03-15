#include <stdio.h>

// Estrutura para representar uma carta
typedef struct {
    int velocidade;
    int aceleracao;
    int potencia;
    int tracao;
    int tempo;
} Carta;

// Função para exibir os atributos de uma carta
void exibirCarta(Carta c) {
    printf("\nAtributos da carta:");
    printf("\n1. Velocidade: %d", c.velocidade);
    printf("\n2. Aceleração: %d", c.aceleracao);
    printf("\n3. Potência: %d", c.potencia);
    printf("\n4. Tração: %d", c.tracao);
    printf("\n5. Tempo: %d\n", c.tempo);
}

// Função para exibir o menu de escolha de atributos
int menuAtributo() {
    int escolha;
    printf("\nEscolha um atributo para comparar:");
    printf("\n1. Velocidade");
    printf("\n2. Aceleração");
    printf("\n3. Potência");
    printf("\n4. Tração");
    printf("\n5. Tempo");
    printf("\nDigite o número do atributo: ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta jogador, Carta oponente, int atributo) {
    int valorJogador, valorOponente;

    // Obtém o valor do atributo escolhido para cada carta
    switch (atributo) {
        case 1:
            valorJogador = jogador.velocidade;
            valorOponente = oponente.velocidade;
            printf("\nComparando Velocidade: Jogador (%d) x Oponente (%d)", valorJogador, valorOponente);
            break;
        case 2:
            valorJogador = jogador.aceleracao;
            valorOponente = oponente.aceleracao;
            printf("\nComparando Aceleração: Jogador (%d) x Oponente (%d)", valorJogador, valorOponente);
            break;
        case 3:
            valorJogador = jogador.potencia;
            valorOponente = oponente.potencia;
            printf("\nComparando Potência: Jogador (%d) x Oponente (%d)", valorJogador, valorOponente);
            break;
        case 4:
            valorJogador = jogador.tracao;
            valorOponente = oponente.tracao;
            printf("\nComparando Tração: Jogador (%d) x Oponente (%d)", valorJogador, valorOponente);
            break;
        case 5:
            valorJogador = jogador.tempo;
            valorOponente = oponente.tempo;
            printf("\nComparando Tempo: Jogador (%d) x Oponente (%d)", valorJogador, valorOponente);
            break;
        default:
            printf("\nAtributo inválido!");
            return;
    }

    // Compara os valores e exibe o resultado
    if (valorJogador > valorOponente) {
        printf("\nVocê venceu!\n");
    } else if (valorJogador < valorOponente) {
        printf("\nVocê perdeu!\n");
    } else {
        printf("\nEmpate!\n");
    }
}

// Função principal
int main() {
    Carta jogador = {150, 85, 200, 90, 30}; // Carta do jogador
    Carta oponente = {160, 80, 190, 95, 32}; // Carta do oponente
    int opcao, atributo;

    do {
        // Menu principal
        printf("\n=== SUPER TRUNFO ===");
        printf("\n1. Jogar");
        printf("\n2. Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nSua carta:");
                exibirCarta(jogador);

                printf("\nCarta do oponente:");
                exibirCarta(oponente);

                atributo = menuAtributo(); // Escolha do atributo
                compararCartas(jogador, oponente, atributo); // Comparação das cartas
                break;

            case 2:
                printf("\nSaindo do jogo...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}