#include "virus.h"
#include "rulepage_visual.h"
#include "menupage_visual.h"
#include "output_functions.h"

bool is_coordinates_in_rectangle(int x, int y, SDL_Rect rectangle) {
    return x > rectangle.x && x < rectangle.x + rectangle.w 
           && y > rectangle.y && y < rectangle.y + rectangle.h;
}

bool process_rulepage(t_rulepage *rulepage, SDL_Renderer *render){
    enum e_scene current_scene = RULE;
    enum e_button current_button = NOBUTTON;
    bool exit_rule_page = false;
    int x, y;
    int windowWidth, windowHeight;
    SDL_Event event;
    
    while (!exit_rule_page) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:      /*is_menu_running by X in the right upper corner*/
                    current_scene = EXIT;
                    exit_rule_page = true;
                    break;
                case SDL_MOUSEMOTION:   /*MOUSE MOTION*/
                    x = event.motion.x;
                    y = event.motion.y;

                    if (is_coordinates_in_rectangle(x, y, rulepage->ok_r_pos) && current_button != EXIT_BUTTON) {
                        current_button = EXIT_BUTTON;
                        SDL_RenderClear(render);
                        mx_upload_rulepage_to_memory_active_ok(rulepage, render);
                    }
                    else if (current_button != NOBUTTON && !is_coordinates_in_rectangle(x, y, rulepage->ok_r_pos)){
                        current_button = NOBUTTON;
                        SDL_RenderClear(render);
                        mx_upload_rulepage_to_memory(rulepage, render);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN: /*YOU CLICKED 1 time*/
                    x = event.button.x;
                    y = event.button.y;

                    if (is_coordinates_in_rectangle(x, y, rulepage->ok_r_pos)) {
                        current_scene = MENU;
                        exit_rule_page = true;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        windowWidth = event.window.data1;
                        windowHeight = event.window.data2;
                        mx_init_rulepage(rulepage, render, windowWidth, windowHeight);
                        SDL_RenderClear(render);
                        mx_upload_rulepage_to_memory(rulepage, render);
                    }
            }
            SDL_RenderPresent(render);
        }
    }

    return current_scene == MENU;
}

enum e_scene process_menupage(t_menupage *menupage, SDL_Renderer *render) {
    enum e_scene current_scene = MENU;
    enum e_button current_button = NOBUTTON;
    bool exit_menu_page = false;
    int x, y;
    int windowWidth, windowHeight;
    SDL_Event event;

    while (!exit_menu_page) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit_menu_page = true;
                    current_scene = EXIT;
                    break;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if (is_coordinates_in_rectangle(x, y, menupage->start_pos) && current_button != START_BUTTON) {
                        current_button = START_BUTTON;
                        SDL_RenderClear(render);
                        mx_upload_menupage_to_memory_start_active(menupage, render);   
                    }
                    else if (is_coordinates_in_rectangle(x, y, menupage->rules_pos) && current_button != RULES_BUTTON) {
                        current_button = RULES_BUTTON;
                        SDL_RenderClear(render);
                        mx_upload_menupage_to_memory_rules_active(menupage, render);
                    }
                    else if (is_coordinates_in_rectangle(x, y, menupage->exit_pos) && current_button != EXIT_BUTTON) {
                        current_button = EXIT_BUTTON;
                        SDL_RenderClear(render);
                        mx_upload_menupage_to_memory_exit_active(menupage, render);
                    }
                    else if (current_button != NOBUTTON && !is_coordinates_in_rectangle(x, y, menupage->start_pos)
                             && !is_coordinates_in_rectangle(x, y, menupage->rules_pos)
                             && !is_coordinates_in_rectangle(x, y, menupage->exit_pos)) {
                        current_button = NOBUTTON;
                        SDL_RenderClear(render);
                        mx_upload_menupage_to_memory(menupage, render);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN: /*YOU CLICKED 1 time*/
                    x = event.button.x;
                    y = event.button.y;

                    if (is_coordinates_in_rectangle(x, y, menupage->rules_pos)) {
                        current_scene = RULE;
                        exit_menu_page = true;
                    }
                    else if (is_coordinates_in_rectangle(x, y, menupage->exit_pos)) {
                        current_scene = EXIT;
                        exit_menu_page = true;
                    }
                    else if (is_coordinates_in_rectangle(x, y, menupage->start_pos)) {
                        current_scene = GAME;
                        exit_menu_page = true;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        windowWidth = event.window.data1;
                        windowHeight = event.window.data2;
                        mx_init_menupage(menupage, render, windowWidth, windowHeight);
                        SDL_RenderClear(render);
                        mx_upload_menupage_to_memory(menupage, render);
                    }
            }

            SDL_RenderPresent(render);
        }
    }

    return current_scene;
}

bool mx_menu(SDL_Renderer *render, t_sdl *sdl) {
    bool is_menu_running = true;
    bool return_to_menu = true;
    enum e_scene current_scene = MENU;

    t_rulepage *rulepage = (t_rulepage*)malloc(sizeof(t_rulepage));
    t_menupage *menupage = (t_menupage*)malloc(sizeof(t_menupage));

    mx_init_rulepage(rulepage, render, WID, HEIG);
    mx_init_menupage(menupage, render, WID, HEIG);
    
    SDL_RenderClear(render);

    mx_upload_menupage_to_memory(menupage, render);

    SDL_RenderPresent(render);

    while (is_menu_running) {
        current_scene = process_menupage(menupage, render);
        
        if (current_scene == RULE) {
            SDL_GetWindowSize(sdl->window, &sdl->window_width, &sdl->window_height);
            mx_init_rulepage(rulepage, render, sdl->window_width, sdl->window_height);
            
            mx_upload_rulepage_to_memory(rulepage, render);
            
            SDL_RenderPresent(render);
            return_to_menu = process_rulepage(rulepage, render);
        }
        else {
            is_menu_running = false;
        }

        if (!return_to_menu) {
            current_scene = EXIT;
            is_menu_running = false;
        }
        else {
            SDL_GetWindowSize(sdl->window, &sdl->window_width, &sdl->window_height);
            mx_init_menupage(menupage, render, sdl->window_width, sdl->window_height);
            mx_upload_menupage_to_memory(menupage, render);
            SDL_RenderPresent(render);
        }
           
    }
    
    SDL_RenderPresent(render);

    mx_destroy_rulepage_textures(rulepage);
    mx_destroy_menupage_textures(menupage);

    free(rulepage);
    free(menupage);

    return current_scene == GAME;
}

