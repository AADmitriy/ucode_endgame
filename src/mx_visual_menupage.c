#include "menupage_visual.h"
#include "virus.h"

void mx_init_menupage(t_menupage *menupage, SDL_Renderer *render, int window_width, int window_height) {
    SDL_Surface *background_surf = NULL;
    SDL_Surface *start_active_surf = NULL;
    SDL_Surface *rules_surf = NULL;
    SDL_Surface *exit_surf = NULL;
    SDL_Surface *start_surf = NULL;
    SDL_Surface *rules_active_surf = NULL;
    SDL_Surface *exit_active_surf = NULL;

    CreateRectangle(&menupage->start_pos, window_width*0.34, window_height*0.25, window_width*0.3, window_height*0.2);
    CreateRectangle(&menupage->rules_pos, window_width*0.41, window_height*0.5, window_width*0.2, window_height*0.15);
    CreateRectangle(&menupage->exit_pos, window_width*0.44, window_height*0.70, window_width*0.14, window_height*0.12);

    const char* dir_background = "resources/UI/head_menu_background.bmp";
    const char* dir_start = "resources/UI/start_button.bmp";
    const char* dir_rules = "resources/UI/rules_button.bmp";
    const char* dir_exit = "resources/UI/exit_button.bmp";
    const char* dir_start_active = "resources/UI/start_active_button.bmp";
    const char* dir_rules_active = "resources/UI/rules_active_button.bmp";
    const char* dir_exit_active = "resources/UI/exit_active_button.bmp";

    //MENU TEXTURES
    CreateTextureImage_from_bmp(dir_background, &background_surf, render, &menupage->background_tex);
    CreateTextureImage_from_bmp(dir_start, &start_surf, render, &menupage->start_tex);
    CreateTextureImage_from_bmp(dir_start_active, &start_active_surf, render, &menupage->start_active_tex);
    CreateTextureImage_from_bmp(dir_rules, &rules_surf, render, &menupage->rules_tex);
    CreateTextureImage_from_bmp(dir_rules_active, &rules_active_surf, render, &menupage->rules_active_tex);
    CreateTextureImage_from_bmp(dir_exit, &exit_surf, render, &menupage->exit_tex);
    CreateTextureImage_from_bmp(dir_exit_active, &exit_active_surf, render, &menupage->exit_active_tex);
}

void mx_upload_menupage_to_memory(t_menupage *menupage, SDL_Renderer *render) {
    SDL_RenderCopy(render, menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(render, menupage->start_tex, NULL, &menupage->start_pos);
    SDL_RenderCopy(render, menupage->rules_tex, NULL, &menupage->rules_pos);
    SDL_RenderCopy(render, menupage->exit_tex, NULL, &menupage->exit_pos);
}

void mx_upload_menupage_to_memory_start_active(t_menupage *menupage, SDL_Renderer *render) {
    SDL_RenderCopy(render, menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(render, menupage->start_active_tex, NULL, &menupage->start_pos);
    SDL_RenderCopy(render, menupage->rules_tex, NULL, &menupage->rules_pos);
    SDL_RenderCopy(render, menupage->exit_tex, NULL, &menupage->exit_pos);
}

void mx_upload_menupage_to_memory_rules_active(t_menupage *menupage, SDL_Renderer *render) {
    SDL_RenderCopy(render, menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(render, menupage->start_tex, NULL, &menupage->start_pos);
    SDL_RenderCopy(render, menupage->rules_active_tex, NULL, &menupage->rules_pos);
    SDL_RenderCopy(render, menupage->exit_tex, NULL, &menupage->exit_pos);
}

void mx_upload_menupage_to_memory_exit_active(t_menupage *menupage, SDL_Renderer *render) {
    SDL_RenderCopy(render, menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(render, menupage->start_tex, NULL, &menupage->start_pos);
    SDL_RenderCopy(render, menupage->rules_tex, NULL, &menupage->rules_pos);
    SDL_RenderCopy(render, menupage->exit_active_tex, NULL, &menupage->exit_pos);
}

void mx_destroy_menupage_textures(t_menupage *menupage) {
    SDL_DestroyTexture(menupage->background_tex);
    SDL_DestroyTexture(menupage->start_active_tex);
    SDL_DestroyTexture(menupage->rules_tex);
    SDL_DestroyTexture(menupage->exit_tex);
    SDL_DestroyTexture(menupage->start_tex);
    SDL_DestroyTexture(menupage->rules_active_tex);
    SDL_DestroyTexture(menupage->exit_active_tex);
}

