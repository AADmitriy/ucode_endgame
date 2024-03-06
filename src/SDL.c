#include "virus.h"
#include "output_functions.h"
#include "animation_nodes.h"

void initSDL(t_sdl *sdl) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 6, 2048);
	int font_size = 12;
	const char *fontfile = "resources/font.ttf";

	sdl->font = TTF_OpenFont(fontfile, font_size);

	sdl->window = SDL_CreateWindow("Topi", 0, 0, WID, HEIG,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	sdl->window_width = WID;
	sdl->window_height = HEIG;
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
			SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(sdl->renderer);
}

void destroySDL(t_topiman *topiman) {
	SDL_DestroyRenderer(topiman->sdl.renderer);
	SDL_DestroyWindow(topiman->sdl.window);
	IMG_Quit();
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
}

void render_clearSDL(t_sdl *sdl) {
	//SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);
}

void free_animations(t_animation_manager *animation_manager) {
	SDL_DestroyTexture(animation_manager->antiTexture);
	SDL_DestroyTexture(animation_manager->coinTexture);
	SDL_DestroyTexture(animation_manager->wallTexture);
	SDL_DestroyTexture(animation_manager->floorTexture);
	SDL_DestroyTexture(animation_manager->grassTexture);
    
	clean_animation_list(&animation_manager->playerDownAnimation);
	clean_animation_list(&animation_manager->playerUpAnimation);
	clean_animation_list(&animation_manager->playerLeftAnimation);
	clean_animation_list(&animation_manager->playerRightAnimation);
	clean_animation_list(&animation_manager->enemyAnimation);
	
	SDL_DestroyTexture(animation_manager->topiTexture);
}

