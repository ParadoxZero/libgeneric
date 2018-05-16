add_executable(mergesort_test mergesort_test.c)
target_link_libraries(mergesort_test generic)
add_executable(mergesort_generic mergesort_generic.c)
target_link_libraries(mergesort_generic generic)

enable_testing()
add_test(mergesort_test ${TEST_ROOT}/mergesort_test)
add_test(mergesort_generic ${TEST_ROOT}/mergesort_generic)
