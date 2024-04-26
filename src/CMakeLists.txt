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

# link all modules in the system
link_project_modules()
