#include "finish_menupage_visual.h"
#include "virus.h"

//#define WIDTH 1200
//#define HEIGHT 750
//#define WI (WIDTH/3.36)
//#define HE (HEIGHT/13.6)

void mx_init_finish_menupage(t_finish_menupage *finish_menupage, SDL_Renderer *renderer, bool is_win, int window_width, int window_height) {
    //int wi = window_width / 3.36;
    int he = window_height / 13.6;
    const char *background_file;
    if (is_win) {
        background_file = "resources/UI/win_background_1.bmp";
    }
    else {
        background_file = "resources/UI/gameover_background.bmp";
    }

    const char* dir_yes = "resources/UI/yes_button.bmp";
    const char* dir_yes_active = "resources/UI/yes_active_button.bmp";
    const char* dir_no = "resources/UI/no_button.bmp";
    const char* dir_no_active = "resources/UI/no_active_button.bmp";

    SDL_Surface *background_surf = NULL;
    SDL_Surface *yes_surf = NULL;
    SDL_Surface *yes_active_surf = NULL;
    SDL_Surface *no_surf = NULL;
    SDL_Surface *no_active_surf = NULL;

    CreateRectangle(&finish_menupage->yes_rect, window_width * 0.30, window_height * 0.75, 0.1 * window_width, he * 2.6);
    CreateRectangle(&finish_menupage->no_rect, window_width * 0.56, window_height * 0.75, 0.1 * window_width, he * 2.6);

    CreateTextureImage_from_bmp(dir_yes, &yes_surf, renderer, &finish_menupage->yes_texture);
    CreateTextureImage_from_bmp(dir_yes_active, &yes_active_surf, renderer, &finish_menupage->yes_active_texture);
    CreateTextureImage_from_bmp(dir_no, &no_surf, renderer, &finish_menupage->no_texture);
    CreateTextureImage_from_bmp(dir_no_active, &no_active_surf, renderer, &finish_menupage->no_active_texture);
    CreateTextureImage_from_bmp(background_file, &background_surf, renderer, &finish_menupage->background_tex);
}

void mx_upload_finish_menupage_to_memory(t_finish_menupage *finish_menupage, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, finish_menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(renderer, finish_menupage->yes_texture, NULL, &finish_menupage->yes_rect);
    SDL_RenderCopy(renderer, finish_menupage->no_texture, NULL, &finish_menupage->no_rect);
}

void mx_upload_finish_menupage_to_memory_yes_active(t_finish_menupage *finish_menupage, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, finish_menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(renderer, finish_menupage->yes_active_texture, NULL, &finish_menupage->yes_rect);
    SDL_RenderCopy(renderer, finish_menupage->no_texture, NULL, &finish_menupage->no_rect);
}

void mx_upload_finish_menupage_to_memory_no_active(t_finish_menupage *finish_menupage, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, finish_menupage->background_tex, NULL, NULL);
    SDL_RenderCopy(renderer, finish_menupage->yes_texture, NULL, &finish_menupage->yes_rect);
    SDL_RenderCopy(renderer, finish_menupage->no_active_texture, NULL, &finish_menupage->no_rect);
}

void mx_destroy_finish_menupage_textures(t_finish_menupage *finish_menupage) {
    SDL_DestroyTexture(finish_menupage->background_tex);
    SDL_DestroyTexture(finish_menupage->yes_texture);
    SDL_DestroyTexture(finish_menupage->yes_active_texture);
    SDL_DestroyTexture(finish_menupage->no_texture);
    SDL_DestroyTexture(finish_menupage->no_active_texture);
}

