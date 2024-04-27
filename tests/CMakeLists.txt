# ##############
# ## /tests ####
# ##############

include(_cmake/TestsUtils.cmake) # macros and functions

# add test suites
add_subdirectory(sorting)
add_subdirectory(stats)
add_subdirectory(some_tests)
