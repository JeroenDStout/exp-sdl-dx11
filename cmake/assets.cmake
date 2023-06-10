message(STATUS "Setup Assets")

function(configure_asset_folder project_ref asset_group_name folder_in folder_out)
  message(STATUS "Configure asset folder ${project_ref} ${asset_group_name}")
  
  file(GLOB asset_files ${folder_in}/*)
  
  set(added_assets "")
  
  file(MAKE_DIRECTORY ${project_bin_dir}/${folder_out})
  
  foreach(asset_file ${asset_files})
    file(RELATIVE_PATH rel_file ${project_root_dir} ${asset_file})
    message(STATUS " - ${rel_file}")
    file(RELATIVE_PATH rel_file ${folder_in} ${asset_file})
	
	add_custom_command(
      COMMENT 			"\nCopying to /${project_bin_dir}/${folder_out}/${rel_file}"
	  OUTPUT    		${project_bin_dir}/${folder_out}/${rel_file}
	  DEPENDS			${asset_file}
      COMMAND   		${CMAKE_COMMAND} -E copy
						${asset_file}
						${project_bin_dir}/${folder_out}/${rel_file}
	  VERBATIM
	)
	
    list(APPEND added_assets ${project_bin_dir}/${folder_out}/${rel_file})
  endforeach()
  
  add_custom_target(${asset_group_name} ALL
     DEPENDS ${added_assets}
  )
  set_target_properties(${asset_group_name} PROPERTIES FOLDER "assets")
  
endfunction()