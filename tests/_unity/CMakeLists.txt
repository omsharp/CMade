###################
### test/_unity ###
###################

add_library(Unity STATIC unity.c)
target_include_directories(Unity PUBLIC CMAKE_CURRENT_LIST_DIR)