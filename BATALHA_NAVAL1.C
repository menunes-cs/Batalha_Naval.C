#include <stdio.h>

// DEFINIÇÕES DE TAMANHOS E PEÇAS
#define TAM_Tabuleiro 10
#define NAVIO 3
#define HABILIDADE 5

//DEFINIÇÃO DAS POSIÇÕEES E DISPAROS 
#define Cone_Linha 2
#define Cone_Coluna 4

#define Cruz_Linha 8
#define Cruz_coluna 2

int main () {

    //Declarando a Matriz 
    int tabuleiro[TAM_Tabuleiro][TAM_Tabuleiro] = {0}; // Inicializa tudo com 0 no caso água.
    int i, j;

    // POSICIONAMENTO DOS NAVIOS

    // 1.Navio Horizontal
    for (int i = 0; i < NAVIO; i++) {
    tabuleiro[2][1 + i] = NAVIO; // Horizzontal
    tabuleiro[5 +i][6] = NAVIO; // vertical
    tabuleiro[i] [7 + i] = NAVIO; // Diagonal 01
    tabuleiro [7 + i][2 - i] = NAVIO; // Diagonal 02
    }    

    // HABILIDADE EM CONE 
    
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 5; j++){
        if (( i == 0 && j ==2 ) || ( i == 1 && j >=1 && j <=3 ) || ( i == 2)) { // Verifica qual parte do cone destacar 
            // Calcula a posição aplicando o deslocamento horizontal 
            int l = Cone_Linha +i;
            int c = Cone_Coluna + (j-2);
            // Garante qque não vai destacar fora do tabuleiro 
            if ( l = 0 && l < TAM_Tabuleiro && c >= 0 && c < TAM_Tabuleiro) {
                tabuleiro[l][c] = HABILIDADE; 
            
            }
        }        
    }
} 
    
     // HABILIDADE EM CRUZ
     
     for ( i = 0; i <5; i++){
     // Pinta a linha horizontal da cruz (destacando para direita/esquerda)
     int c_horiz = Cruz_coluna + (i-2);
     if (Cruz_Linha >= 0 && Cruz_Linha < TAM_Tabuleiro && c_horiz >= 0 && c_horiz <TAM_Tabuleiro) {
        tabuleiro[Cruz_Linha][c_horiz] = HABILIDADE;
     }
     // Pinta a linha vertical da luz (deslocando para cima/baixo)
     int l_vert = Cruz_Linha + (i-2);
     if (l_vert >= 0 && l_vert < TAM_Tabuleiro && Cruz_coluna >= 0 && Cruz_coluna < TAM_Tabuleiro) {
        
     }   
     }
     
 printf("\n");

// Exibição do Tabuleiro
printf(" TABULEIRO BATALHA NAVAL \n ");

printf(" A B C D E F G H I J\n "); // Guia de Colunas 

for (int i = 0; i < TAM_Tabuleiro; i++) {
    printf("%2d ", i); // Imprime o número da linha na lateral

    for (int j = 0; j < TAM_Tabuleiro; j++) {
        printf("%d ", tabuleiro[i][j]); // Imprime o conteúdo com espaço
    }
 
    printf("\n"); // Pula linha DEPOIS de imprimir as 10 colunas
}
return 0;
} 