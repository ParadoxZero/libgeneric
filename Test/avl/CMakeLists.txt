
add_executable(avl_test avl_test.c)
target_link_libraries(avl_test generic)
target_link_libraries(avl_test m)

enable_testing()
add_test(avl_test avl_test)

