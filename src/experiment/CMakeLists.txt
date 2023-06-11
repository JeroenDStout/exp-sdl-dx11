init_directory(experiment)

# Define the Experiment project
init_project(experiment "Experiment")

# Sources
setup_project_source(experiment "core"
  main.cpp
  experiment.cpp
  experiment.h
  assets.cpp
  assets.h
)
setup_project_source(experiment "include"
  include_sdl.h
)

# Target
configure_project_executable(experiment)
configure_project_console(experiment)
configure_sdl_target(experiment)
configure_exec_publish(experiment)
	
add_dependencies(experiment version)
