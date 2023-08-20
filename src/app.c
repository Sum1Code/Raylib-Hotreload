#include "app_plug.h"
#include <raylib.h>

// GLOBALS
Window_t win = {.name = "Hello", .height = 600, .width = 800};
Vector2 rect[2] = {{400, 200}, {200, 200}};
Camera3D *cam = NULL;
void Init() {
  // important init window, do not remove
  CreateWindow(win);
  cam = CreateCamera3D();
  // CODE ONLY RUNS ONCE BEFORE UPDATE LOOP
  // code after here:
}

void Update() {
  // CODE RUNS EVERY FRAME

  BeginDrawing();
  ClearBackground(RAYWHITE);
  // DRAW HERE
  BeginMode3D(*cam);
  DrawCube((Vector3){0, 0, 0}, 2.0f, 2.0f, 2.0f, BLUE);
  EndMode3D();
  EndDrawing();
}

void CleanUp() {
  // CLEAN UP CODE
}
