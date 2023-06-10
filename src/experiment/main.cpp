#include "experiment/experiment.h"

#include "experiment/include_sdl.h"
#include "version/git_version.h"

#include <iostream>


int SDL_main(int, char *[])
{
    std::cout
      << std::endl
      << "          * * * * * * * * * * * * *  " << std::endl
      << "         * * * SDL + DX11 test * * * " << std::endl
      << "          * * * * * * * * * * * * *  " << std::endl
      << std::endl
      << gaos::version::get_git_essential_version() << std::endl
      << gaos::version::get_compile_stamp() << std::endl
      << std::endl
      << gaos::version::get_git_history() << std::endl
      << std::endl;

    // ---- sdl

    experiment::run_experiment();
    
    return 0;
}