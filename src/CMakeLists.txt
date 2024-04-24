##############
#### /src ####
##############

# set global (project wide) include (headers) directory
# include_directories(./include)

# add subdirectories of modules.
# each subdirectory has its own CMakeLists.txt that will be processed immediatly.
add_subdirectory(ModuleA) # add and process ModuleA's CMakeLists.txt
add_subdirectory(ModuleB) # add and process ModuleB's CMakeLists.txt

# add main executable
add_executable(${PROJECT_NAME} main.c)

# link mudules as static libraries to the main executable
target_link_libraries(${PROJECT_NAME} ModuleA ModuleB)