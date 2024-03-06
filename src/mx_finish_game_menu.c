#include "virus.h"
#include "output_functions.h"
#include "finish_menupage_visual.h"
#include "sound_manager.h"

bool process_finish_game_menu_and_cleanup(t_finish_menupage *finish_menupage, SDL_Renderer *renderer, bool is_win) {
    int x, y;
    int windowWidth, windowHeight;
    bool exit_menu = false;
    enum e_scene current_scene = MENU;
    enum e_button current_button = NOBUTTON;
    SDL_Event event;

    while (!exit_menu) {
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit_menu = true;
                    break;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if (is_coordinates_in_rectangle(x, y, finish_menupage->yes_rect) && current_button != YES_BUTTON) {
                        current_button = YES_BUTTON;
                        SDL_RenderClear(renderer);
                        mx_upload_finish_menupage_to_memory_yes_active(finish_menupage, renderer);
                    }
                    else if (is_coordinates_in_rectangle(x, y, finish_menupage->no_rect) && current_button != NO_BUTTON) {
                        current_button = NO_BUTTON;
                        SDL_RenderClear(renderer);
                        mx_upload_finish_menupage_to_memory_no_active(finish_menupage, renderer);
                    }
                    else if (current_button != NOBUTTON
                             && !is_coordinates_in_rectangle(x, y, finish_menupage->yes_rect)
                             && !is_coordinates_in_rectangle(x, y, finish_menupage->no_rect)) {
                        current_button = NOBUTTON;
                        SDL_RenderClear(renderer);
                        mx_upload_finish_menupage_to_memory(finish_menupage, renderer);
                    }
                    SDL_RenderPresent(renderer);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    x = event.button.x;
                    y = event.button.y;

                    if (is_coordinates_in_rectangle(x, y, finish_menupage->yes_rect)) {
                        current_scene = GAME;
                        exit_menu = true;
                    }
                    else if (is_coordinates_in_rectangle(x, y, finish_menupage->no_rect)) {
                        current_scene = EXIT;
                        exit_menu = true;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        windowWidth = event.window.data1;
                        windowHeight = event.window.data2;
                        mx_init_finish_menupage(finish_menupage, renderer, is_win, windowWidth, windowHeight);
                        SDL_RenderClear(renderer);
                        mx_upload_finish_menupage_to_memory(finish_menupage, renderer);
                    }
            }
        }

        SDL_RenderPresent(renderer);
    }

    return current_scene == GAME;
}

bool mx_finish_game(t_topiman *topiman) {
    if (topiman->is_winner) {
        play_victory_background_music(topiman->sound_manager);
    }
    else {
        play_defeat_background_music(topiman->sound_manager);
    }
    
    SDL_Renderer *renderer = topiman->sdl.renderer;

    t_finish_menupage *finish_menupage = (t_finish_menupage*)malloc(sizeof(t_finish_menupage));

    mx_init_finish_menupage(finish_menupage, renderer, topiman->is_winner, topiman->sdl.window_width, topiman->sdl.window_height);

    SDL_RenderClear(renderer);

    mx_upload_finish_menupage_to_memory(finish_menupage, renderer);

    SDL_RenderPresent(renderer);

    bool restart_game = process_finish_game_menu_and_cleanup(finish_menupage, renderer, topiman->is_winner);

    mx_destroy_finish_menupage_textures(finish_menupage);

    stop_background_music();

    return restart_game;
}

