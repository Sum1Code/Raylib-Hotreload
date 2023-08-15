CC=clang
CFLAGS=-Wall -Wextra 
BIN=app

OBJDIR=build
SRCDIR=src
INCLDIR=include

OBJS=$(wildcard $(OBJDIR)/*.o)
APPLIB=libapp.so
LIBS=-lraylib -ldl

.PHONY:watch run app main final

default: watch

run: final
	./$(BIN)

final: app main 
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) -L./build $(LIBS)  

app: $(SRCDIR)/app.c
	$(CC) $(CFLAGS) -shared -fPIC -o ./build/$(APPLIB) $^
main: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c -o ./build/$@.o $^

watch:
	@while true; do \
		make run; \
		sleep 1; \
	done
