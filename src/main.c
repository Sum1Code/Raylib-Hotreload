#include <dlfcn.h>
#include <raylib.h>
#include <stdio.h>

typedef void (*AppFunc_t)();
AppFunc_t Init;
AppFunc_t Update;

void *handle;
bool reload() {
  handle = dlopen("./build/libapp.so", RTLD_LAZY);

  if (!handle) {
    fprintf(stderr, "Error loading shared library: %s\n", dlerror());
    return 0;
  }

  Init = dlsym(handle, "Init");
  Update = dlsym(handle, "Update");

  if (!Init || !Update) {
    fprintf(stderr, "Error loading symbols: %s\n", dlerror());
    dlclose(handle);
    return 0;
  }

  return 1;
}

int main(void) {
  if (!reload()) {
    fprintf(stderr, "Error Reloading: %s\n", dlerror());
    dlclose(handle);
    return 1;
  }
  Init();

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_R)) {
      dlclose(handle);
      reload();
    }
    Update();
  }

  CloseWindow();
  dlclose(handle);

  return 0;
}
