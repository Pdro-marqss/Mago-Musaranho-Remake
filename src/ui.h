#ifndef UI_H
#define UI_H

#include "raylib.h"

typedef struct TextAlign {
    bool isCenterX;
    bool isCenterY;
    float x;
    float y;
} TextAlign;

typedef struct Button {
    Rectangle rect;
    const char *label;
} Button;


bool IsButtonPressed(Button *b);
void DrawButton(Button *b);

void DrawTextAlignedInRect(const char *text, Rectangle rect, int fontSize, Color color, TextAlign align);

Rectangle CenterRectX(Rectangle rect, Rectangle container);
Rectangle CenterRectY(Rectangle rect, Rectangle container);
Rectangle CenterRect(Rectangle rect, Rectangle container);

Rectangle PlaceBelow(Rectangle rect, Rectangle reference, float spacing);
Rectangle PlaceAbove(Rectangle rect, Rectangle reference, float spacing);
Rectangle PlaceLeft(Rectangle rect, Rectangle reference, float spacing);
Rectangle PlaceRight(Rectangle rect, Rectangle reference, float spacing);



#endif