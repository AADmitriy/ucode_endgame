#pragma once 

#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

typedef struct s_rulepage {
    SDL_Texture *blackbackg_tex;
    SDL_Texture *ok_tex;
    SDL_Texture *ok_active_tex;
    SDL_Rect ok_r_pos;
    SDL_Texture *rules_tex;
    SDL_Rect rules_pos;
}              t_rulepage;

void mx_init_rulepage(t_rulepage *rulepage, SDL_Renderer *render, int window_width, int window_height);
void mx_upload_rulepage_to_memory(t_rulepage *rulepage, SDL_Renderer *render);
void mx_upload_rulepage_to_memory_active_ok(t_rulepage *rulepage, SDL_Renderer *render);
void mx_destroy_rulepage_textures(t_rulepage *rulepage);

