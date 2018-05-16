
add_executable(bst_search bst_search.c)
target_link_libraries(bst_search generic)

enable_testing()
add_test(bst_search bst_search)

