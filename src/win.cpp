#include "win.h"
#include "player.h"
#include "raylib.h"
int screenHeight = 400;
int screenWidth = 400;
Win::Win() {
  ShowCursor();
  InitWindow(screenWidth, screenHeight, "ElderWood");
  SetWindowTitle("Yohannes");
  Player player;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKBLUE);
    player.movement();
    EndDrawing();
  }
  CloseWindow();
}
