#####################
### tests/sorting ###
#####################

# set the name of the tested module here
set(tested_module_name Sorting)

# add test sourc files here
set(test_source_files
# each time you add a new test file you must add it to this list for cmake to process it.
    quicksort.c
    test_2.c
)

# go through test_source_files one by one and process each file:
foreach(file ${test_source_files})
    # remmove extension from filename
    get_filename_component(file_name ${file} NAME_WLE)
    
    # build the test name based on the tested module and test filename
    set(test_name "${tested_module_name}_${file_name}")

    # add current test file as an executable
    add_executable(${test_name}
        ${file}
    )

    # link the unity framework and the tested module as a library
    target_link_libraries(${test_name}  
        Unity
        ${tested_module_name}
    ) 

    # the indlude directory of the Unity framework
    target_include_directories(${test_name} 
        PUBLIC
        ${PROJECT_SOURCE_DIR}/tests/_unity
    )

    # set the binaries directory
    set_target_properties(${test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_TESTS_OUTPUT_DIRECTORY}"
    )

    # add the current test 
    add_test(${test_name} "${CMAKE_TESTS_OUTPUT_DIRECTORY}/${test_name}")

endforeach(file ${test_source_files})
