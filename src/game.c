#include "game.h"
#include "config.h"
#include "raylib.h"


void InitGame(Game *game) {
    game->shouldExit = false;
    game->state = STATE_MENU;

    InitPlayer(&game->player);

    Rectangle screenRect = { 0, 0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT};
    Rectangle titleRect = { 0, 250, VIRTUAL_WIDTH, 40};

    Rectangle playRect = { 0, 0, 200, 60};
    playRect = CenterRectX(playRect, screenRect);
    playRect = PlaceBelow(playRect, titleRect, 40);
    game->menu.playButton = (Button){ playRect, "PLAY" };

    Rectangle exitRect = { 0, 0, 200, 60};
    exitRect = CenterRectX(exitRect, screenRect);
    exitRect = PlaceBelow(exitRect, playRect, 20);
    game-> menu.exitButton = (Button){ exitRect, "EXIT" };
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
            if (IsKeyPressed(KEY_ESCAPE)) game->state = STATE_MENU;
            break;
            


        case STATE_GAMEOVER:
            break;
    }
}


void DrawGame(Game *game) {
    switch(game->state) {

        case STATE_MENU:
            DrawTextAlignedInRect(
                "MUSARANHO REMAKE", 
                (Rectangle){ 0, 0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT}, 
                40, 
                WHITE, 
                (TextAlign) {.isCenterX = true, .isCenterY = false, .y = 250});

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