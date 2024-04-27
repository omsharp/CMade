# #############
# ### /src ####
# #############

# contains important utilities for managing modules.
include(_cmake/ModulesUtils.cmake)

# must add main executable before adding modules subdirectories
add_executable(${PROJECT_NAME} main.c)

add_subdirectory(modules)
add_subdirectory(utils)
