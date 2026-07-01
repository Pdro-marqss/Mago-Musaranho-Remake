#include "raylib.h"
#include "config.h"
#include "game.h"
#include <math.h>

int main(void) {
    SetConfigFlags( FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED);

    InitWindow(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, GAME_NAME);
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
    ToggleFullscreen();

    
    int monitor = GetCurrentMonitor();
    int monitorRefreshRate = GetMonitorRefreshRate(monitor);

    SetTargetFPS(monitorRefreshRate);
    
    RenderTexture2D target = LoadRenderTexture(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);


    Game game;
    InitGame(&game);


    // Loop
    while (!WindowShouldClose() && !game.shouldExit){
        // Corrige o bug do alt+tab fullscreen
        if (!IsWindowFocused() && IsWindowFullscreen()) {
            MinimizeWindow();
            BeginDrawing();
            EndDrawing();
            continue;
        }

        float dt = GetFrameTime();

        UpdateGame(&game, dt);

        BeginTextureMode(target);
            ClearBackground(BLACK);
            DrawGame(&game);
        EndTextureMode();


        // Calculos de escala para responsividade em monitores
        float screenW = (float)GetScreenWidth();
        float screenH = (float)GetScreenHeight();
        float scale = fminf(screenW / VIRTUAL_WIDTH, screenH / VIRTUAL_HEIGHT);
        float renderW = VIRTUAL_WIDTH * scale;
        float renderH = VIRTUAL_HEIGHT * scale;
        float offsetX = (screenW - renderW) * 0.5f;
        float offsetY = (screenH - renderH) * 0.5f;


        BeginDrawing();
            ClearBackground(BLACK);

            DrawTexturePro(
                target.texture,
                (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height },
                (Rectangle){ offsetX, offsetY, renderW, renderH },
                (Vector2){ 0, 0 },
                0.0f,
                WHITE
            );

            DrawText("W A S D para mover", 20, 20, 20, WHITE);
            DrawFPS(20, 50);

            // DrawText(TextFormat("Monitor: %d x %d", GetScreenWidth(), GetScreenHeight()), 20, 50, 20, WHITE);
            // DrawText(TextFormat("Monitor fps: %d", monitorRefreshRate), 20, 80, 20, WHITE);
            // DrawText(TextFormat("Screen: %d x %d", GetScreenWidth(), GetScreenHeight()), 20, 110, 20, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}