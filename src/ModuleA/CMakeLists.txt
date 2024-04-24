######################
#### /src/ModuleA ####
######################

# set variables
set(MODULE_NAME ModuleA)
set(MODULE_SOURCE ModuleA.c)

# add module as a static library
add_library(${MODULE_NAME} STATIC ${MODULE_SOURCE})

# module's include directory (current dir of this file)
target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
