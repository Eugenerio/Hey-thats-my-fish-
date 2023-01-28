#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "ui.h"

int board_size = 0;

void generateBoard(int boardSize, int **board){
    for (int k = 0; k < boardSize; k++){
        board[0][k] = 0;
    }

    for (int l = 0; l < boardSize; l++){
        board[boardSize - 1][l] = 0;
    }

    for (int m = 0; m < boardSize; m++){
        board[m][0] = 0;
    }

    for (int n = 0; n < boardSize; n++){
        board[n][boardSize - 1] = 0;
    }

    for (int i = 1; i < boardSize - 1; i++){
        for (int j = 1; j < boardSize - 1; j++){
            board[i][j] = rand() % 4;
        }
    }
}




void printBoard(int **board, int boardSize) {
    setColor(STYLE_BOLD);
    setColor(BLUE_TXT);
    // Print Column Indices
    printf("  +---");
    for (int j = 0; j < boardSize; j++) {
        printf("%1d", j);
        if(j + 1 != boardSize){
        printf("---");
        }
    }            
    printf("\n");



    for (int i = 0; i < boardSize; i++) {
        printf("%2d| ", i); // Print Row Indices

        for (int j = 0; j < boardSize; j++) {
            if(board[i][j] > 10){
                // Print Player Icon
                printf("  P%1d", (board[i][j] / 10));
            }else{
                // Print Floe
                printf("%3d ", board[i][j]);
            }
        }
        printf("\n");
    }
    resetColor();
}