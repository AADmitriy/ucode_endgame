#include "virus.h"

#include "sound_manager.h"
#include "output_functions.h"

t_pos get_random_empty_space(int map_height, int map_width, int **map) {
    int empty_spaces_count = 0;

	for (int y = 0; y < map_height; y++) {
		for (int x = 0; x < map_width; x++) {
			if (map[y][x] == EMPTY) {
				empty_spaces_count++;
			}
		}
	}

	t_pos *all_empty_spaces = (t_pos*)malloc(sizeof(t_pos) * empty_spaces_count);
	int index = 0;

	for (int y = 0; y < map_height; y++) {
		for (int x = 0; x < map_width; x++) {
			if (map[y][x] == EMPTY) {
				all_empty_spaces[index] = (t_pos){x, y};
			    index++;
			}
		}
	}

	t_pos random_space = all_empty_spaces[rand() % index];

	free(all_empty_spaces);

	return random_space;
}

void mx_player_move(t_topiman *topiman, int map_height, int map_width, int **map) { //перемещение
    int new_y = topiman->topi.y + topiman->topiMove.y;
	int new_x = topiman->topi.x + topiman->topiMove.x;

	 

	if (new_y >= 0 && new_y < map_height && new_x >= 0 && new_x < map_width
		&& map[new_y][new_x] != WALL && map[new_y][new_x] != DOORS_CLOSED) {
		map[topiman->topi.y][topiman->topi.x] = EMPTY;
		topiman->topi.x = new_x;
		topiman->topi.y = new_y;
        
		if (map[topiman->topi.y][topiman->topi.x] == COIN) {

			play_collect_coin_sound(topiman->sound_manager);
			topiman->score += 10;
		}
		else if (map[topiman->topi.y][topiman->topi.x] == FREEZE) {
			play_freeze_sound(topiman->sound_manager);
			topiman->virus_frozen = 15;
		}
		else if (map[topiman->topi.y][topiman->topi.x] == ANTICEPTIC && topiman->anticeptic_apeared) {
			map[1][2] = DOORS_OPEN;
			topiman->score += 1000;
			//topiman->is_winner = true;
			play_victory_sound(topiman->sound_manager);
		}
		else if (map[topiman->topi.y][topiman->topi.x] == DOORS_OPEN) {
			topiman->is_winner = true;
		}
        if (topiman->score % 500 == 0) {
	    if(!topiman->spawn_freeze) {
            	t_pos empty_space = get_random_empty_space(map_height, map_width, map);
				map[empty_space.y][empty_space.x] = FREEZE;
	    	topiman->spawn_freeze = true;	
	    }
	} else {
		topiman->spawn_freeze = false;
	}

		map[topiman->topi.y][topiman->topi.x] = PLAYER;
	}
}

void putScore(t_topiman *topiman) {
	char buf[50] = "CASH: ";
	
	sprintf(buf + 6, "%d", topiman->score);

	topiman->sdl.surfaceScore = TTF_RenderText_Solid(topiman->sdl.font, buf, (SDL_Color){255, 0, 0, 255});

	topiman->sdl.textureScore = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->sdl.surfaceScore);
	topiman->sdl.rectScore.x = topiman->sdl.window_width/2.5;
	topiman->sdl.rectScore.y = 0;
	topiman->sdl.rectScore.w = topiman->sdl.window_width/4.8;
	topiman->sdl.rectScore.h = topiman->sdl.window_height/20;
	
	SDL_RenderCopy(topiman->sdl.renderer, topiman->sdl.textureScore, NULL, &(topiman->sdl.rectScore));
	SDL_FreeSurface(topiman->sdl.surfaceScore);
	SDL_DestroyTexture(topiman->sdl.textureScore);
}

