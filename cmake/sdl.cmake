message(STATUS "Setup SDL2")

include(FetchContent)
cmake_policy(SET CMP0135 NEW)

# Obtain SDL2
FetchContent_Declare(
  SDL2
  URL     https://github.com/libsdl-org/SDL/releases/download/release-2.26.5/SDL2-devel-2.26.5-VC.zip
)
FetchContent_MakeAvailable(SDL2)
set(ENV{SDL2_DIR} ${sdl2_SOURCE_DIR})

find_package(SDL2 REQUIRED)

# For all configurations, create a custom command to copy the SDL2 dynamic libraries
set(_added_copy_files "")
if (WIN32)
  foreach(config ${CMAKE_CONFIGURATION_TYPES})
    add_custom_command(
      COMMENT 			"Copying SDL2.dll to /${project_bin_dir}/${config}/SDL2.dll"
      OUTPUT    		${project_bin_dir}/${config}/SDL2.dll
      DEPENDS			${SDL2_BINDIR}/SDL2.dll
      COMMAND   		${CMAKE_COMMAND} -E copy
                        ${SDL2_BINDIR}/SDL2.dll
                        ${project_bin_dir}/${config}/SDL2.dll
      VERBATIM
    )
    
    list(APPEND _added_copy_files ${project_bin_dir}/${config}/SDL2.dll)
  endforeach()
else()
  message(ERROR "Missing platform specific copy for SDL2")
endif()

# Create a target to make the SDL2 files relevant
add_custom_target(sdl_copy ALL
  DEPENDS ${_added_copy_files}
)
set_target_properties(sdl_copy PROPERTIES FOLDER "meta")

# Helper function for setting up project
function(configure_sdl_target project_ref)
  message(STATUS "Configure SDL Target ${project_ref}")
  
  target_link_libraries(${project_ref} ${SDL2_LIBRARIES})
endfunction()