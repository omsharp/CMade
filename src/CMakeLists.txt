# #############
# ### /src ####
# #############

# contains important functions and properties for managing modules.
# will set property modules_list that holds all the added modules.
include(_cmake/ModulesUtils.cmake)

add_subdirectory(modules)
add_subdirectory(utils)

# add main executable
add_executable(${PROJECT_NAME} main.c)

# get the list of all modules in the project and
# link them to the main executable
get_property(modules GLOBAL PROPERTY modules_list)
target_link_libraries(${PROJECT_NAME} ${modules})
