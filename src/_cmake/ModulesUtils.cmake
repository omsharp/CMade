# -------------------------------------------------#
# --------- utilites for managing modules ---------#
# -------------------------------------------------#

# a property that holds a list of all modules in project
set_property(GLOBAL PROPERTY modules_list)

# adds the source files as a static library.
# using the caller's directory as a module name.
function(add_module_static)
    # extract the current directory name into module_name to be used as module's name
    cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME module_name)
    string(REPLACE " " "_" module_name ${module_name})

    # add module as a static library using its source files
    add_library(${module_name} STATIC
        ${ARGV}
    )

    # include directory (current dir of this file)
    target_include_directories(${module_name} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

    # add module to the modules list property
    get_property(temp GLOBAL PROPERTY modules_list)
    list(APPEND temp ${module_name})
    set_property(GLOBAL PROPERTY modules_list ${temp})
endfunction(add_module_static)

# links all the added modules to the project executable
function(link_project_modules)
    # get the list of all modules in the project and
    get_property(modules GLOBAL PROPERTY modules_list)

    # link modules to the project executable
    target_link_libraries(${PROJECT_NAME} ${modules})
endfunction(link_project_modules)
