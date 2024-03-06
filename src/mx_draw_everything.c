#include "virus.h"
#include "output_functions.h"
#include "animation_manager.h"



void mx_draw_everything(t_topiman *topiman, SDL_Renderer *renderer, t_animation_manager *animations, 
                        int map_height, int map_width, int **map, t_sdl *sdl) {
	SDL_Rect rect;
	int window_width = sdl->window_width;
	int window_height = sdl->window_height;

	rect = (SDL_Rect) {0, 0, window_width/40, window_height/25}; //размер кубиков
	
	for (int y = 0; y < map_height; y++) {
		rect.x = 0;
		for (int x = 0; x < map_width; x++) {
            if (map[y][x] == EMPTY) {
				draw_floor(rect, renderer, animations, window_width, window_height);
			}
			if (map[y][x] == VIRUS) {
				if(topiman->virus_frozen > 0) {
					draw_frozen_enemy(rect, renderer, animations, window_width, window_height);
				} else {
					draw_enemy(rect, renderer, animations, window_width, window_height);
				}
			}
			if (map[y][x] == PLAYER) {
				if (y == 0) {
					draw_freedom(rect, renderer, animations, window_width, window_height);
					draw_player_movement_animation(rect, renderer, animations, topiman, window_width, window_height);
				}
				else if (y == 1 && x == 2) {
					draw_doors_open(rect, renderer, animations, window_width, window_height);
					draw_player_movement_animation(rect, renderer, animations, topiman, window_width, window_height);
				}
				else {
					draw_floor(rect, renderer, animations, window_width, window_height);
				    draw_player_movement_animation(rect, renderer, animations, topiman, window_width, window_height);
				}
			}
            if (map[y][x] == DOORS_CLOSED) {
				draw_doors_closed(rect, renderer, animations, window_width, window_height);
			}
			if (map[y][x] == DOORS_OPEN) {
				draw_doors_open(rect, renderer, animations, window_width, window_height);
			}
			if (map[y][x] == FREEDOM) {
				draw_freedom(rect, renderer, animations, window_width, window_height);

				if (y == 0 && x == 1) {
					draw_wizard(rect, renderer, animations, window_width, window_height);
				}
			}
			if (map[y][x] == ANTICEPTIC) {
				draw_floor(rect, renderer, animations, window_width, window_height);
				if (topiman->score >= 2000) {
					topiman->anticeptic_apeared = true;
					draw_anticeptic(rect, renderer,  animations, window_width, window_height);
			    }
			}
			if (map[y][x] == WALL) {
				draw_wall(rect, renderer, animations, window_width, window_height);
			}
			else if (map[y][x] == COIN) {
				draw_coin(rect, renderer, animations, window_width, window_height);
			} 
			else if (map[y][x] == FREEZE) {
				draw_freeze(rect, renderer, animations, window_width, window_height);
			}

			if (topiman->anticeptic_apeared == false && map[11][14] != ANTICEPTIC && map[11][14] != PLAYER && map[11][14] != VIRUS) {
				map[11][14] = ANTICEPTIC;
			}
			
			rect.x += window_width/40;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += window_height/25;
	}
	
	putScore(topiman);
}

