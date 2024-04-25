# ####################
# ## tests/sorting ###
# ####################

# add yout test source files here
set(test_sources

    # each time you add a new test file to this suite, you must add it to this list for cmake to process it.
    quicksort.c
    test_2.c
)

# this function will process the test source files and produce a test for each one.
add_test_suite(Sorting test_sources)