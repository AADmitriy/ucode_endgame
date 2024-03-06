CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

OBJDIR = ./obj
SRCDIR = ./src
HEADERFILES = ./inc

SRCFILES := $(wildcard $(SRCDIR)/*.c)
OBJFILES := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))

BINARY = endgame

all: $(BINARY)

$(BINARY): $(OBJFILES)
	$(CC) $(CFLAGS) -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer $^ -o $@

$(OBJFILES): | $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERFILES)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADERFILES) -I "/usr/include/SDL2/"

$(OBJDIR):
	mkdir -p $@

uninstall: clean
	rm -f $(BINARY)

clean:
	rm -r -f $(OBJDIR)

reinstall: uninstall all
