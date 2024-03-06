#pragma once

#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

typedef struct s_menupage {
    SDL_Texture *background_tex;
    SDL_Texture *start_active_tex;
    SDL_Texture *rules_tex;
    SDL_Texture *exit_tex;
    SDL_Texture *start_tex;
    SDL_Texture *rules_active_tex;
    SDL_Texture *exit_active_tex;
    SDL_Rect start_pos;
    SDL_Rect rules_pos;
    SDL_Rect exit_pos;
    SDL_Rect ok_r_pos;
}              t_menupage;

enum e_button {
    START_BUTTON,
    RULES_BUTTON,
    EXIT_BUTTON,
    NOBUTTON,
};

void mx_init_menupage(t_menupage *menupage, SDL_Renderer *render, int window_width, int window_height);
void mx_upload_menupage_to_memory(t_menupage *menupage, SDL_Renderer *render);
void mx_upload_menupage_buttons_to_memory(t_menupage *menupage, SDL_Renderer *render);
void mx_upload_menupage_to_memory_start_active(t_menupage *menupage, SDL_Renderer *render);
void mx_upload_menupage_to_memory_rules_active(t_menupage *menupage, SDL_Renderer *render);
void mx_upload_menupage_to_memory_exit_active(t_menupage *menupage, SDL_Renderer *render);
void mx_destroy_menupage_textures(t_menupage *menupage);

