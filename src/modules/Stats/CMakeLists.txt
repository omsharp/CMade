###########################
#### /src/Module_Stats ####
###########################

# sets module name based on directory
set_module_name(MODULE_NAME)

# add module as a static library
add_library(${MODULE_NAME} STATIC 
    Median.c
)

# module's include directory (current dir of this file)
target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# add to the modules list
add_module(${MODULE_NAME})
