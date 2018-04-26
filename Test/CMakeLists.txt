
add_executable(list_add list/list_add.c)
target_link_libraries(list_add st_list)

add_executable(list_remove list/list_remove.c)
target_link_libraries(list_remove st_list)

add_executable(list_iter list/list_iter.c)
target_link_libraries(list_iter st_list)
enable_testing()

add_test(list_add list_add)
add_test(list_iter list_iter)
add_test(list_remove list_remove)
