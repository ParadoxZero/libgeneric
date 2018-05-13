add_executable(btree_print btree_print.c)
target_link_libraries(btree_print generic)
add_executable(btree_search btree_search.c)
target_link_libraries(btree_search generic)

enable_testing()
add_test(btree_print btree_print)
add_test(btree_search btree_search)

