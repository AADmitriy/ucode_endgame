#include "sound_manager.h"
#include "output_functions.h"

void init_sound_manager(t_sound_manager *sound_manager) {
    const char *path_to_collect_coin_sound = "resources/sounds_and_music/collect_coin1.mp3";
    const char *path_to_victory_sound = "resources/sounds_and_music/victory.wav";
    const char *path_to_defeat_sound = "resources/sounds_and_music/defeat1.mp3";
    const char *path_to_game_background_music = "resources/sounds_and_music/game_background_music1.mp3";
    const char *path_to_menu_background_music = "resources/sounds_and_music/menu_background_music1.mp3";
    const char *path_to_victory_background_music = "resources/sounds_and_music/victory_background_music1.mp3";
    const char *path_to_defeat_background_music = "resources/sounds_and_music/defeat_background_music1.mp3";
    const char *path_to_freeze_sound = "resources/sounds_and_music/freeze.mp3";

    sound_manager->collect_coin_sound = Mix_LoadWAV(path_to_collect_coin_sound);
    sound_manager->victory_sound = Mix_LoadWAV(path_to_victory_sound);
    sound_manager->defeat_sound = Mix_LoadWAV(path_to_defeat_sound);
    sound_manager->game_background_music = Mix_LoadMUS(path_to_game_background_music);
    sound_manager->menu_background_music = Mix_LoadMUS(path_to_menu_background_music);
    sound_manager->victory_background_music = Mix_LoadMUS(path_to_victory_background_music);
    sound_manager->defeat_background_music = Mix_LoadMUS(path_to_defeat_background_music);
    sound_manager->freeze_sound = Mix_LoadWAV(path_to_freeze_sound);
}

void play_collect_coin_sound(t_sound_manager *sound_manager) {
    Mix_PlayChannel(-1, sound_manager->collect_coin_sound, 0);
}

void play_victory_sound(t_sound_manager *sound_manager) {
    Mix_PlayChannel(-1, sound_manager->victory_sound, 0);
}

void play_defeat_sound(t_sound_manager *sound_manager) {
    Mix_PlayChannel(-1, sound_manager->defeat_sound, 0);
}

void play_game_background_music(t_sound_manager *sound_manager) {
    Mix_PlayMusic(sound_manager->game_background_music, 2147483647);
}

void play_menu_background_music(t_sound_manager *sound_manager) {
    Mix_PlayMusic(sound_manager->menu_background_music, 2147483647);
}

void play_victory_background_music(t_sound_manager *sound_manager) {
    Mix_PlayMusic(sound_manager->victory_background_music, 2147483647);
}

void play_defeat_background_music(t_sound_manager *sound_manager) {
    Mix_PlayMusic(sound_manager->defeat_background_music, 2147483647);
}

void stop_background_music(void) {
    Mix_HaltMusic();
}

void play_freeze_sound(t_sound_manager *sound_manager) {
    Mix_PlayChannel(-1, sound_manager->freeze_sound, 0);
}

void free_sound_and_music(t_sound_manager *sound_manager) {
    Mix_FreeChunk(sound_manager->collect_coin_sound);
    Mix_FreeChunk(sound_manager->victory_sound);
    Mix_FreeChunk(sound_manager->defeat_sound);
    Mix_FreeMusic(sound_manager->game_background_music);
    Mix_FreeMusic(sound_manager->menu_background_music);
    Mix_FreeMusic(sound_manager->victory_background_music);
    Mix_FreeMusic(sound_manager->defeat_background_music);
}

