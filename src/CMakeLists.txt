# #############
# ### /src ####
# #############

# a golbal property that holds a list of all modules in project
set_property(GLOBAL PROPERTY modules_list)

# add a module to the module_list property
# this function is called by the module's cmake file
function(add_module module)
    get_property(temp GLOBAL PROPERTY modules_list)
    list(APPEND temp ${module})
    set_property(GLOBAL PROPERTY modules_list "${temp}")
endfunction(add_module)

# extracts the current directory name, and sets in out variable
function(get_current_directory_name out)
    cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME temp)
    string(REPLACE " " "_" temp ${temp})
    set(${out} ${temp} PARENT_SCOPE)
endfunction(get_current_directory_name)

# add the main subdirectories
add_subdirectory(modules)
add_subdirectory(utils)

# add main executable
add_executable(${PROJECT_NAME} main.c)

# get the list of all modules in the project
get_property(mods_list GLOBAL PROPERTY modules_list)

# link modules as static libraries to the main executable
target_link_libraries(${PROJECT_NAME} ${mods_list})