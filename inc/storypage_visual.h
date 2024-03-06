#pragma once 

#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

typedef struct s_storypage {
    SDL_Texture *bg_tex;
    SDL_Texture *btn_go_tex;
    SDL_Texture *btn_go_active_tex;
    SDL_Rect go_rect;
}              t_storypage;

void mx_init_storypage(t_storypage *storypage, SDL_Renderer *render, int window_width, int window_height);
void mx_upload_storypage_to_memory(t_storypage *storypage, SDL_Renderer *render);
void mx_destroy_storypage_textures(t_storypage *storypage);

