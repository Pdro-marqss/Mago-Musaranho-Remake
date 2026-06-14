#include "game.h"
#include "raylib.h"


void InitGame(Game *game) {
    game->state = STATE_MENU;
    InitPlayer(&game->player);
}


void UpdateGame(Game *game, float dt) {
    switch (game->state) {
        case STATE_MENU: 
            if (IsKeyPressed(KEY_ENTER)) {
                InitPlayer(&game->player);
                game->state = STATE_GAMEPLAY;
            };
            break;

        case STATE_GAMEPLAY: 
            UpdatePlayer(&game->player, dt);
            if (IsKeyPressed(KEY_SPACE)) game->state = STATE_MENU;
            break;

        case STATE_GAMEOVER:
            if (IsKeyPressed(KEY_ENTER)) game->state = STATE_MENU;
            break;
    }
}


void DrawGame(Game *game) {
    switch(game->state) {
        case STATE_MENU:
            DrawText("MENU", 580, 300, 40, WHITE);
            DrawText("ENTER para jogar", 500, 360, 20, WHITE);
            break;
        
        case STATE_GAMEPLAY:
            DrawPlayer(&game->player);
            break;

        case STATE_GAMEOVER:
            DrawText("GAME OVER", 500, 300, 40, RED);
            break;
    }
}