#include "virus.h"


void CreateRectangle(SDL_Rect* object, int x, int y, int w, int h){
    object->x = x;
    object->y = y;
    object->w = w;
    object->h = h;
}

void CreateTextureImage_from_bmp(const char *file, SDL_Surface **surface, SDL_Renderer *render, SDL_Texture **texture){
    *surface = SDL_LoadBMP(file);
    if (!*surface)
        printf("error creating surface\n%s\n", file);
    *texture = SDL_CreateTextureFromSurface(render, *surface);
    if (!*texture)
        printf("error creating texture: %s\n", SDL_GetError());
    SDL_FreeSurface(*surface);
}

SDL_Texture* loadTextTexture(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color color) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
    if (!textSurface) {
        printf("Error rendering text: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        printf("Error creating texture from surface: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return NULL;
    }

    SDL_FreeSurface(textSurface);

    return textTexture;
}


