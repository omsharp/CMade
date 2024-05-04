# #####################
# ### /src/modules ####
# #####################

# [INFO] using globing to add subdirectories
# will not inform cmake of the changes in the source tree,
# which means you'll have to touch a CMake file every time you add a module,
# for the build system to pick it up.
# file(GLOB V_GLOB LIST_DIRECTORIES true "*")
# foreach(item ${V_GLOB})
# if(IS_DIRECTORY ${item})
# add_subdirectory(${item})
# endif()
# endforeach()

# [INFO] for now I'm settling with adding each module subdirectory manually
# so that the build system will pick the change automatically.
# maybe I'll add a script that will touch cmake file after adding a module directory!
# add_subdirectory(Sorting)

# todo)) this could be simplified more, something like
# add_modules(
# Guards
# Lists
# )

add_module(Guards)
add_module(Lists)
