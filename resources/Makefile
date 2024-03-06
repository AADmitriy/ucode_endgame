
NAME = endgame

CC = gcc

CFLAGS =  -F. -Wall -Werror -Wextra

SDL_FLAGS = -framework SDL2 -framework SDL2_ttf -framework SDL2_image

OBJ = SDL.o main.o mx_topi.o mx_map.o

HEADER = virus.h

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)  $^ $(CFLAGS) $(SDL_FLAGS) -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	
reinstall: uninstall clean all

sdl2:
	cp -r SDL2_ttf.framework ~/Library/Frameworks/
	cp -r SDL2_image.framework ~/Library/Frameworks/
	cp -r SDL2.framework ~/Library/Frameworks/
