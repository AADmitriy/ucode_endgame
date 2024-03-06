#include "virus.h"

t_animation_node *create_animation_start_frame(SDL_Texture *texture);
void push_back_animation_node(t_animation_node *head, SDL_Texture *texture);
void link_last_and_first_node(t_animation_node *head);
t_animation_node *get_first_element_of_list(t_animation_node *head);
void clean_animation_list(t_animation_node **head);

