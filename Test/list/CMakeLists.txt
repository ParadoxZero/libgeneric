
add_executable(list_add list_add.c)
target_link_libraries(list_add generic)

add_executable(list_add_at list_add_at.c)
target_link_libraries(list_add_at generic)

add_executable(list_remove list_remove.c)
target_link_libraries(list_remove generic)

add_executable(list_iter list_iter.c)
target_link_libraries(list_iter generic)

add_executable(list_get list_get.c)
target_link_libraries(list_get generic)

enable_testing()

add_test(list_add list_add)
add_test(list_add_at list_add_at)
add_test(list_iter list_iter)
add_test(list_remove list_remove)
add_test(list_get list_get)
