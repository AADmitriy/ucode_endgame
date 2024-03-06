#pragma once

#include "virus.h"

void draw_wall(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_coin(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_freeze(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_freedom(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_anticeptic(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_enemy(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_frozen_enemy(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_doors_closed(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_doors_open(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_floor(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);
void draw_player_movement_animation(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, t_topiman *topiman, int window_width, int window_height);
void draw_wizard(SDL_Rect rect, SDL_Renderer *renderer, t_animation_manager *animations, int window_width, int window_height);


