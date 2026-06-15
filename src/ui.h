#ifndef UI_H
#define UI_H

#include "raylib.h"


typedef struct Button {
    Rectangle rect;
    const char *text;
} Button;

typedef enum AlignTextMode {
    ALIGN_NONE,
    ALIGN_CENTER_X,
    ALIGN_CENTER_Y,
    ALIGN_CENTER_BOTH
} AlignTextMode;


bool IsButtonPressed(Button *b);
void DrawButton(Button *b);
void DrawTextAlignedInRect(const char *text, Rectangle rect, int fontSize, Color color, AlignTextMode mode);


#endif