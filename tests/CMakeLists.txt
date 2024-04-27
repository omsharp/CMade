# ##############
# ## /tests ####
# ##############

# utilities
include(_cmake/TestsUtils.cmake)

# add Unity subdirectory
add_subdirectory(_unity)

# add suites subdirectory
add_subdirectory(sorting)
add_subdirectory(some_tests)
