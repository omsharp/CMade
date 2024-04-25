# ##############
# ## /tests ####
# ##############

# will process a test file and add test to the system
# this function must be called every time a new file is added to the test suite.
function(add_test_suite tested_module_name test_source_list)
    # go through test_source_files one by one and process each file:
    foreach(file ${${test_source_list}})
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

        # the include directory of the Unity framework
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
endfunction(add_test_suite tested_module_name test_source_list)

# add Unity subdirectory
add_subdirectory(_unity)

# add suites subdirectory
add_subdirectory(sorting)
