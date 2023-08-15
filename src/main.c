#include <raylib.h>

int main(void) {
  InitWindow(800, 600, "hello, world!");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, world!", 350, 250, 48, GRAY);
    EndDrawing();
  }
  return 0;
}
