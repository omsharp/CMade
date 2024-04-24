######################
#### /src/ModuleB ####
######################

# set variables
set(MODULE_NAME ModuleB)
set(MODULE_SOURCE ModuleB.c)

# add module as a static library
add_library(${MODULE_NAME} STATIC ${MODULE_SOURCE})

# module's include directory (current dir of this file)
target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
