#include "animation_manager.h"
#include "output_functions.h"

void draw_wall(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    animations->wallRect = (SDL_Rect){rect.x, rect.y, window_width/41, window_height/26};
	SDL_RenderCopy(renderer, animations->wallTexture, NULL, &(animations->wallRect));
}

void draw_coin(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    draw_floor(rect, renderer, animations, window_width, window_height);

    animations->coinRect = (SDL_Rect){rect.x + window_width/240, rect.y + window_height/150, window_width/67, window_height/41};
	SDL_RenderCopy(renderer, animations->coinTexture, NULL, &(animations->coinRect));
	SDL_RenderDrawPoint(renderer, rect.x + window_width/80, rect.y + window_height/50);
	SDL_RenderDrawPoint(renderer, rect.x + window_width/80, rect.y + window_height/41);
	SDL_RenderDrawPoint(renderer, rect.x + window_width/80, rect.y + window_height/41);
}

void draw_freeze(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    draw_floor(rect, renderer, animations, window_width, window_height);

    animations->freezeRect = (SDL_Rect){rect.x + window_width/240, rect.y + window_height/150, window_width/67, window_height/41};
	SDL_RenderCopy(renderer, animations->freezeTexture, NULL, &(animations->freezeRect));
	SDL_RenderDrawPoint(renderer, rect.x + window_width/80, rect.y + window_height/50);
	SDL_RenderDrawPoint(renderer, rect.x + window_width/80, rect.y + window_height/41);
	SDL_RenderDrawPoint(renderer, rect.x + window_width/80, rect.y + window_height/41);
}

void draw_freedom(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    animations->grassRect = (SDL_Rect){rect.x, rect.y, window_width/40, window_height/25};
	SDL_RenderCopy(renderer, animations->grassTexture, NULL, &(animations->grassRect));
}

void draw_doors_closed(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    draw_freedom(rect, renderer, animations, window_width, window_height);

    animations->doorsRect = (SDL_Rect){rect.x, rect.y, window_width/40, window_height/25};
	SDL_RenderCopy(renderer, animations->doors_closedTexture, NULL, &(animations->doorsRect));
}

void draw_doors_open(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    draw_freedom(rect, renderer, animations, window_width, window_height);

    animations->doorsRect = (SDL_Rect){rect.x, rect.y, window_width/40, window_height/25};
	SDL_RenderCopy(renderer, animations->doors_openTexture, NULL, &(animations->doorsRect));
}


void draw_anticeptic(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    draw_floor(rect, renderer, animations, window_width, window_height);

    animations->antiRect = (SDL_Rect){rect.x + window_width/240, rect.y, window_width/60, window_height/25};
	SDL_RenderCopy(renderer, animations->antiTexture, NULL, &(animations->antiRect));
}

void draw_enemy(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    draw_floor(rect, renderer, animations, window_width, window_height);

    animations->enemyRect = (SDL_Rect){rect.x, rect.y - window_height/150, window_width/40, window_height/25};

	t_animation_node *current_frame_node = animations->enemyAnimation;
    animations->enemyAnimation = current_frame_node->next_frame_node;

	SDL_RenderCopy(renderer, current_frame_node->texture, NULL, &(animations->enemyRect));
}

void draw_frozen_enemy(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
	draw_floor(rect, renderer, animations, window_width, window_height);
	
	animations->enemyRect = (SDL_Rect){rect.x, rect.y - window_height/150, window_width/40, window_height/25};

	SDL_RenderCopy(renderer, animations->frozen_enemy_texture, NULL, &(animations->enemyRect));
}

void draw_wizard(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    animations->wizardRect = (SDL_Rect){rect.x, rect.y, window_width/40, window_height/25};
	SDL_RenderCopy(renderer, animations->wizardTexture, NULL, &(animations->wizardRect));
}

void draw_floor(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height) {
    animations->floorRect = (SDL_Rect){rect.x, rect.y, window_width/41, window_height/26};
	SDL_RenderCopy(renderer, animations->floorTexture, NULL, &(animations->floorRect));
}

void draw_player_movement_animation(SDL_Rect rect, SDL_Renderer *renderer,
                                    t_animation_manager *animations, t_topiman *topiman, int window_width, int window_height) {
	animations->topiRect = (SDL_Rect){rect.x, rect.y, window_width/40, window_height/25};
    
	if (topiman->topiMove.x == 0 && topiman->topiMove.y == 1) {
        t_animation_node *current_frame_node = animations->playerDownAnimation;
        animations->playerDownAnimation = current_frame_node->next_frame_node;
		
		SDL_RenderCopy(renderer, current_frame_node->texture, NULL, &(animations->topiRect));
	}
	else if (topiman->topiMove.x == 0 && topiman->topiMove.y == -1) {
		t_animation_node *current_frame_node = animations->playerUpAnimation;
        animations->playerUpAnimation = current_frame_node->next_frame_node;
		
		SDL_RenderCopy(renderer, current_frame_node->texture, NULL, &(animations->topiRect));
	}
	else if (topiman->topiMove.x == 1 && topiman->topiMove.y == 0) {
		t_animation_node *current_frame_node = animations->playerRightAnimation;
        animations->playerRightAnimation = current_frame_node->next_frame_node;
		
		SDL_RenderCopy(renderer, current_frame_node->texture, NULL, &(animations->topiRect));
	}
	else if (topiman->topiMove.x == -1 && topiman->topiMove.y == 0) {
		t_animation_node *current_frame_node = animations->playerLeftAnimation;
        animations->playerLeftAnimation = current_frame_node->next_frame_node;;
		
		SDL_RenderCopy(renderer, current_frame_node->texture, NULL, &(animations->topiRect));
	}
}

