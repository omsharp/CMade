set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(SDL_LIBC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include/sdl
)

add_subdirectory(sdl)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static)
