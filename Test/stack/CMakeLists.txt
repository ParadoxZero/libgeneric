add_executable(stack_ints stack_ints.c)
target_link_libraries(stack_ints st_nstack)

enable_testing()
add_test(stack_ints stack_ints)
