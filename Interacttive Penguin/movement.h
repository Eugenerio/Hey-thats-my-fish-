//this function checks the surroundings of the penguin and see if there is a legal move
int canMove(int **board, int penguin, int current_player);
/*!

    @param int **board - the GameBoard
    @param int penguin - the current penguin that the player selceted 
    @param int current_player - the current player 

*/

//this 
int movePenguin(int **board, int players_num, int board_size, int penguins_num);
/*!

    @param int **board - the GameBoard
    @param int players_num - the number of the players in the game
    @param int board_size - the board size
    @param int penguins_num - the number of the punguins in the game 

*/

//this function checks if the player can move the penguin to the needed position
int isMoveLegal(int **board, int penguin, int current_player, int dst_row, int dst_col);
/*!

    @param int **board - the GameBoard
    @param int penguin - the current penguin that the player selceted 
    @param int current_player - the current player
    @param int dst_row - the destination row
    @param int dst_col - the destination column

*/

// //
// int gameEnd(int **board, int winner_num, int penguins_num);
// /*!

//     @param int **board - the GameBoard
//     @param int players_num - the current player
//     @param int current_player - the current player

// */


void showScoreboard(int players_num);
/*!

    @param int **players_num - the number of players in the game
  
*/