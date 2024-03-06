#include "virus.h"
#include "storypage_visual.h"

bool show_story(SDL_Renderer *render, t_sdl *sdl) {
	bool quit = false;
	SDL_Event event;
	int x, y;
	int windowWidth, windowHeight;
	
    t_storypage *storypage = (t_storypage*)malloc(sizeof(t_storypage));

	mx_init_storypage(storypage, render, sdl->window_width, sdl->window_height);

	SDL_RenderClear(render);

    mx_upload_storypage_to_memory(storypage, render);

	while(!quit) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:  
                    return false;
				case SDL_MOUSEMOTION:
					x = event.motion.x;
					y = event.motion.y;

					if (is_coordinates_in_rectangle(x, y, storypage->go_rect)) {
                       	SDL_RenderCopy(render, storypage->btn_go_active_tex, NULL, &storypage->go_rect);   
                    }
                    else {
                        SDL_RenderCopy(render, storypage->btn_go_tex, NULL, &storypage->go_rect);
                   	}
                    break;
				case SDL_MOUSEBUTTONDOWN: /*YOU CLICKED 1 time*/
                    x = event.button.x;
                   	y = event.button.y;

                    if (is_coordinates_in_rectangle(x, y, storypage->go_rect)) {  			
                        quit = true;
                    }
                    break;
				case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        windowWidth = event.window.data1;
                        windowHeight = event.window.data2;
                        mx_init_storypage(storypage, render, windowWidth, windowHeight);
						sdl->window_width = windowWidth;
						sdl->window_height = windowHeight;
                        SDL_RenderClear(render);
                        mx_upload_storypage_to_memory(storypage, render);
                    }
			}
		}
		SDL_RenderPresent(render);
	}

	mx_destroy_storypage_textures(storypage);

	free(storypage);

	return true;
}

