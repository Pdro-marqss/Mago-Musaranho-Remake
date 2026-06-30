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

    int textWidth = MeasureText(b->label, 20);

    DrawText(
        b->label,
        b->rect.x + (b->rect.width - textWidth) / 2,
        b->rect.y + 15,
        20,
        WHITE
    );
}


void DrawTextAlignedInRect(const char *text, Rectangle rect, int fontSize, Color color, TextAlign align) {
    int textWidth = MeasureText(text, fontSize);

    float x = rect.x + align.x;
    float y = rect.y + align.y;

    if (align.isCenterX) x = rect.x + (rect.width - textWidth) * 0.5f;
    if (align.isCenterY) y = rect.y + (rect.height - fontSize) * 0.5f;

    DrawText(text, (int)x, (int)y, fontSize, color);
}

Rectangle CenterRectX(Rectangle rect, Rectangle container) {
    rect.x = container.x + (container.width - rect.width) * 0.5f;
    return rect;
}

Rectangle CenterRectY(Rectangle rect, Rectangle container) {
    rect.y = container.y + (container.height - rect.height) * 0.5f;
    return rect;
}

Rectangle CenterRect(Rectangle rect, Rectangle container) {
    rect = CenterRectX(rect, container);
    rect = CenterRectY(rect, container);

    return rect;
}

Rectangle PlaceBelow(Rectangle rect, Rectangle reference, float spacing) {
    rect.y = reference.y + reference.height + spacing;
    return rect;
}

Rectangle PlaceAbove(Rectangle rect, Rectangle reference, float spacing) {
    rect.y = reference.y - rect.height - spacing;
    return rect;
}

Rectangle PlaceLeft(Rectangle rect, Rectangle reference, float spacing) {
    rect.x = reference.x - rect.width - spacing;
    return rect;
}

Rectangle PlaceRight(Rectangle rect, Rectangle reference, float spacing) {
    rect.x = reference.x + reference.width + spacing;
    return rect;
}