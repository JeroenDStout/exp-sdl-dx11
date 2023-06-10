#include "experiment/experiment.h"
#include "experiment/include_sdl.h"

#include <random>
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

    std::random_device random_dev;
    std::mt19937       random_gen(random_dev());
    std::uniform_int_distribution<std::mt19937::result_type> random_byte(0x00, 0xFF);

    bool      running = true;
    SDL_Event sdl_event;

    while (running && SDL_WaitEvent(&sdl_event)) {
        switch (sdl_event.type) {
          default:
            break;

          case SDL_EventType::SDL_QUIT:
	        std::cout << "Quit" << std::endl;
            running = false;
			break;

          case SDL_EventType::SDL_MOUSEBUTTONDOWN:
	        std::cout << "Button press" << std::endl;

            // Set a random background colour
            SDL_SetRenderDrawColor(
              renderer,
              (std::uint8_t)random_byte(random_gen),
              (std::uint8_t)random_byte(random_gen),
              (std::uint8_t)random_byte(random_gen),
              SDL_ALPHA_OPAQUE
            );
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);

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