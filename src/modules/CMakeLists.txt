######################
#### /src/modules ####
######################


# [info] still not sure whether to use globing or not.
# [info] for now i'm satteling with manually adding subdirectories.

# add all subdirectories in src/modules.
# each subdirectory has its own CMakeLists.txt that will be processed immediatly.
# file(GLOB V_GLOB LIST_DIRECTORIES true "*")
# foreach(item ${V_GLOB})
# 	if(IS_DIRECTORY ${item})
# 		add_subdirectory(${item})
# 	endif()
# endforeach()

# add each module subdirectory
add_subdirectory(Sorting)
add_subdirectory(Stats)
