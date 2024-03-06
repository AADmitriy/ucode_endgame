#pragma once

#include <SDL2/SDL_mixer.h>

typedef struct s_sound_manager {
    Mix_Chunk *collect_coin_sound;
    Mix_Chunk *collect_anticeptic_sound;
    Mix_Chunk *victory_sound;
    Mix_Chunk *defeat_sound;
    Mix_Chunk *freeze_sound;
    Mix_Music *game_background_music;
    Mix_Music *menu_background_music;
    Mix_Music *victory_background_music;
    Mix_Music *defeat_background_music;
}              t_sound_manager;

void init_sound_manager(t_sound_manager *sound_manager);
void play_collect_coin_sound(t_sound_manager *sound_manager);
void play_collect_anticeptic_sound(t_sound_manager *sound_manager);
void play_victory_sound(t_sound_manager *sound_manager);
void play_defeat_sound(t_sound_manager *sound_manager);
void play_death_sound(t_sound_manager *sound_manager);
void play_game_background_music(t_sound_manager *sound_manager);
void play_menu_background_music(t_sound_manager *sound_manager);
void play_victory_background_music(t_sound_manager *sound_manager);
void play_defeat_background_music(t_sound_manager *sound_manager);
void stop_background_music(void);
void play_freeze_sound(t_sound_manager *sound_manager);
void free_sound_and_music(t_sound_manager *sound_manager);

