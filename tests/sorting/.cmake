# ####################
# ## tests/sorting ###
# ####################

test_suite_sources(
  BubbleSort_test_1.c
  BubbleSort_test_2.c
)

test_suite_depends_on(
  Sorting
  Stats
)