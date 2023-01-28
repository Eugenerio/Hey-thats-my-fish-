#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ui.h"
#include "board.h"
#include "placement.h"
#include "movement.h"
#include "struct.h"

int main(){
    srand(time(NULL));
    printLogo(BLUE_TXT,STYLE_BOLD);

    
    int players_num, penguins_per_player;
    int **board;
    int read_input_bytes = 0;

    setColor(STYLE_BOLD);
    enter_players_number:
        printf("Please enter number of players:");
        read_input_bytes = scanf("%d", &players_num);
        if (players_num < 2  || read_input_bytes < 1) {
            printErrorText("Invalid number of players has been entered");
            getchar();
            goto enter_players_number;
        } else if (players_num > MAX_NUM_PLAYERS) {
            setColor(RED_TXT);
            printf("Too many players! Max number of players is %d\n",MAX_NUM_PLAYERS);
            setColor(WHITE_TXT);
            setColor(STYLE_BOLD);
            goto enter_players_number;
        }

    enter_penguins_number:
        printf("Please enter number of penguin per player:");
        read_input_bytes = scanf("%d", &penguins_per_player);
        if (penguins_per_player < 1 || read_input_bytes < 1){
            printErrorText("Invalid number of penguins has been entered");
            getchar();
            goto enter_penguins_number;
        } else if (penguins_per_player > MAX_NUM_PENGUINS) {
            setColor(RED_TXT);
            printf("Too many players! Max number of penguins is %d\n",MAX_NUM_PENGUINS);
            setColor(WHITE_TXT);
            setColor(STYLE_BOLD);
            goto enter_penguins_number;
        }

    enter_board_dimensions:
        printf("Please enter dimensions of board (Board is a square so only enter one number):");
        read_input_bytes = scanf("%d", &board_size);
        if (board_size < 5  || read_input_bytes < 1) {
            printErrorText("Minimum board size is 5x5!");
            getchar();
            setColor(WHITE_TXT);
            setColor(STYLE_BOLD);
            goto enter_board_dimensions;
        }
    
    setup_board:
        board = malloc(board_size * sizeof(int *)); // allocate memory for the game board
        if(board == NULL){
            goto setup_board;
        }

        for (int i = 0; i < board_size; i++){
            board[i] = malloc(board_size * sizeof(int));
            if(board[i] == NULL){
                goto cleanup_board;
            }
        }
    
    resetColor();
    generateBoard(board_size, board);
    printBoard(board, board_size);
    placePenguin(players_num, penguins_per_player, board, board_size);
    movePenguin(board, players_num, board_size, penguins_per_player);

    cleanup_board:
        free(board);
        for (int i = 0; i < board_size; i++){
            free(board[i]);
        }
}
