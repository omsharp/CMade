# holds a list of all tests in a suite (directory)
set_property(DIRECTORY PROPERTY tests_list)

function(add_test_suite suite_name)
  include("${CMAKE_SOURCE_DIR}/tests/${suite_name}/.cmake")
endfunction()

# source files of tests in this suite.
# tests_sources([<source>...])
function(test_suite_sources sources_list)
  # get the current list of tests
  get_property(current_tests_list DIRECTORY PROPERTY tests_list)

  # Extracts the directory name of the current list
  # into variable directory_name and clean it.
  cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME directory_name)
  string(REPLACE " " "_" directory_name ${directory_name})

  # go through test source files,
  # process and build a test for each source file
  foreach(source_file ${ARGV})
    # remove extension from source file name
    get_filename_component(test_name ${source_file} NAME_WLE)

    set(test_name "${directory_name}.${test_name}")

    add_executable(${test_name}
      ${PROJECT_SOURCE_DIR}/tests/${directory_name}/${source_file}
      ${PROJECT_SOURCE_DIR}/_external/unity/unity.c
    )

    # the include directory of the Unity framework
    target_include_directories(${test_name}
      PUBLIC
      ${PROJECT_SOURCE_DIR}/_external/unity
    )

    # set the binary directory for the test
    set_target_properties(${test_name}
      PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY
      "${CMAKE_TESTS_OUTPUT_DIRECTORY}"
    )

    add_test(${test_name}
      "${CMAKE_TESTS_OUTPUT_DIRECTORY}/${test_name}"
    )

    list(APPEND current_tests_list ${test_name})
  endforeach()

  # update the list of tests
  set_property(DIRECTORY PROPERTY tests_list ${current_tests_list})
endfunction()

# modules that this suite of tests depends on.
# tests_depends_on([<module>...])
function(test_suite_depends_on)
  get_property(current_tests_list DIRECTORY PROPERTY tests_list)

  foreach(test_name ${current_tests_list})
    target_link_libraries(${test_name}
      ${ARGV}
    )
  endforeach()
endfunction()
