#include <dlfcn.h>
#include <raylib.h>
#include <stdio.h>

typedef void (*AppFunc_t)();

int main(void) {
  void *handle = dlopen("./build/libapp.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "Error loading shared library: %s\n", dlerror());
    return 1;
  }

  AppFunc_t Init = dlsym(handle, "Init");
  AppFunc_t Update = dlsym(handle, "Update");

  if (!Init || !Update) {
    fprintf(stderr, "Error loading symbols: %s\n", dlerror());
    dlclose(handle);
    return 1;
  }

  Init();

  while (!WindowShouldClose()) {
    Update();
  }

  CloseWindow();
  dlclose(handle);

  return 0;
}
