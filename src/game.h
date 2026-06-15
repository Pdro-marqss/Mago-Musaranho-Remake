#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "ui.h"


typedef enum GameState {
    STATE_MENU,
    STATE_GAMEPLAY,
    STATE_GAMEOVER
} GameState;

typedef struct Menu {
    Button playButton;
    Button exitButton;
} Menu;

typedef struct Game {
    GameState state;
    Player player;
    Menu menu;
    bool shouldExit;
} Game;


void InitGame(Game *game);
void UpdateGame(Game *game, float dt);
void DrawGame(Game *game);

#endif