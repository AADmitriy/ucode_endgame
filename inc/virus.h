#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_mixer.h>

#include "sound_manager.h"

//#define WID 40*30 * 1.5
//#define HEIG 24*30+30 * 1.5
#define WID 1500
#define HEIG 800
#define W WID / 30
#define H HEIG / 30

#define EMPTY 0
#define COIN 1
#define WALL 2
#define PLAYER 3
#define ANTICEPTIC 4
#define VIRUS 5
#define DOORS_OPEN 6
#define DOORS_CLOSED 8
#define FREEDOM 7
#define FREEZE 9


typedef struct s_sdl {
	TTF_Font *font;
	SDL_Window *window;
	int window_width;
	int window_height;
	SDL_Renderer *renderer;
	SDL_Surface	*surfaceScore;
	SDL_Rect rectScore;
	SDL_Texture	*textureScore;
	SDL_Event e;
}			   t_sdl;


typedef struct s_pos {
	int	x;
	int	y;
}			   t_pos;

typedef struct s_animation_node {
	bool start;
	SDL_Texture *texture;
    struct s_animation_node *next_frame_node;
}              t_animation_node;

typedef struct s_animation_manager {
	t_animation_node *playerDownAnimation;
	t_animation_node *playerUpAnimation;
	t_animation_node *playerLeftAnimation;
	t_animation_node *playerRightAnimation;
	SDL_Texture *topiTexture;
	SDL_Rect topiRect;
	t_animation_node *enemyAnimation;
    SDL_Rect enemyRect;
	SDL_Texture *frozen_enemy_texture;
	

	SDL_Texture *antiTexture;
	SDL_Rect antiRect;

	SDL_Texture *coinTexture;
	SDL_Rect coinRect;

	SDL_Texture *freezeTexture;
	SDL_Rect freezeRect;

	SDL_Texture *wallTexture;
	SDL_Rect wallRect;

	SDL_Texture *floorTexture;
	SDL_Rect floorRect;

	SDL_Texture *grassTexture;
	SDL_Rect grassRect;

	SDL_Texture *doors_openTexture;
	SDL_Texture *doors_closedTexture;
	SDL_Rect doorsRect;

	SDL_Texture *wizardTexture;
	SDL_Rect wizardRect;
}              t_animation_manager;

typedef struct	s_topiman {
	t_sdl sdl;
	t_pos topi;
	t_pos virus;
	t_pos topiMove;
	
	t_animation_manager *animation_manager;
	t_sound_manager *sound_manager;

	int score;
	int stop;
	int virus_frozen;
	bool is_winner;
	bool anticeptic_apeared;
	bool spawn_freeze;

	SDL_Surface *messageSurface;
	SDL_Rect messageRect;
	SDL_Texture *mssageTexture;

}               t_topiman;

enum e_scene {
	MENU,
	RULE,
	GAME,
	EXIT,
};

void initSDL(t_sdl *sdl);
void destroySDL(t_topiman *topiman);
void render_clearSDL(t_sdl *sdl);
void free_animations(t_animation_manager *animations);

void default_position_topi(t_topiman *topiman);
int **mx_get_map(const char *filename, int *height, int *width);

void mx_process_game(t_topiman *topiman, int map_height, int map_width, int **map);
void mx_draw_everything(t_topiman *topiman, SDL_Renderer *renderer, t_animation_manager *animations, 
                        int map_height, int map_width, int **map, t_sdl *sdl);
void mx_player_move(t_topiman *topiman, int map_height, int map_width, int **map);
void mx_virus(t_topiman *topiman, int map_height, int map_width, int **map, int *tile_under_virus);
void putScore(t_topiman *topiman);
bool mx_virus_catched_topi(t_topiman *topi);
bool is_coordinates_in_rectangle(int x, int y, SDL_Rect rectangle);
bool mx_menu(SDL_Renderer *render, t_sdl *sdl);
bool mx_finish_game(t_topiman *topiman);

bool show_story(SDL_Renderer *render, t_sdl *sdl);

void CreateRectangle(SDL_Rect* object, int x, int y, int w, int h);
SDL_Texture* loadTextTexture(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color color);
void CreateTextureImage_from_bmp(const char *file, SDL_Surface **surface, SDL_Renderer *render, SDL_Texture **texture);

