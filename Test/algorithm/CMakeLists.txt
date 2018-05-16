add_executable(mergesort_test mergesort_test.c)
target_link_libraries(mergesort_test generic)

enable_testing()
add_test(mergesort_test mergesort_test)
