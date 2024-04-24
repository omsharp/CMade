######################
#### /src/utils ####
######################

# sets module name based on directory
set_module_name(MODULE_NAME)

# add utils source files to meke utils module library
add_library(${MODULE_NAME} STATIC
    NullPointerGuard.c
    CopyArray_Double.c
)

# include directory (current dir of this file)
target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# add to the modules list
add_module(${MODULE_NAME})
