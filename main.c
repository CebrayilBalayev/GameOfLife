#include "actions.h"
#include "interface.h"

int main(int argc, char** argv){
    int size = 64;//best options => 2^n : 32,64,128...
    int type = CIRCULAR;//CLIPPED or CIRCULAR
    int delay = 80;//time in ms

	srand(time(NULL)); 
	int **matrix = allocatedMatrix(size);
	matrix = randomMatrix(matrix,size);

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr,"Problem can not init SDL2 \n");
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("Game of Life",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SIZE , SIZE , SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	assert(renderer != NULL);

	drawmatrix(renderer,matrix,size);
	SDL_RenderPresent(renderer);

	bool quit = false;
	bool play = true;
	while (!quit){
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){quit = true;break;}
			if(event.type == SDL_KEYDOWN)
				if(event.key.keysym.sym == SDLK_SPACE)
					play = !play;
				if(event.key.keysym.sym == SDLK_r && !play){
					matrix = randomMatrix(matrix,size);
					drawmatrix(renderer,matrix,size);
					SDL_RenderPresent(renderer);
				}
		}
		
		if(play){
			drawmatrix(renderer,matrix,size);
			matrix = dostep(matrix,size,type);
			SDL_RenderPresent(renderer);
			SDL_Delay(delay);	
		}
	}
	SDL_Quit();
	return 0;
}
