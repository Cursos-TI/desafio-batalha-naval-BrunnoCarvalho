#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define TAM_LINHA 10
#define TAM_COLUNA 10

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[TAM_LINHA][TAM_COLUNA];

    for(int i=0; i < TAM_LINHA; i++){
        for(int j = 0; j <TAM_COLUNA; j++){
            tabuleiro[i][j] = 0;
        }
    }

    int navioHorizontal[2] = {1, 2};
    int navioVertical[2] = {3, 5};

    int linha = navioHorizontal[0] - 1; //Considerando tabuleiro de 1 até 10. Fazemos o -1 para percorrer os indices de 0 até 4.
    int coluna = navioHorizontal[1] - 1;
    
    if(linha < TAM_LINHA && coluna + 2 < TAM_COLUNA){
        for(int j = 0; j < 3; j++){
            tabuleiro[linha][coluna + j] = 3;
        }
    }else{
        printf("Índices fora do limite do tabuleiro!\n");
        return 1;
    }

    linha = navioVertical[0] - 1;
    coluna = navioVertical[1] - 1;

    if(linha +2 < TAM_LINHA && coluna < TAM_COLUNA){
        for(int i = 0 ; i < 3; i++){
            if(tabuleiro[i + linha][coluna] == 3){
                printf("Você não pode sobrepor navios.\n");
                return 1;
            }
            tabuleiro[i + linha][coluna] = 3;
        }
    }else{
        printf("Índices fora do limite do tabuleiro!\n");
        return 1;
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int navioDiagonal[2] = {7, 7};
    int navioDiagonalSec[2] = {1, 10};

    linha = navioDiagonal[0] - 1; //Considerando tabuleiro de 1 até 10. Fazemos o -1 para percorrer os indices de 0 até 4.
    coluna = navioDiagonal[1] - 1;

    for (int i = 0; i < 3; i++) {
        if(tabuleiro[linha + i][coluna + i] == 3){
            printf("Você não pode sobrepor navios.\n");
            return 1;
        }
        tabuleiro[linha + i][coluna + i] = 3;
    }

    linha = navioDiagonalSec[0] - 1; 
    coluna = navioDiagonalSec[1] - 1;

    for(int i = 0; i < 3; i++){
        if(tabuleiro[linha][coluna] == 3){
            printf("Você não pode sobrepor navios.\n");
            return 1;
        }
        tabuleiro[linha][coluna] = 3;
        linha++;
        coluna--;
    }

    //Apresentação da matriz
    for(int i=0; i < TAM_LINHA; i++){
        for(int j = 0; j <TAM_COLUNA; j++){
            printf("%d ", tabuleiro[i][j] );
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
