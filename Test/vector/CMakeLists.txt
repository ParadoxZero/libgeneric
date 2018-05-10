add_executable(vector_stack vector_stack.c)
target_link_libraries(vector_stack generic)
add_executable(vector_insert vector_insert.c)
target_link_libraries(vector_insert generic)

enable_testing()
add_test(vector_stack vector_stack)
add_test(vector_insert vector_insert)
