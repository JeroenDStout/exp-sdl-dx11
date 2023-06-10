#include "experiment/experiment.h"

#include "SDL.h"

#include <iostream>


namespace experiment {

void run_experiment() {
    //
    // --- Init
    //

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

    //
    // --- Main loop
    //

	std::cout << "Main loop" << std::endl;

    bool      running = true;
    SDL_Event sdl_event;

    while (running && SDL_WaitEvent(&sdl_event)) {
        switch (sdl_event.type) {
          default: break;
          case SDL_EventType::SDL_QUIT:
	        std::cout << "Quit" << std::endl;
            running = false;
			break;
        }
    }

    //
    // --- Cleanup
    //

	std::cout << "Destroying window" << std::endl;
    
    SDL_DestroyWindow(window);
    SDL_Quit();

	std::cout << "Experiment ended" << std::endl;
}

}