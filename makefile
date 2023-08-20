CC=clang
CFLAGS=-Wall -Wextra 
BIN=app

OBJDIR=build
SRCDIR=src
INCLDIR=include

OBJS=$(wildcard $(OBJDIR)/*.o)
APPLIB=libapp.so
LIBS=-lraylib -ldl

.PHONY: run app main final

default: final

run: final
	./$(BIN)

final: app main 
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) -L./build $(LIBS)  

app: $(SRCDIR)/app.c
	mkdir -p ./build
	$(CC) $(CFLAGS) -shared -fPIC -I$(INCLDIR) -o ./build/$(APPLIB) $^
main: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c -o ./build/$@.o $^

