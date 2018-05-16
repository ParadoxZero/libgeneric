add_executable(test_mergesort test_mergesort.c)
target_link_libraries(test_mergesort generic)

enable_testing()
add_test(test_mergesort ${TEST_ROOT}/test_mergesort)
