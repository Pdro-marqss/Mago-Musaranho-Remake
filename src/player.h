#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

void InitPlayer(Player *p);
void UpdatePlayer(Player *p, float dt);
void DrawPlayer(Player *p);

#endif