add_executable(swap_ints swap_ints.c)
target_link_libraries(swap_ints st_utils)
enable_testing()
add_test(swap_ints swap_ints)
