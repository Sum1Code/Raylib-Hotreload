#include <raylib.h>

// GLOBALS

Vector2 pos = {400, 300};
Vector2 size = {100, 100};

void Init() {
  // important init window, do not remove
  InitWindow(800, 600, "GameWindow");
  // CODE ONLY RUNS ONCE BEFORE UPDATE LOOP
  // code after here:
}

void Update() {
  // CODE RUNS EVERY FRAME

  BeginDrawing();
  ClearBackground(RAYWHITE);
  // DRAW HERE
  DrawRectangleV(pos, size, GREEN);
  EndDrawing();
}
