#
#       * * * * * * * * * * * * *
#      * * * SDL + DX11 test * * *
#       * * * * * * * * * * * * *
#

cmake_minimum_required(VERSION 3.15) 

project(SDL_DX11)
include(cmake/project.cmake)
include(cmake/publish.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Languages
include(cmake/cxx.cmake)
include(cmake/python.cmake)

# Support
include(cmake/artefacts.cmake)
include(cmake/sources.cmake)
include(cmake/sdl.cmake)

# Assets
include(cmake/assets.cmake)

# Subprojects
add_subdirectory(src/experiment)
add_subdirectory(src/version)

# Publication
finalise_publish()