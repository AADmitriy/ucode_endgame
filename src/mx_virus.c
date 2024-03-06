#include "virus.h"
#include "output_functions.h"

void mx_virus(t_topiman *topiman, int map_height, int map_width, int **map, int *tile_under_virus) {
	
	if(topiman->virus_frozen > 0) {
		if (!mx_virus_catched_topi(topiman)) {
			map[topiman->virus.y][topiman->virus.x] = VIRUS;
		}
		topiman->virus_frozen--;
		return;
	}
	(void)map_height;
	(void)map_width;
	int x = topiman->topi.x - topiman->virus.x;
	int y = topiman->topi.y - topiman->virus.y;
	int mod_x = x < 0 ? x * -1 : x;
	int mod_y = y < 0 ? y * -1 : y;

    if (*tile_under_virus == COIN) {
	    map[topiman->virus.y][topiman->virus.x] = COIN;
	}
	else if (*tile_under_virus == ANTICEPTIC){
		map[topiman->virus.y][topiman->virus.x] = ANTICEPTIC;
	}
    else {
        map[topiman->virus.y][topiman->virus.x] = EMPTY;
    }

	if (mod_x >= mod_y && x > 0) {
        if (map[topiman->virus.y][topiman->virus.x + 1] != WALL) {
            topiman->virus.x++;
        }
        else {
            if (map[topiman->virus.y + 1][topiman->virus.x] != WALL) {
                topiman->virus.y++;
            } else if (map[topiman->virus.y - 1][topiman->virus.x] != WALL) {
                topiman->virus.y--;
            }
        }
    } 
    else if (mod_x >= mod_y && x < 0) {
        if (map[topiman->virus.y][topiman->virus.x - 1] != WALL) {
            topiman->virus.x--;
        }
        else {
            if (map[topiman->virus.y + 1][topiman->virus.x] != WALL) {
                topiman->virus.y++;
            } else if (map[topiman->virus.y - 1][topiman->virus.x] != WALL) {
                topiman->virus.y--;
            }
        }
    } 
    else if (mod_x < mod_y && y > 0) {
        if (map[topiman->virus.y + 1][topiman->virus.x] != WALL) {
            topiman->virus.y++;
        }
        else {
            if (map[topiman->virus.y][topiman->virus.x + 1] != WALL) {
                topiman->virus.x++;
            } else if (map[topiman->virus.y][topiman->virus.x - 1] != WALL) {
                topiman->virus.x--;
            }
        }
    }
    else if (mod_x < mod_y && y < 0) {
        if (map[topiman->virus.y - 1][topiman->virus.x] != WALL) {
            topiman->virus.y--;
        }
        else {
            if (map[topiman->virus.y][topiman->virus.x + 1] != WALL) {
                topiman->virus.x++;
            } else if (map[topiman->virus.y][topiman->virus.x - 1] != WALL) {
                topiman->virus.x--;
            }
        }
    }
    
	*tile_under_virus = map[topiman->virus.y][topiman->virus.x];

	map[topiman->virus.y][topiman->virus.x] = VIRUS;
}

