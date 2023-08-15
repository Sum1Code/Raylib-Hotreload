#include <dlfcn.h>
#include <raylib.h>

typedef void (*AppFunc_t)();

int main(void) {
  void *handle = dlopen("./build/libapp.so", RTLD_LAZY);
  AppFunc_t Init = dlsym(handle, "Init");
  AppFunc_t Update = dlsym(handle, "Update");

  Init();
  while (!WindowShouldClose()) {
    Update();
  }
  return 0;
}
