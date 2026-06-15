#include "ui.h"
#include "config.h"
#include "input.h"


bool IsButtonPressed(Button *b) {
    Vector2 mouse = GetMouseVirtual();

    bool buttonClicked = CheckCollisionPointRec(mouse, b->rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    return buttonClicked;
}


void DrawButton(Button *b) {
    Vector2 mouse = GetMouseVirtual();

    bool hover = CheckCollisionPointRec(mouse, b->rect);

    Color color = hover ? DARKGRAY : GRAY;

    DrawRectangleRec(b->rect, color);
    DrawRectangleLinesEx(b->rect, 2, BLACK);

    int textWidth = MeasureText(b->text, 20);

    DrawText(
        b->text,
        b->rect.x + (b->rect.width - textWidth) / 2,
        b->rect.y + 15,
        20,
        WHITE
    );
}


void DrawTextAlignedInRect(const char *text, Rectangle rect, int fontSize, Color color, AlignTextMode mode) {
    int textWidth = MeasureText(text, fontSize);

    float x = rect.x;
    float y = rect.y;

    switch (mode) {
        case ALIGN_CENTER_X:
            x += (rect.width - textWidth) * 0.5f;
            break;

        case ALIGN_CENTER_Y:
            y += (rect.height - fontSize) * 0.5f;
            break;

        case ALIGN_CENTER_BOTH:
            x += (rect.width - textWidth) * 0.5f;
            y += (rect.height - fontSize) * 0.5f;
            break;

        case ALIGN_NONE:
        default:
            break;
    }


    DrawText(text, (int)x, (int)y, fontSize, color);
}