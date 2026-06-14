#include "player.h"
#include "config.h"

void InitPlayer(Player *p) {
    p->position = (Vector2){ VIRTUAL_WIDTH / 2.0f, VIRTUAL_HEIGHT / 2.0f };
    p->speed = 300.0f;
}

void UpdatePlayer(Player *p, float dt) {
    if (IsKeyDown(KEY_W)) p->position.y -= p->speed * dt;
    if (IsKeyDown(KEY_S)) p->position.y += p->speed * dt;
    if (IsKeyDown(KEY_A)) p->position.x -= p->speed * dt;
    if (IsKeyDown(KEY_D)) p->position.x += p->speed * dt;
}

void DrawPlayer(Player *p) {
    DrawCircleV(p->position, 10, BLUE);
}