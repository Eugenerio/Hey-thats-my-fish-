#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "struct.h"
#include "board.h"
#include "ui.h"

int canMove(int **board, int penguin, int current_player){
    int r = players[current_player].penguins_rows[penguin];
    int c = players[current_player].penguins_cols[penguin];
    setColor(YELLOW_TXT);
    setColor(STYLE_ITALIC);
    printf("Penguin's current position: (%d,%d)\n", r, c);
    if (((board[r + 1][c] == 0) || (board[r + 1][c] > 3)) && ((board[r - 1][c] == 0) || (board[r - 1][c] > 3)) &&
     ((board[r][c + 1] == 0) || (board[r][c + 1] > 3)) && ((board[r][c - 1] == 0) || (board[r][c - 1] > 3))) {
        return 0;
    }
    resetColor();

    return 1;
}

// int gameEnd(int **board, int winner_num, int penguins_num)
// {
//     setColor(YELLOW_TXT);
//     setColor(STYLE_BOLD);
//     for (int i = 0, stuck_penguins = 0; i < winner_num; i++)
//     {
//         if (stuck_penguins == (penguins_num * winner_num))
//         {
//             printf("Number of stuck penguins: %d\n", stuck_penguins);
//             return 0;
//         }else {
//             return 1;
//         }

//         for (int j = 0, stuck_penguins = 0; j < penguins_num; j++) {
//             if (canMove(board, j, i)) {
//                 stuck_penguins = 0;
//                 return 1;
//             }else {
//                 stuck_penguins++;
//             }
//         }
//     }

//     resetColor();
//     return 0;
// }

int showWinner(int players_num){
    int* scores = malloc(sizeof(int) * players_num);
    int temp;
    for (int c = 0; c < players_num - 1; c++)
    {
        for (int d = 0; d < players_num - c - 1; d++)
        {
            if (scores[d] > scores[d + 1])
            {
                temp = scores[d];
                scores[d] = scores[d + 1];
                scores[d + 1] = temp;
            }
        }
    }
    free(scores);
    return 0;
}

void showScoreboard(int players_num){
    printCharLine('+', GREEN_TXT);
    printFramedText("SCOREBOARD",'+',1, GREEN_TXT,GREEN_TXT);
    printCharLine('+', GREEN_TXT);
    setColor(STYLE_BOLD);
    for (int i = 0; i < players_num; i++) {
        printf("\tPlayer %d: %d\n", i + 1, players[i].score);
    }
    printCharLine('+', GREEN_TXT);
    resetColor();
}

int movePenguin(int **board, int players_num, int board_size, int penguins_num){
    int src_row, src_col, current_penguin, current_player, dst_row, dst_col, read_input_bytes = 0;
    
    while (1) {
        for (int i = 0; i < players_num; i++) {
            current_player = i;
            while (1) {
                int stuck_penguins;
                for (int k = 0; k < penguins_num; k++)
                {
                    if (canMove(board, k, i))
                    {
                        stuck_penguins = 0;
                    }else{
                        stuck_penguins++;
                    }
                }
                if (stuck_penguins == penguins_num)
                {
                    printf("Player %d will be skipped since all their penguins are stuck\n", current_player + 1);
                    break;
                }
                else if (stuck_penguins == (penguins_num * players_num))
                {
                    showScoreboard(players_num);
                    return 0;
                }


            enter_src_penguin:
                setColor(RED_TXT + current_player);
                printf("Player %d, Please select penguin to move:\n", current_player + 1);
                printf("What row is the penguin on? ");
                read_input_bytes = scanf("%d", &src_row);
                if(read_input_bytes < 1){
                    getchar();
                    printf("\n");
                    printBoard(board, board_size);
                    goto enter_src_penguin;
                }

                printf("What column is the penguin on? ");
                read_input_bytes = scanf("%d", &src_col);
                if(read_input_bytes < 1){
                    getchar();
                    printf("\n");
                    printBoard(board, board_size);
                    goto enter_src_penguin;
                }

                if ((board[src_row][src_col] - (10 * (current_player + 1)) > 0) && (board[src_row][src_col] - (10 * (current_player + 1)) < 10))
                {
                    current_penguin = board[src_row][src_col] - 1 - (10 * (current_player + 1));
                    // printf("%d\n", currentPeng);
                    if (canMove(board, current_penguin, current_player) == 0)
                    {
                        printf("Chosen penguin is stuck!");
                        continue;
                    }

                    printBoard(board, board_size);
                
                enter_dst_penguin:
                    setColor(RED_TXT + current_player);
                    printf("Player %d, Please select block to move on:\n", current_player + 1);
                    printf("Which row do you want to move to? ");
                    read_input_bytes = scanf("%d", &dst_row);
                    if(read_input_bytes < 1){
                        getchar();
                        printf("\n");
                        printBoard(board, board_size);
                        goto enter_dst_penguin;
                    }
                    
                    printf("Which column do you want to move to? ");
                    read_input_bytes = scanf("%d", &dst_col);
                    if(read_input_bytes < 1){
                        getchar();
                        printf("\n");
                        printBoard(board, board_size);
                        goto enter_dst_penguin;
                    }
                

                    if (isMoveLegal(board, current_penguin, i, dst_row, dst_col)) {
                        players[current_player].score += board[dst_row][dst_col];
                        board[players[current_player].penguins_rows[current_penguin]][players[current_player].penguins_cols[current_penguin]] = 0;
                        players[current_player].penguins_rows[current_penguin] = dst_row;
                        players[current_player].penguins_cols[current_penguin] = dst_col;
                        board[dst_row][dst_col] = (10 * (current_player + 1)) + (current_penguin + 1);
                        printBoard(board, board_size);
                        break;
                    }else {
                        continue;
                    }
                } else {
                    printErrorText("Selected penguin doesn't belong to the current player!");
                    continue;
                }
            }
        }
    }
    resetColor();
}

int isMoveLegal(int **board, int penguin, int current_player, int dst_row, int dst_col){

    int r = players[current_player].penguins_rows[penguin];
    int c = players[current_player].penguins_cols[penguin];
    if ((board[dst_row][dst_col] != 0) && (board[dst_row][dst_col] <= 3)) {
        printf("Destination %d %d\n", dst_row, dst_col);
        if (r == dst_row) {
            if ((c > dst_col) && (c != dst_col + 1))
            {
                for (int i = c + 1; i > dst_col; i--)
                {
                    if ((board[r][i] == 0) || (board[r][i] > 3))
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            else if ((c < dst_col) && (c + 1 != dst_col))
            {
                for (int i = dst_col; i < c; i++)
                {
                    if ((board[r][i] == 0) || (board[r][i] > 3))
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            else
            {
                return 1;
            }
        }
        else if (c == dst_col)
        {
            if ((r > dst_row) && (r != dst_row + 1)) {
                for (int i = r; i > dst_row; i--)
                {
                    if ((board[i][c] == 0) || (board[i][c] > 3))
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
            } else if ((r < dst_row) && (r + 1 != dst_row)) {
                for (int i = dst_row; i < r; i++) {
                    if ((board[i][c] == 0) || (board[i][c] > 3)) {
                        return 0;
                    }else {
                        return 1;
                    }
                }
            }
        }
        else {
            printInfoText("Penguin can only move in a straight line");
        }
    }else{
        printWarningText("Penguin cannot move on an empty block or on another penguin");
    }

    return 1;
}