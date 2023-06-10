#include "experiment/experiment.h"

#include "SDL.h"

#include <iostream>


namespace experiment {

void run_experiment() {
	std::cout << "Starting experiment" << std::endl;

    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow(
      "SDL + DX11 test",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      640, 480, 0
    );

	std::cout << "Creating renderer" << std::endl;
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    
    SDL_Delay(3000);

	std::cout << "Destroying window" << std::endl;
    
    SDL_DestroyWindow(window);
    SDL_Quit();

	std::cout << "Experiment ended" << std::endl;
}

}