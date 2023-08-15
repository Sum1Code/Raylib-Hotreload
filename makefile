CC=clang
CFLAGS=-Wall -Wextra 
BIN=app

OBJDIR=build
SRCDIR=src

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
LIBS=-lraylib

.PHONY: run build clean

default: run
run: build
	./$(BIN)

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(OBJDIR)/* $(BIN)
