

add_executable(vector_insert vector_insert.c)
target_link_libraries(vector_insert generic)

add_executable(queue_order queue_order.c)
target_link_libraries(queue_order generic)

enable_testing()

add_test(vector_insert vector_insert)
add_test(queue_order queue_order)
