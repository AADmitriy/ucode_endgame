#include "virus.h"
#include "output_functions.h"

void mx_process_game(t_topiman *topiman, int map_height, int map_width, int **map) {
    bool exit_game = false;
	int tile_under_virus = COIN;
    SDL_Event event;

    while (!exit_game) {
	    while (SDL_PollEvent(&(event))) {
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
				exit_game = true;
			}
			else if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) { //главное управление
					topiman->topiMove = (t_pos){0, 1};
				}
				else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
					topiman->topiMove = (t_pos){0, -1};
				}
				else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
					topiman->topiMove = (t_pos){1, 0};
				}
				else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
					topiman->topiMove = (t_pos){-1, 0};
				}
			}
			else if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    SDL_GetWindowSize(topiman->sdl.window, &topiman->sdl.window_width, &topiman->sdl.window_height);
                }
			}
		}

		if (mx_virus_catched_topi(topiman) && topiman->virus_frozen == 0) {
			play_defeat_sound(topiman->sound_manager);
			render_clearSDL(&topiman->sdl);

			exit_game = true;
			continue;
		}

		render_clearSDL(&topiman->sdl); //очистка цели рендеринга
	    
		mx_player_move(topiman, map_height, map_width, map); //поведение topi
		
        if(topiman->is_winner == true) {
            render_clearSDL(&topiman->sdl);

			exit_game = true;
			continue;
		}
        
		mx_virus(topiman, map_height, map_width, map, &tile_under_virus); //поведение virusa
        
		mx_draw_everything(topiman, topiman->sdl.renderer, topiman->animation_manager, map_height, map_width, map, &topiman->sdl);
        
		SDL_RenderPresent(topiman->sdl.renderer); //рендеринг
		SDL_Delay(240); //скорость передвижения
		
	}
}

