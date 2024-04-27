# process test source file
macro(process_current_file)
  # Extracts the directory name of the current list
  # into variable directory_name
  cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME directory_name)
  string(REPLACE " " "_" directory_name ${directory_name})

  # remove extension
  get_filename_component(file_name ${file} NAME_WLE)

  set(test_name "${directory_name}_${file_name}")

  add_executable(${test_name} ${file})

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
endmacro()

# Adds a test suite for a module.
# add_module_test_suite(<moduleName>
# [<source>...]
# )
function(add_test_suite_for_module module_name)
  if(ARGC LESS 2)
    message(FATAL_ERROR "A test suite must have at least one source file.")
  endif()

  # remove the first argument from the args list (module_name)
  list(REMOVE_AT ARGV 0)

  # go through test source files,
  # process and build a test for each source file
  foreach(file ${ARGV})
    # macro: process the curren test source file
    process_current_file()

    # link Unity and the tested module as a libraries to test
    target_link_libraries(${test_name}
      Unity
      ${module_name}
    )
  endforeach()
endfunction()

# Adds a test suite not linked to a module.
# add_test_suite([<source>...])
function(add_test_suite)
  if(ARGC LESS 1)
    message(FATAL_ERROR "A test suite must have at least one source file.")
  endif()

  # go through test source files,
  # process and build a test for each source file
  foreach(file ${ARGV})
    # macro: process the curren test source file
    process_current_file()

    # link the unity framework as a library
    target_link_libraries(${test_name}
      Unity
    )
  endforeach()
endfunction()
