#include "rulepage_visual.h"
#include "virus.h"
#include "output_functions.h"

void mx_init_rulepage(t_rulepage *rulepage, SDL_Renderer *render, int window_width, int window_height) {
    int WI = window_width / 3.36;
    int HE = window_height / 13.6;

    SDL_Surface *blackbackg_surf = NULL;
    SDL_Surface *ok_surf = NULL;
    SDL_Surface *ok_active_surf = NULL;
    SDL_Surface *rules_surf = NULL;

    CreateRectangle(&rulepage->ok_r_pos, window_width*0.43, (window_height*0.9) - (HE/2), 0.5*WI, HE*1.2); 
    CreateRectangle(&rulepage->rules_pos, window_width*0.2, window_height*0.15, window_width*0.6, window_height*0.7); 

    const char* dir_blackback = "resources/UI/head_menu_background.bmp";
    const char* dir_ok = "resources/UI/exit_button.bmp";
    const char* dir_active_ok = "resources/UI/exit_active_button.bmp";
    const char* dir_rules = "resources/UI/rules.bmp";

    CreateTextureImage_from_bmp(dir_blackback, &blackbackg_surf, render, &rulepage->blackbackg_tex);
    CreateTextureImage_from_bmp(dir_ok, &ok_surf, render, &rulepage->ok_tex);
    CreateTextureImage_from_bmp(dir_active_ok, &ok_active_surf, render, &rulepage->ok_active_tex);
    CreateTextureImage_from_bmp(dir_rules, &rules_surf, render, &rulepage->rules_tex);
}

void mx_upload_rulepage_to_memory(t_rulepage *rulepage, SDL_Renderer *render) {
    SDL_RenderCopy(render, rulepage->blackbackg_tex, NULL, NULL);
    SDL_RenderCopy(render, rulepage->rules_tex, NULL, &rulepage->rules_pos);
    SDL_RenderCopy(render, rulepage->ok_tex, NULL, &rulepage->ok_r_pos);
}

void mx_upload_rulepage_to_memory_active_ok(t_rulepage *rulepage, SDL_Renderer *render) {
    SDL_RenderCopy(render, rulepage->blackbackg_tex, NULL, NULL);
    SDL_RenderCopy(render, rulepage->rules_tex, NULL, &rulepage->rules_pos);
    SDL_RenderCopy(render, rulepage->ok_active_tex, NULL, &rulepage->ok_r_pos);
}

void mx_destroy_rulepage_textures(t_rulepage *rulepage) {
    SDL_DestroyTexture(rulepage->rules_tex);
    SDL_DestroyTexture(rulepage->ok_tex); 
    SDL_DestroyTexture(rulepage->ok_active_tex);
    SDL_DestroyTexture(rulepage->blackbackg_tex);   
}

