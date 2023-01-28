#ifndef PLAYERS_H
#define PLAYERS_H
#define MAX_NUM_PLAYERS 15
#define MAX_NUM_PENGUINS 10

typedef struct _players{
    int score;
    int penguins_rows[MAX_NUM_PLAYERS];
    int penguins_cols[MAX_NUM_PLAYERS];
} Player;


Player players[MAX_NUM_PLAYERS];

#endif