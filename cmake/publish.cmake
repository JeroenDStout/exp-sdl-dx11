message(STATUS "Config publication")

set_property(GLOBAL PROPERTY publish_exec)

function(configure_exec_publish name)
  message(STATUS "Publication for ${name}")
  
  get_property(_publish_exec GLOBAL PROPERTY publish_exec)
  list(APPEND _publish_exec "${name}" )
  set_property(GLOBAL PROPERTY publish_exec "${_publish_exec}")
endfunction()

function(finalise_publish)
  message(STATUS "")
  message(STATUS "-- Finalising publication")
  
  set(file_out "${CMAKE_BINARY_DIR}/publish_info.txt")
  file(WRITE ${file_out} "")
  
  get_property(_publish_exec GLOBAL PROPERTY publish_exec)
  
  message(STATUS "Executables:")
  foreach (var IN ITEMS ${_publish_exec})
    message(STATUS "* " ${var})
    file(APPEND ${file_out} "executable: ${var}\n")
  endforeach()
  
  
endfunction()