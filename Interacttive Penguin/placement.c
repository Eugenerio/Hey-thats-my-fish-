#include <stdio.h>
#include "placement.h"
#include "struct.h"
#include "ui.h"

void placePenguin(int player_num, int penguin_num, int **board, int board_size) {
    int placing_row, placing_col, read_input_bytes = 0;
    for (int current_penguin = 0; current_penguin < penguin_num; current_penguin++) {
        for (int current_player = 0; current_player < player_num; current_player++) {
            enter_place:
                setColor(RED_TXT + current_player);
                setColor(STYLE_BOLD);
                printf("Player %d, please place penguin number %d\n", current_player + 1, current_penguin + 1);
                resetColor();
                setColor(STYLE_BOLD);
                printf("Choose a row to place your penguin in:");
                read_input_bytes = scanf("%d", &placing_row);
                if(read_input_bytes < 1){
                    getchar();
                    printf("\n");
                    printBoard(board, board_size);
                    goto enter_place;
                }

                printf("Choose a column to place your penguin in:");
                read_input_bytes =  scanf("%d", &placing_col);
                
                if(read_input_bytes < 1){
                    getchar();
                    printf("\n");
                    printBoard(board, board_size);
                    goto enter_place;
                }

                if(placing_row >= board_size || placing_col >= board_size || placing_row < 0 || placing_col < 0) {
                    printBoard(board, board_size);
                    printErrorText("[Invalid Placement Place] Enter a place location within the board!");
                    goto enter_place;
                }

                if (board[placing_row][placing_col] == 1) {
                    board[placing_row][placing_col] = (10 * (current_player + 1)) + (current_penguin + 1);
                    players[current_player].penguins_rows[current_penguin] = placing_row;
                    players[current_player].penguins_cols[current_penguin] = placing_col;
                    printFramedText("Penguin placed successfully!",'*',true,GREEN_TXT,STYLE_BOLD);
                    printBoard(board, board_size);
                } else {
                    printErrorText("[Invalid Placement] Penguins can only be placed on floes with '1'!");
                    goto enter_place;
                }
        }
    }
    resetColor();
}
