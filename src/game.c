#include "game.h"
#include "config.h"
#include "raylib.h"


void InitGame(Game *game) {
    game->shouldExit = false;
    game->state = STATE_MENU;

    InitPlayer(&game->player);

    game->menu.playButton = (Button){ {540, 300, 200, 60}, "PLAY" };
    game-> menu.exitButton = (Button){ {540, 380, 200, 60}, "EXIT" };
}


void UpdateGame(Game *game, float dt) {
    switch (game->state) {

        case STATE_MENU: 
            if (IsButtonPressed(&game->menu.playButton)) {
                InitPlayer(&game->player);
                game->state = STATE_GAMEPLAY;
            }

            if (IsButtonPressed(&game->menu.exitButton)) {
                game->shouldExit = true;
            }

            break;


        case STATE_GAMEPLAY: 
            UpdatePlayer(&game->player, dt);
            if (IsKeyPressed(KEY_SPACE)) game->state = STATE_MENU;
            break;


        case STATE_GAMEOVER:
            break;
    }
}


void DrawGame(Game *game) {
    switch(game->state) {

        case STATE_MENU:
            // DrawText("MENU", 580, 200, 40, WHITE);
            DrawTextAlignedInRect("MENU", (Rectangle){ 0, 0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT }, 40, WHITE, ALIGN_CENTER_X);

            DrawButton(&game -> menu.playButton);
            DrawButton(&game -> menu.exitButton);

            break;
        

        case STATE_GAMEPLAY:
            DrawPlayer(&game->player);
            break;


        case STATE_GAMEOVER:
            DrawText("GAME OVER", 500, 300, 40, RED);
            break;
    }
}