#pragma once

#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "virus.h"

typedef struct s_finish_menupage {
    SDL_Texture *background_tex;
    SDL_Rect yes_rect;
    SDL_Texture *yes_texture;
    SDL_Texture *yes_active_texture;
    SDL_Rect no_rect;
    SDL_Texture *no_texture;
    SDL_Texture *no_active_texture;
}              t_finish_menupage;

enum e_button {
    YES_BUTTON,
    NO_BUTTON,
    NOBUTTON,
};

void mx_init_finish_menupage(t_finish_menupage *finish_menupage, SDL_Renderer *renderer, bool is_win, int window_width, int window_height);
void mx_upload_finish_menupage_to_memory(t_finish_menupage *finish_menupage, SDL_Renderer *renderer);
void mx_destroy_finish_menupage_textures(t_finish_menupage *finish_menupage);
void mx_upload_finish_menupage_to_memory_yes_active(t_finish_menupage *finish_menupage, SDL_Renderer *renderer);
void mx_upload_finish_menupage_to_memory_no_active(t_finish_menupage *finish_menupage, SDL_Renderer *renderer);


