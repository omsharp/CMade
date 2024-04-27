# holds a list of all tests in a suite (directory)
set_property(DIRECTORY PROPERTY tests_list)

set_property(DIRECTORY PROPERTY group_name)

# sets the group name of this suit
function(tests_set_group_name suite_name)
  # todo)) finish this idea...
  set_property(DIRECTORY PROPERTY group_name ${suite_name})
endfunction()

# source files of tests in this suite.
# test_sources([<source>...])
function(tests_sources sources_list)
  # get the current list of tests
  get_property(current_tests_list DIRECTORY PROPERTY tests_list)

  # Extracts the directory name of the current list
  # into variable directory_name
  cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME directory_name)
  string(REPLACE " " "_" directory_name ${directory_name})

  # go through test source files,
  # process and build a test for each source file
  foreach(file ${ARGV})
    # remove extension
    get_filename_component(file_name ${file} NAME_WLE)

    set(test_name "${directory_name}_${file_name}")

    add_executable(${test_name} ${file} "../_unity/unity.c")

    # the include directory of the Unity framework
    target_include_directories(${test_name}
      PUBLIC
      ${PROJECT_SOURCE_DIR}/tests/_unity
    )

    # set the binary directory for the test
    set_target_properties(${test_name}
      PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY
      "${CMAKE_TESTS_OUTPUT_DIRECTORY}/${directory_name}"
    )

    add_test(${test_name}
      "${CMAKE_TESTS_OUTPUT_DIRECTORY}/${directory_name}/${test_name}"
    )

    list(APPEND current_tests_list ${test_name})
  endforeach()

  # update the list of tests
  set_property(DIRECTORY PROPERTY tests_list ${current_tests_list})
endfunction()

# modules that this suite of tests depends on.
# tests_depends_on([<module>...])
function(tests_depends_on)
  get_property(current_tests_list DIRECTORY PROPERTY tests_list)

  foreach(test_file ${current_tests_list})
    target_link_libraries(${test_file}
      ${ARGV}
    )
  endforeach()
endfunction()