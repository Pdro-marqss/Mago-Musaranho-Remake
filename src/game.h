#ifndef GAME_H
#define GAME_H

#include "player.h"

typedef enum GameState {
    STATE_MENU,
    STATE_GAMEPLAY,
    STATE_GAMEOVER
} GameState;

typedef struct Game {
    GameState state;
    Player player;
} Game;

void InitGame(Game *game);
void UpdateGame(Game *game, float dt);
void DrawGame(Game *game);

#endif