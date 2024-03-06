#include "virus.h"

t_animation_node *create_animation_start_frame(SDL_Texture *texture) {
    t_animation_node *new_node = (t_animation_node*)malloc(sizeof(t_animation_node));
    new_node->start = true;
    new_node->texture = texture;
    new_node->next_frame_node = NULL;

    return new_node;
}

void push_back_animation_node(t_animation_node *head, SDL_Texture *texture) {
    t_animation_node *new_node = (t_animation_node*)malloc(sizeof(t_animation_node));
    new_node->start = false;
    new_node->texture = texture;
    new_node->next_frame_node = NULL;

    while (head->next_frame_node != NULL) {
        head = head->next_frame_node;
    }

    head->next_frame_node = new_node;
}

void link_last_and_first_node(t_animation_node *head) {
    t_animation_node *first_node = head;

    while (head->next_frame_node != NULL) {
        head = head->next_frame_node;
    }

    head->next_frame_node = first_node;
}

t_animation_node *get_first_element_of_list(t_animation_node *head) {
    while (head->start != true) {
        head = head->next_frame_node;
    }

    return head;
}

void clean_animation_list(t_animation_node **head) {
    t_animation_node *current_node = get_first_element_of_list(*head);

    current_node = current_node->next_frame_node;

    while (current_node->start != true) {
        SDL_DestroyTexture(current_node->texture);
        t_animation_node *temp = current_node;
        current_node = current_node->next_frame_node;
        free(temp);
    }

    SDL_DestroyTexture(current_node->texture);
    free(current_node);

    *head = NULL;
}

