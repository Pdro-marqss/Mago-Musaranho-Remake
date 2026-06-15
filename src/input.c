#include "input.h"
#include "config.h"
#include <math.h>

Vector2 GetMouseVirtual(void)
{
    Vector2 mouse = GetMousePosition();

    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    float scale = fminf(
        screenW / VIRTUAL_WIDTH,
        screenH / VIRTUAL_HEIGHT
    );

    float renderW = VIRTUAL_WIDTH * scale;
    float renderH = VIRTUAL_HEIGHT * scale;

    float offsetX = (screenW - renderW) * 0.5f;
    float offsetY = (screenH - renderH) * 0.5f;

    // 🔥 importante: converte pra espaço do render primeiro
    Vector2 virtualMouse = {
        (mouse.x - offsetX) / scale,
        (mouse.y - offsetY) / scale
    };

    // 🔥 clamp (evita comportamento estranho fora da área)
    if (virtualMouse.x < 0) virtualMouse.x = 0;
    if (virtualMouse.y < 0) virtualMouse.y = 0;
    if (virtualMouse.x > VIRTUAL_WIDTH) virtualMouse.x = VIRTUAL_WIDTH;
    if (virtualMouse.y > VIRTUAL_HEIGHT) virtualMouse.y = VIRTUAL_HEIGHT;

    return virtualMouse;
}