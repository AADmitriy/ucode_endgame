#include "virus.h"
#include "storypage_visual.h"

void mx_init_storypage(t_storypage *storypage, SDL_Renderer *render, int window_width, int window_height) {
    int WI = window_width / 3.36;
	int HE = window_height / 13.6;
	int size_font = HE / 2;

	SDL_Color color_green = {0, 0, 0, 0};
    SDL_Color color_yellow = {255, 255, 0, 0};
	const char *font_file = "resources/font.ttf";

	CreateRectangle(&storypage->go_rect, window_width * 0.42, window_height * 0.85, 0.4 * WI, HE * 1.2);	

	TTF_Font* font = TTF_OpenFont(font_file, size_font);

	storypage->btn_go_active_tex = loadTextTexture(render, font, "GO", color_yellow);
	storypage->btn_go_tex = loadTextTexture(render, font, "GO", color_green);
    storypage->bg_tex = IMG_LoadTexture(render, "resources/UI/story.bmp");

	TTF_CloseFont(font);
}

void mx_upload_storypage_to_memory(t_storypage *storypage, SDL_Renderer *render) {
    SDL_RenderCopy(render, storypage->bg_tex, NULL, NULL);
    SDL_RenderCopy(render, storypage->btn_go_tex, NULL, &storypage->go_rect);
}

void mx_destroy_storypage_textures(t_storypage *storypage) {
    SDL_DestroyTexture(storypage->bg_tex);
    SDL_DestroyTexture(storypage->btn_go_tex);
    SDL_DestroyTexture(storypage->btn_go_active_tex);
}

