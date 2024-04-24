#####################
### tests/suite_1 ###
#####################

add_executable(suite_1
    test_1.c
    # test_2.c
)

# link the unity as a library
target_link_libraries(suite_1  
    Unity
    _m_Sorting
) 

target_include_directories(
    suite_1 
    PUBLIC
    ${PROJECT_SOURCE_DIR}/tests/_unity
)

set_target_properties(suite_1
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_TESTS_OUTPUT_DIRECTORY}"
)

add_test(suite_test_1 "${CMAKE_TESTS_OUTPUT_DIRECTORY}/suite_1")