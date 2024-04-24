###############
#### /root ####
###############
cmake_minimum_required(VERSION 3.25.0)

# C standard
set(CMAKE_C_STANDARD 17)

# project name (main executable file name)
project("C_Example")

# determine OS bitness
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
else()
    set(OSBitness 32)
endif()

# build output directory based on OS and build type.
# (example: bin/Linux_64/Debug)
set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}_${OSBitness}/${CMAKE_BUILD_TYPE}")

# path of the executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

# path of the static libraries. (will be embedded in executable)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")

# path of the dynamic libraries. (to be shipped with executable)
# will be the same as the executables path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")

# path of tests binaries
set(CMAKE_TESTS_OUTPUT_DIRECTORY "${FullOutputDir}/tests")

# set project-wide include (headers) directory
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# add lists in /src
add_subdirectory(src)

# compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    )

# CTest sets BUILD_TESTING option to ON by default.
# Test-related configuration goes here.
include(CTest)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()