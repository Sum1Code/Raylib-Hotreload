#ifndef _APP_PLUG_H
#define _APP_PLUG_H
#include <raylib.h>
#include <stdlib.h>

typedef struct WindowContext {
  int width;
  int height;
  const char *name;
} Window_t;

void CreateWindow(Window_t window_context) {
  InitWindow(window_context.width, window_context.height, window_context.name);
}
Camera3D *CreateCamera3D() {
  Camera3D *cam = malloc(sizeof(Camera3D));
  cam->position = (Vector3){0, 0, 0};
  cam->projection = CAMERA_PERSPECTIVE;
  cam->up = (Vector3){0, 1, 0};
  cam->fovy = 45.0f;
  cam->target = (Vector3){0, 0, 0};
  return cam;
}

#endif // _APP_PLUG_H
