#include "virus.h"
#include "output_functions.h"
#include "sound_manager.h"
#include "animation_nodes.h"

void default_position_topi(t_topiman *topiman) {
	topiman->topi = (t_pos){1, 2};
	topiman->topiMove = (t_pos){1, 0};
	topiman->virus = (t_pos){21, 21};
}

static void initDefault(t_topiman *topiman) {	
	topiman->score = 0;
	topiman->is_winner = false;
	topiman->anticeptic_apeared = false;
	topiman->spawn_freeze = false;

	default_position_topi(topiman);
}

t_animation_node *create_three_frame_animation(SDL_Texture *frame1, SDL_Texture *frame2, SDL_Texture *frame3) {
	t_animation_node *animation_list = create_animation_start_frame(frame1);
    push_back_animation_node(animation_list, frame2);
	push_back_animation_node(animation_list, frame3);
	link_last_and_first_node(animation_list);

	return animation_list;
}

void initPlayerAnimation(t_animation_manager *animation_manager, SDL_Renderer *renderer) {
	animation_manager->antiTexture = IMG_LoadTexture(renderer, "resources/weapon_lavish_sword.png");
	animation_manager->coinTexture = IMG_LoadTexture(renderer, "resources/money.png");
	animation_manager->freezeTexture = IMG_LoadTexture(renderer, "resources/freeze.png");
	animation_manager->wallTexture = IMG_LoadTexture(renderer, "resources/wall_left.png");
	animation_manager->floorTexture = IMG_LoadTexture(renderer, "resources/floor_1.png");
	animation_manager->grassTexture = IMG_LoadTexture(renderer, "resources/grass_image.png");
	animation_manager->doors_openTexture = IMG_LoadTexture(renderer, "resources/doors_leaf_open.png");
	animation_manager->doors_closedTexture = IMG_LoadTexture(renderer, "resources/doors_leaf_closed.png");
	animation_manager->wizardTexture = IMG_LoadTexture(renderer, "resources/wizzard_m_hit_anim_f0.png");

	SDL_Texture *topiImage = IMG_LoadTexture(renderer,"resources/Topi1.png");
	SDL_Texture *topiImageDown1 = IMG_LoadTexture(renderer,"resources/Topi2.png");
	SDL_Texture *topiImageDown2 = IMG_LoadTexture(renderer,"resources/Topi3.png");

	animation_manager->playerDownAnimation = create_three_frame_animation(topiImage, topiImageDown1, topiImageDown2);
	
	SDL_Texture *topiImageUp1 = IMG_LoadTexture(renderer,"resources/Topi_S1.png");
	SDL_Texture *topiImageUp2 = IMG_LoadTexture(renderer,"resources/Topi_S2.png");
	SDL_Texture *topiImageUp3 = IMG_LoadTexture(renderer,"resources/Topi_S3.png");

    animation_manager->playerUpAnimation = create_three_frame_animation(topiImageUp1, topiImageUp2, topiImageUp3);

    SDL_Texture *topiImageLeft1 = IMG_LoadTexture(renderer,"resources/Topi_L1.png");
	SDL_Texture *topiImageLeft2 = IMG_LoadTexture(renderer,"resources/Topi_L2.png");
	SDL_Texture *topiImageLeft3 = IMG_LoadTexture(renderer,"resources/Topi_L3.png");

    animation_manager->topiTexture = topiImageLeft1;
    animation_manager->playerLeftAnimation = create_three_frame_animation(topiImageLeft1, topiImageLeft2, topiImageLeft3);

	SDL_Texture *topiImageRight1 = IMG_LoadTexture(renderer,"resources/Topi_P1.png");
	SDL_Texture *topiImageRight2 = IMG_LoadTexture(renderer,"resources/Topi_P2.png");
	SDL_Texture *topiImageRight3 = IMG_LoadTexture(renderer,"resources/Topi_P3.png");

	animation_manager->playerRightAnimation = create_three_frame_animation(topiImageRight1, topiImageRight2, topiImageRight3);

	SDL_Texture *enemyImage1 = IMG_LoadTexture(renderer,"resources/big_demon_idle_anim_f01.png");
	SDL_Texture *enemyImage2 = IMG_LoadTexture(renderer,"resources/big_demon_idle_anim_f02.png");
	SDL_Texture *enemyImage3 = IMG_LoadTexture(renderer,"resources/big_demon_idle_anim_f03.png");
	
	animation_manager->enemyAnimation = create_three_frame_animation(enemyImage1, enemyImage2, enemyImage3);
	animation_manager->frozen_enemy_texture = IMG_LoadTexture(renderer,"resources/big_demon_frozen.png");
}

int main(void) {
    bool play_game = true;

	int map_height;
	int map_width;

	int **map = mx_get_map("resources/map", &map_height, &map_width);

	t_topiman *topiman = (t_topiman*)malloc(sizeof(t_topiman));
	topiman->animation_manager = (t_animation_manager*)malloc(sizeof(t_animation_manager));
    topiman->sound_manager = (t_sound_manager*)malloc(sizeof(t_sound_manager));
	topiman->virus_frozen = 0;

	initSDL(&topiman->sdl);
	initDefault(topiman);
	initPlayerAnimation(topiman->animation_manager, topiman->sdl.renderer);

	init_sound_manager(topiman->sound_manager);
    
    play_menu_background_music(topiman->sound_manager);
	
	if (!mx_menu(topiman->sdl.renderer, &topiman->sdl)) {
		stop_background_music();
		free_sound_and_music(topiman->sound_manager);
		free_animations(topiman->animation_manager);
		destroySDL(topiman);
		free(topiman->animation_manager);
		free(topiman->sound_manager);
		free(topiman);
	    exit(EXIT_SUCCESS);
	}
	
    if (!show_story(topiman->sdl.renderer, &topiman->sdl)) {
		stop_background_music();
		free_sound_and_music(topiman->sound_manager);
		free_animations(topiman->animation_manager);
		destroySDL(topiman);
		free(topiman->animation_manager);
		free(topiman->sound_manager);
		free(topiman);
	    exit(EXIT_SUCCESS);
	}

	stop_background_music();
    
    while (play_game) {
		play_game_background_music(topiman->sound_manager);
	    mx_process_game(topiman, map_height, map_width, map);
		stop_background_music();
        
	    play_game = mx_finish_game(topiman);

		if (play_game) {
			initDefault(topiman);

			for (int i = 0; i < map_height; i++) {
                free(map[i]);
            }
            free(map);
			
			map = mx_get_map("resources/map", &map_height, &map_width);
			SDL_GetWindowSize(topiman->sdl.window, &topiman->sdl.window_width, &topiman->sdl.window_height);
        }
	}

	for (int i = 0; i < map_height; i++) {
        free(map[i]);
    }
    free(map);

	destroySDL(topiman);

	free_animations(topiman->animation_manager);

    free_sound_and_music(topiman->sound_manager);

    free(topiman->animation_manager);
	free(topiman->sound_manager);
    free(topiman);

	exit(EXIT_SUCCESS);
}
