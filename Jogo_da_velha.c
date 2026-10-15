#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogadorAtual;

void inicializarjogo() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirjogo() {
    
    system("cls");
    
    printf("\n--- JOGO DA VELHA ---\n\n");
    printf("     0   1   2 \n");
    
    for (int i = 0; i < 3; i++) {
        
        printf("  %d  ", i);
        
        for (int j = 0; j < 3; j++) {
            
            printf("%c ", tabuleiro[i][j]);
            
            if (j < 2) { 
                
                printf("| ");
            }
        }
        
        printf("\n");
        
        if (i < 2) {
            
            printf("    -----------\n");
        }
    }
    
    printf("\n");
}


char verificarVencedor() {

    for (int i = 0; i < 3; i++) {
        
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
            
            return tabuleiro[i][0];
        }
        
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]){
            
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
        
        return tabuleiro[0][0];
    }

    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
        
        return tabuleiro[0][2];
    }

    return ' ';
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    
    int linha, coluna;
    char vencedor = ' ';
    jogadorAtual = 'X';



    inicializarTabuleiro();

    while (1) {
        imprimirTabuleiro();
        printf("Jogador '%c', digite a LINHA (0, 1, 2) e a COLUNA (0, 1, 2): ", jogadorAtual);
        
        if (scanf("%d %d", &linha, &coluna) != 2) {
            
            while (getchar() != '\n'); 
            continue;
        }

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        vencedor = verificarVencedor();
        if (vencedor != ' ') {
            imprimirTabuleiro();
            printf("Parabens! O jogador '%c' venceu!\n", vencedor);
            break;
        }

        if (verificarEmpate()) {
            imprimirTabuleiro();
            printf("O jogo terminou em empate!\n");
            break;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}