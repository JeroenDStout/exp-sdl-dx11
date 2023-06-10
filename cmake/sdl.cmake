message(STATUS "Setup SDL2")

find_package(SDL2 REQUIRED)

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

add_custom_target(sdl_copy ALL
  DEPENDS ${_added_copy_files}
)
set_target_properties(sdl_copy PROPERTIES FOLDER "meta")

function(configure_sdl_target project_ref)
  message(STATUS "Configure SDL Target ${project_ref}")
  
  target_link_libraries(${project_ref} ${SDL2_LIBRARIES})
endfunction()